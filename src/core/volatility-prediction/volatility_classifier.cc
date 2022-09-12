#include "core/volatility-prediction/volatility_classifier.h"
#include "core/data_processor.h"
#include <float.h>
#include <cmath>
#include <fstream>

using std::ifstream;
using std::invalid_argument;

namespace finadvisor {

VolatilityPoint VolatilityClassifier::GetVolatilityTestingPoint(size_t vector_index) {
    return volatility_testing_points_[vector_index];
}

istream &operator>>(istream &input, VolatilityClassifier &classifier) {
    DataProcessor processor;
    VolatilityPoint point;
    std::string line;
    while (getline(input, line)) {
        if (!std::isalpha(line[0])) {
            vector<string> probabilities_ = processor.Split(line, " ");
            point.positive_z_score_probability = std::stod(probabilities_[0]);
            point.negative_z_score_probability = std::stod(probabilities_[1]);
            classifier.volatility_testing_points_.reserve(classifier.volatility_testing_points_.size() + 1);
            classifier.volatility_testing_points_.emplace_back(point);
        } else {
            point.volatility_type = line;
        }
    }
    return input;
}

VolatilityClassifier VolatilityClassifier::ValidateFile(const std::string &file_path) {
    ifstream file;
    file.open(file_path);
    if (file.fail() || file.bad() || file.eof()) {
        file.close();
        throw invalid_argument("Cannot open file");
    } else {
        VolatilityClassifier classifier;
        file >> classifier;
        file.close();
        return classifier;
    }
}

double VolatilityClassifier::CalculateValidationAccuracy(VolatilityModel model, size_t cluster_size) {
    double validation_accuracy = 0;
    for (const VolatilityPoint &point : volatility_testing_points_) {
        model.AssignClusterPoints(cluster_size);
        model.UpdateCentroidData();
        double min_probability_difference = DBL_MAX;
        string cluster_trend;
        for (size_t i = 0; i < model.GetClusterCount(); i++) {
            double probability_difference = abs(model.GetCluster(i).positive_z_score_probability -
                                                model.GetCluster(i).positive_z_score_probability) +
                                            abs(model.GetCluster(i).negative_z_score_probability -
                                                model.GetCluster(i).negative_z_score_probability);
            if (probability_difference < min_probability_difference) {
                min_probability_difference = probability_difference;
                cluster_trend = model.GetCluster(i).volatility_type;
            }
            if (cluster_trend == point.volatility_type) {
                validation_accuracy++;
            }
        }
    }
    return validation_accuracy / volatility_testing_points_.size();
}

}