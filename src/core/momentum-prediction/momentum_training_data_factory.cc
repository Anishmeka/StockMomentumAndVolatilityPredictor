#include "core/momentum-prediction/momentum_training_data_factory.h"
#include <fstream>
#include <vector>
#include "core/data_processor.h"
#include "core/date.h"
#include <sstream>
#include "core/momentum-prediction/momentum_calculator.h"
#include <codecvt>
#include <iostream>

using std::istreambuf_iterator;
using std::count;
using std::ifstream;
using std::invalid_argument;
using std::stod;
using std::stringstream;

namespace finadvisor {

Momentum MomentumTrainingDataFactory::GetMomentum(size_t map_index) {
    std::pair<const vector<double>, Momentum> &nth_element = *std::next(momentum_by_price_difference_.begin(), map_index);
    return nth_element.second;
}

std::vector<double> MomentumTrainingDataFactory::GetPriceDifferences(size_t map_index) {
    std::pair<const vector<double>, Momentum> &nth_element = *std::next(momentum_by_price_difference_.begin(), map_index);
    return nth_element.first;
}

ostream& operator<<(ostream& output, MomentumTrainingDataFactory& factory) {
    for (const auto& pair : factory.momentum_by_price_difference_) {\
        output << kMomentumCategories_[static_cast<int>(pair.second.category)] << " " <<
            kMomentumDirections_[static_cast<int>(pair.second.direction)];
        output << kNewLineCharacter_;
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        for (double price_difference : pair.first) {
            // Code below derived from:
            // https://stackoverflow.com/questions/18534494/convert-from-utf-8-to-unicode-c
            if (price_difference > 0) {
                // Encode - Convert character of type Utf8 to unicode
                output << converter.from_bytes(kUpwardTrendCharacter_).c_str();
            } else if (price_difference < 0) {
                output << converter.from_bytes(kDownwardTrendCharacter_).c_str();
            } else {
                output << converter.from_bytes(kStaticTrendCharacter_).c_str();
            }
            output << kParseCharacter_;
        }
        output << kNewLineCharacter_;
    }
    return output;
}

size_t MomentumTrainingDataFactory::GetClosingPriceIndex() {
    return kClosingPriceIndex_;
}

size_t MomentumTrainingDataFactory::GetOpeningPriceIndex() {
    return kOpeningPriceIndex_;
}

string MomentumTrainingDataFactory::WriteToOutputFile(MomentumTrainingDataFactory& factory) {
    stringstream model_stream;
    model_stream << factory;
    std::ofstream file(kMomentumOutputFilePath_);
    file << model_stream.str();
    file.close();
    return kMomentumOutputFilePath_;
}

istream& operator>>(istream& input, MomentumTrainingDataFactory& factory) {
    string line;
    size_t month = 0;
    while (getline(input, line)) {
        DataProcessor processor;
        Date date(processor.Split(line, kParseCharacter_)[0]);
        if (month != date.GetMonth() && !factory.price_differences_.empty()) {
            MomentumCalculator calculator;
            factory.momentum_by_price_difference_.insert({factory.price_differences_,
                                                          calculator.IdentifyMomentum(factory.price_differences_)});
            factory.price_differences_.clear();
        }
        month = date.GetMonth();
        factory.price_differences_.reserve(factory.price_differences_.size() + MomentumTrainingDataFactory::kOpeningPriceIndex_);
        factory.price_differences_.emplace_back(stod(processor.Split(line, kParseCharacter_)[
                MomentumTrainingDataFactory::kOpeningPriceIndex_]) -
                                                stod(processor.Split(line, kParseCharacter_)[
                                                        MomentumTrainingDataFactory::kClosingPriceIndex_]));
    }
    return input;
}

MomentumTrainingDataFactory MomentumTrainingDataFactory::ValidateFiles(const vector<string>& file_paths) const {
    MomentumTrainingDataFactory factory;
    ifstream file;
    for (const string& file_path : file_paths) {
        file.open(file_path);
        if (file.fail() || file.bad() || file.eof()) {
            file.close();
            throw invalid_argument("Cannot open file");
        } else {
            file >> factory;
            file.close();
        }
    }
    return factory;
}

}