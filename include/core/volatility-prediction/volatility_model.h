#ifndef AUTOMATED_FINADVISOR_VOLATILITY_MODEL_H
#define AUTOMATED_FINADVISOR_VOLATILITY_MODEL_H

#include <cstddef>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using std::string;
using std::vector;
using std::istream;

namespace finadvisor {

/**
 * Stores volatility as a representation of point in two dimensional space for use in K means clustering algorithm
 */
struct VolatilityPoint {
    /**
     * Volatility type consisting of measure and category.
     */
    string volatility_type;
    /**
     * X coordinate of volatility point representing proportion of positive z-scores.
     */
    double positive_z_score_probability;
    /**
     * Y coordinate of volatility point representing proportion of negative z-scores.
     */
    double negative_z_score_probability;
    /**
     * Grouping for use in K means clustering algorithm
     */
    size_t cluster;
    /**
     * Minimum distance between current volatility point and target volatility point.
     */
    double minimum_distance;

    double ComputeDistance(const VolatilityPoint& point) {
        return pow(point.positive_z_score_probability - positive_z_score_probability, 2) +
            pow(point.negative_z_score_probability - negative_z_score_probability, 2);
    }
};

struct Centroid {
    size_t point_count;
    double x_coordinate_sum;
    double y_coordinate_sum;
};

class VolatilityModel {
    public:
        /**
         * Invokes extraction operator.
         *
         * @param file_path path of txt file for extraction purposes
         * @return updated instance of VolatilityModel class with member variable values extracted from txt file
         */
        VolatilityModel ValidateFile(const string& file_path);
        /**
         * Sets value of VolatilityPoint struct
         */
        void GenerateVolatilityPoint();
        /**
         * Extracts values from input txt file into member variables of VolatilityModel class.
         *
         * @param input istream representing txt file for extraction purposes
         * @param model instance of VolatilityModel class
         * @return istream representing VolatilityModel
         */
        friend istream &operator>>(istream &input, VolatilityModel& model);
        /**
         * Initializes value of file line member variable.
         *
         * @param file_line Line in txt file
         */
        void SetFileLine(const string& file_line);
        /**
         * Initializes cluster by assigning volatility points to each one.
         *
         * @param cluster_count number of volatility points in each cluster
         */
        void AssignClusterPoints(size_t cluster_count);
        /**
         * Updates centroid point counts, x coordinate sums, and y coordinate sums.
         */
        void UpdateCentroidData();

        // Getters
        string GetVolatilityType(size_t vector_index);
        double GetPositiveZScoreProbability(size_t vector_index);
        double GetNegativeZScoreProbability(size_t vector_index);
        size_t GetClusterCount();
        VolatilityPoint GetCluster(size_t vector_index);
        Centroid GetCentroid(size_t vector_index);
        double GetMinimumDistance(size_t vector_index);
        size_t GetClusterValue(size_t vector_index);
    private:
        vector<VolatilityPoint> volatility_points_;
        string file_line_;
        VolatilityPoint current_volatility_point_;
        vector<Centroid> centroids_;
        vector<VolatilityPoint> clusters_;
};

const static string kVolatilityTrainingDataUnicode_ = "0x0000002B,0x0000002D";

}

#endif //AUTOMATED_FINADVISOR_VOLATILITY_MODEL_H
