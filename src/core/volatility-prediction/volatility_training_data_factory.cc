#include "core/volatility-prediction/volatility_training_data_factory.h"
#include "core/momentum-prediction/momentum_model.h"
#include "core/volatility-prediction/volatility_calculator.h"
#include "core/data_processor.h"
#include "core/date.h"
#include <iostream>
#include <codecvt>
#include <numeric>
#include <sstream>

using std::ifstream;
using std::invalid_argument;
using std::accumulate;
using std::inner_product;
using std::stringstream;

namespace finadvisor {

ostream& operator<<(ostream& output, VolatilityTrainingDataFactory& factory) {
    for (const auto& pair : factory.volatility_by_standardized_quartile_price_) {
        output << kVolatilityMeasures_[static_cast<int>(pair.second.measure)] << " " <<
               kVolatilityCategories_[static_cast<int>(pair.second.category)];
        output << kNewLineCharacter_;
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        for (double standardized_quartile_price : pair.first) {
            // Code below derived from:
            // https://stackoverflow.com/questions/18534494/convert-from-utf-8-to-unicode-c
            if (standardized_quartile_price >= 0) {
                // For sake of simplicity with the k means clustering algorithm, a Z-score of 0 is considered positive.
                // Making such a simplification has a negligible effect on accuracy due to shifts in central tendency.
                output << converter.from_bytes(kVolatilityTrainingDataCharacters_[0]).c_str();
            } else {
                output << converter.from_bytes(kVolatilityTrainingDataCharacters_[1]).c_str();
            }
            output << kParseCharacter_;
        }
        output << kNewLineCharacter_;
    }
    return output;
}

Volatility VolatilityTrainingDataFactory::GetVolatility(size_t map_index) {
    std::pair<const vector<double>, Volatility> &nth_element = *std::next(
            volatility_by_standardized_quartile_price_.begin(), map_index);
    return nth_element.second;
}

std::vector<double> VolatilityTrainingDataFactory::GetStandardizedQuartilePrices(size_t map_index) {
    std::pair<const vector<double>, Volatility> &nth_element = *std::next(
            volatility_by_standardized_quartile_price_.begin(), map_index);
    return nth_element.first;
}

string VolatilityTrainingDataFactory::WriteToOutputFile(VolatilityTrainingDataFactory& factory) {
    stringstream model_stream;
    model_stream << factory;
    std::ofstream file(kVolatilityOutputFilePath_);
    file << model_stream.str();
    file.close();
    return kVolatilityOutputFilePath_;
}

DailyPrice VolatilityTrainingDataFactory::GetDailyPrice(size_t vector_index) {
    return daily_prices_[vector_index];
}

void VolatilityTrainingDataFactory::UpdateDailyPrices(const string& line) {
    DailyPrice price;
    DataProcessor processor;
    daily_prices_.reserve(daily_prices_.size() + 1);
    price.opening_price = stod(processor.Split(line, kParseCharacter_)[MomentumTrainingDataFactory::GetOpeningPriceIndex()]);
    price.closing_price = stod(processor.Split(line, kParseCharacter_)[MomentumTrainingDataFactory::GetClosingPriceIndex()]);
    price.high_price = stod(processor.Split(line, kParseCharacter_)[VolatilityTrainingDataFactory::kHighPriceIndex_]);
    price.low_price = stod(processor.Split(line, kParseCharacter_)[VolatilityTrainingDataFactory::kLowPriceIndex_]);
    daily_prices_.emplace_back(price);
}

istream& operator>>(istream& input, VolatilityTrainingDataFactory& factory) {
    string line;
    size_t month = 0;
    VolatilityCalculator calculator;
    DataProcessor processor;
    while (getline(input, line)) {
        Date date(processor.Split(line, kParseCharacter_)[0]);
        if (month != date.GetMonth() && !factory.quartile_prices_.empty()) {
            factory.volatility_by_standardized_quartile_price_.insert({calculator.StandardizeQuartilePrices(
                    factory.quartile_prices_), calculator.IdentifyVolatility(factory.quartile_prices_)});
            factory.quartile_prices_.clear();
        }
        month = date.GetMonth();
        factory.quartile_prices_.reserve(factory.quartile_prices_.size() + 1);
        factory.UpdateDailyPrices(line);
        DailyPrice price = factory.daily_prices_[factory.daily_prices_.size() - 1];
        factory.quartile_prices_.emplace_back(calculator.CalculateQuartilePrice(
                price.opening_price, price.closing_price, price.high_price, price.low_price));
    }
    return input;
}

VolatilityTrainingDataFactory VolatilityTrainingDataFactory::ValidateFiles(const vector<string>& file_paths) const {
    VolatilityTrainingDataFactory factory;
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