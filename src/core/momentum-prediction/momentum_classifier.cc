#include "core/momentum-prediction/momentum_classifier.h"
#include "core/data_processor.h"
#include <float.h>
#include <cmath>

using std::ifstream;
using std::invalid_argument;

namespace finadvisor {

MomentumPoint MomentumClassifier::GetMomentumTestingPoint(size_t vector_index) {
    return momentum_testing_points_[vector_index];
}

istream& operator>>(istream &input, MomentumClassifier &classifier) {
    DataProcessor processor;
    MomentumPoint point;
    std::string line;
    while (getline(input, line)) {
        if (!std::isalpha(line[0])) {
            vector<string> probabilities_ = processor.Split(line, " ");
            point.price_increase_probability = std::stod(probabilities_[0]);
            point.price_decrease_probability = std::stod(probabilities_[1]);
            point.static_price_probability = std::stod(probabilities_[2]);
            classifier.momentum_testing_points_.reserve(classifier.momentum_testing_points_.size() + 1);
            classifier.momentum_testing_points_.emplace_back(point);
        } else {
            point.momentum_trend = line;
        }
    }
    return input;
}

MomentumClassifier MomentumClassifier::ValidateFile(const string &file_path) {
    ifstream file;
    file.open(file_path);
    if (file.fail() || file.bad() || file.eof()) {
        file.close();
        throw invalid_argument("Cannot open file");
    } else {
        MomentumClassifier classifier;
        file >> classifier;
        file.close();
        return classifier;
    }
}

double MomentumClassifier::CalculateValidationAccuracy(MomentumModel model, size_t k) {
    double validation_accuracy = 0;
    for (const MomentumPoint& point : momentum_testing_points_) {
        double k_nearest_labels_average = model.ComputeKNearestLabelsAverage(k, point.price_increase_probability,
                                                            point.price_decrease_probability, point.static_price_probability);
        double min_distance_difference = DBL_MAX;
        string nearest_label_trend;
        for (size_t i = 0; i < model.GetMomentumPointCount(); i++) {
            double distance_difference = abs(model.GetDistance(i) - k_nearest_labels_average);
            if (distance_difference < min_distance_difference) {
                min_distance_difference = distance_difference;
                nearest_label_trend = model.GetMomentumTrend(i);
            }
        }

        if (nearest_label_trend == point.momentum_trend) {
            validation_accuracy++;
        }
    }
    return validation_accuracy / momentum_testing_points_.size();
}

}
