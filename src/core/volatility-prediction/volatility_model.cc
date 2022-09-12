#include "core/volatility-prediction/volatility_model.h"
#include "core/data_processor.h"
#include "core/momentum-prediction/momentum_training_data_factory.h"
#include "core/momentum-prediction/momentum_model.h"
#include "core/volatility-prediction/volatility_training_data_factory.h"
#include <codecvt>

using std::ifstream;
using std::invalid_argument;

namespace finadvisor {

void VolatilityModel::SetFileLine(const string& file_line) {
    file_line_ = file_line;
}

string VolatilityModel::GetVolatilityType(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return volatility_points_[vector_index].volatility_type;
}

double VolatilityModel::GetPositiveZScoreProbability(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return volatility_points_[vector_index].positive_z_score_probability;
}

double VolatilityModel::GetNegativeZScoreProbability(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return volatility_points_[vector_index].negative_z_score_probability;
}

double VolatilityModel::GetMinimumDistance(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return volatility_points_[vector_index].minimum_distance;
}

size_t VolatilityModel::GetClusterValue(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return volatility_points_[vector_index].cluster;
}

void VolatilityModel::GenerateVolatilityPoint() {
    for (char training_data_character : file_line_) {
        if (training_data_character == kVolatilityTrainingDataCharacters_[0]) {
            current_volatility_point_.positive_z_score_probability++;
        } else {
            current_volatility_point_.negative_z_score_probability++;
        }
    }
    current_volatility_point_.positive_z_score_probability /= file_line_.length();
    current_volatility_point_.negative_z_score_probability /= file_line_.length();
    volatility_points_.emplace_back(current_volatility_point_);
}

istream &operator>>(istream &input, VolatilityModel& model) {
    std::string line;
    DataProcessor processor;
    while (getline(input, line)) {
        model.file_line_ = line;
        bool is_training_data_line = false;
        for (char number : kAscendingIntegers_) {
            if (model.file_line_.find(number) != string::npos) {
                vector<string> file_characters = processor.Split(line, kParseCharacter_);
                vector<string> unicode_characters = processor.Split(kVolatilityTrainingDataUnicode_, kParseCharacter_);
                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                model.file_line_.clear();
                model.file_line_.reserve(file_characters.size());
                for (auto& unicode_character : file_characters) {
                    if (unicode_character == unicode_characters[0]) {
                        model.file_line_ += kVolatilityTrainingDataUnicode_[0];
                    } else {
                        model.file_line_ += kVolatilityTrainingDataUnicode_[1];
                    }
                }
                is_training_data_line = true;
                break;
            }
        }

        if (!is_training_data_line) {
            model.current_volatility_point_.volatility_type = model.file_line_;
        }
        model.GenerateVolatilityPoint();
    }
    return input;
}

size_t VolatilityModel::GetClusterCount() {
    return clusters_.size();
}

VolatilityPoint VolatilityModel::GetCluster(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return clusters_[vector_index];
}

Centroid VolatilityModel::GetCentroid(size_t vector_index) {
    if (vector_index >= volatility_points_.size()) {
        throw invalid_argument("Index out of bounds");
    }
    return centroids_[vector_index];
}

VolatilityModel VolatilityModel::ValidateFile(const string& file_path) {
    ifstream file;
    file.open(file_path);
    if (file.fail() || file.bad() || file.eof()) {
        file.close();
        throw invalid_argument("Cannot open file");
    } else {
        VolatilityModel model;
        file >> model;
        file.close();
        return model;
    }
}

void VolatilityModel::UpdateCentroidData() {
    centroids_.reserve(volatility_points_.size());
    centroids_.resize(volatility_points_.size());
    for (const VolatilityPoint& point : volatility_points_) {
        size_t cluster_id = point.cluster;
        centroids_[cluster_id].point_count += 1;
        centroids_[cluster_id].x_coordinate_sum += point.positive_z_score_probability;
        centroids_[cluster_id].y_coordinate_sum += point.negative_z_score_probability;
    }

    for (size_t cluster_id = 0; cluster_id < clusters_.size(); cluster_id++) {
        clusters_[cluster_id].volatility_type = volatility_points_[cluster_id].volatility_type;
        clusters_[cluster_id].positive_z_score_probability = centroids_[cluster_id].x_coordinate_sum /
                centroids_[cluster_id].point_count;
        clusters_[cluster_id].negative_z_score_probability = centroids_[cluster_id].y_coordinate_sum /
                centroids_[cluster_id].point_count;
    }
}

void VolatilityModel::AssignClusterPoints(size_t cluster_count) {
    // Initialize clusters
    clusters_.reserve(cluster_count);
    for (size_t i = 0; i < cluster_count; i++) {
        clusters_.emplace_back(volatility_points_[rand() % volatility_points_.size()]);
    }

    // Set ID to index of cluster and minimum distance to closest point
    for (size_t cluster_id = 0; cluster_id < clusters_.size(); cluster_id++) {
        for (VolatilityPoint& point: volatility_points_) {
            double distance = clusters_[cluster_id].ComputeDistance(point);
            if (distance < point.minimum_distance) {
                point.minimum_distance = distance;
                point.cluster = cluster_id;
            }
        }
    }
}

}
