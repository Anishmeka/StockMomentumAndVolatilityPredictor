#include "core/momentum-prediction/momentum_model.h"
#include <codecvt>
#include "core/data_processor.h"
#include <iostream>
#include <cmath>

using std::ifstream;
using std::invalid_argument;

namespace finadvisor {

void MomentumModel::SetFileLine(const string& line) {
    file_line_ = line;
}

double MomentumModel::GetPriceIncreaseProbability(size_t index) {
    if (index >= momentum_training_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return momentum_training_points_[index].price_increase_probability;
}

double MomentumModel::GetPriceDecreaseProbability(size_t index) {
    if (index >= momentum_training_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return momentum_training_points_[index].price_decrease_probability;
}

double MomentumModel::GetStaticPriceProbability(size_t index) {
    if (index >= momentum_training_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return momentum_training_points_[index].static_price_probability;
}

double MomentumModel::GetDistance(size_t index) {
    if (index >= momentum_training_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return momentum_training_points_[index].distance;
}

string MomentumModel::GetMomentumTrend(size_t index) {
    if (index >= momentum_training_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return momentum_training_points_[index].momentum_trend;
}

void MomentumModel::GenerateMomentumPoint() {
    for (char training_data_character : file_line_) {
        if (training_data_character == kMomentumTrainingDataCharacters_[0]) {
            current_momentum_point_.price_increase_probability++;
        } else if (training_data_character == kMomentumTrainingDataCharacters_[1]) {
            current_momentum_point_.price_decrease_probability++;
        } else {
            current_momentum_point_.static_price_probability++;
        }
    }
    current_momentum_point_.price_increase_probability /= file_line_.length();
    current_momentum_point_.static_price_probability /= file_line_.length();
    current_momentum_point_.price_decrease_probability /= file_line_.length();
    momentum_training_points_.emplace_back(current_momentum_point_);
}

istream& operator>>(istream& input, MomentumModel& model) {
    std::string line;
    while (getline(input, line)) {
        model.file_line_ = line;
        bool is_training_data_line = false;

        for (char number : kAscendingIntegers_) {
            if (model.file_line_.find(number) != string::npos) {
                DataProcessor processor;
                vector<string> file_characters = processor.Split(line, kParseCharacter_);
                vector<string> unicode_characters = processor.Split(kMomentumTrainingDataUnicode_, kParseCharacter_);
                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                model.file_line_.clear();
                model.file_line_.reserve(file_characters.size());
                for (auto& unicode_character : file_characters) {
                    if (unicode_character == unicode_characters[0]) {
                        model.file_line_ += kMomentumTrainingDataCharacters_[0];
                    } else if (unicode_character == unicode_characters[1]) {
                        model.file_line_ += kMomentumTrainingDataCharacters_[1];
                    } else {
                        model.file_line_ += kMomentumTrainingDataCharacters_[2];
                    }
                }
                is_training_data_line = true;
                break;
            }
        }

        if (!is_training_data_line) {
            model.current_momentum_point_.momentum_trend = model.file_line_;
        }
        model.GenerateMomentumPoint();
    }
    return input;
}

MomentumModel MomentumModel::ValidateFile(const string& file_path) {
    ifstream file;
    file.open(file_path);
    if (file.fail() || file.bad() || file.eof()) {
        file.close();
        throw invalid_argument("Cannot open file");
    } else {
        MomentumModel model;
        file >> model;
        file.close();
        return model;
    }
}

size_t MomentumModel::GetMomentumPointCount() {
    return momentum_training_points_.size();
}

double MomentumModel::CalculateEuclideanDistance(const MomentumPoint &current_point, double x_query_coordinate,
                                                 double y_query_coordinate, double z_query_coordinate) const {
    double sum_squared_distance = 0;
    sum_squared_distance = pow(x_query_coordinate - current_point.price_increase_probability, 2) +
            pow(y_query_coordinate - current_point.price_decrease_probability, 2) +
            pow(z_query_coordinate - current_point.static_price_probability, 2);
    return sqrt(sum_squared_distance);
}

bool CompareDistance(const MomentumPoint& first_point, const MomentumPoint& second_point) {
    return first_point.distance < second_point.distance;
}

double MomentumModel::ComputeKNearestLabelsAverage(size_t k, double x_query_coordinate, double y_query_coordinate,
                                                   double z_query_coordinate) {
    for (MomentumPoint& point : momentum_training_points_) {
        point.distance = CalculateEuclideanDistance(point, x_query_coordinate, y_query_coordinate, z_query_coordinate);
    }
    // Sort the vector of momentum points in ascending order by distances
    std::sort(momentum_training_points_.begin(), momentum_training_points_.end(), CompareDistance);
    double k_nearest_labels_average = 0;
    // Label refers to the squared deviations from the semi-interquartile range
    for (size_t i = 0; i < k; i++) {
        k_nearest_labels_average += pow(momentum_training_points_[i].distance -
                                        (momentum_training_points_[floor(kThreeQuarters_ * momentum_training_points_.size())].distance) -
                                        (momentum_training_points_[floor(kOneQuarters_ * momentum_training_points_.size())].distance), 2);
    }
    return k_nearest_labels_average / k;
}

}