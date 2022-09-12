#ifndef AUTOMATED_FINADVISOR_MOMENTUM_MODEL_H
#define AUTOMATED_FINADVISOR_MOMENTUM_MODEL_H
#include <fstream>
#include "core/momentum-prediction/momentum_training_data_factory.h"

using std::istream;

namespace finadvisor {

/**
 * Stores momentum as a representation of point in three dimensional space for use in K nearest neighbor algorithm
 */
struct MomentumPoint {
    /**
     * Momentum trend consisting of momentum category and momentum direction.
     */
    string momentum_trend;
    /**
     * X coordinate of momentum point representing proportion of positive price differences.
     */
    double price_increase_probability;
    /**
     * Y coordinate of momentum point representing proportion of negative price differences.
     */
    double price_decrease_probability;
    /**
     * Z coordinate of momentum point representing proportion of price differences of 0 magnitude.
     */
    double static_price_probability;
    /**
     * Distance between current momentum point and target momentum point (i.e. member of testing set).
     */
    double distance;
};

class MomentumModel {
    public:
        /**
         * Extracts values from input txt file into member variables of MomentumModel class.
         *
         * @param input istream representing txt file for extraction purposes
         * @param model instance of MomentumModel class
         * @return istream representing model
         */
        friend istream &operator>>(istream &input, MomentumModel& model);
        /**
         * Sets values of MomentumPoint struct.
         */
        void GenerateMomentumPoint();
        /**
         * Invokes extraction operator.
         *
         * @param file_path path of txt file for extraction purposes
         * @return updated instance of MomentumModel class with member variable values extracted from txt file
         */
        MomentumModel ValidateFile(const string& file_path);
        /**
         * Gets probability for price increase.
         *
         * @param index Vector index
         * @return probability for price increase
         */
        double GetPriceIncreaseProbability(size_t index);
        /**
         * Gets probability for price decrease.
         *
         * @param index Vector index
         * @return probability for price decrease
         */
        double GetPriceDecreaseProbability(size_t index);
        /**
         * Gets probability for static prices
         *
         * @param index Vector index
         * @return probability for static price
         */
        double GetStaticPriceProbability(size_t index);
        /**
         * Gets momentum trend.
         *
         * @param index Vector index
         * @return momentum trend
         */
        string GetMomentumTrend(size_t index);
        /**
         * Calculates the average of the distances of the nearest k momentum points.
         *
         * @param k Number of nearest neighbors; stands for k in KNN algorithm
         * @param x_query_coordinate Price increase probability of query point
         * @param y_query_coordinate Price decrease probability of query point
         * @param z_query_coordinate Static price probability of query point
         * @return Mean of distance of nearest k momentum points
         */
        double ComputeKNearestLabelsAverage(size_t k, double x_query_coordinate, double y_query_coordinate,
                                                       double z_query_coordinate);
        /**
         * Computes the distance between current momentum point and query momentum point.
         *
         * @param current_point current instance of MomentumPoint struct.
         * @param x_query_coordinate price increase probability of query point
         * @param y_query_coordinate price decrease probability of query point
         * @param z_query_coordinate static price probability of query point
         * @return distance between current momentum point and query momentum point
         */
        double CalculateEuclideanDistance(const MomentumPoint& current_point, double x_query_coordinate,
                                          double y_query_coordinate, double z_query_coordinate) const;
        /**
         * Determines if the distance of the second MomentumPoint exceeds distance of first MomentumPoint.
         *
         * @param first_point first MomentumPoint struct for comparison
         * @param second_point second MomentumPoint struct for comparison
         * @return true if distance of second MomentumPoint is greater than distance of first MomentumPoint
         */
        friend bool CompareDistance(const MomentumPoint& first_point, const MomentumPoint& second_point);
        void SetFileLine(const string& line);
        size_t GetMomentumPointCount();
        double GetDistance(size_t index);
    private:
        vector<MomentumPoint> momentum_training_points_;
        string file_line_;
        MomentumPoint current_momentum_point_;
        constexpr const static double kThreeQuarters_ = static_cast<double>(3) / 4;
        constexpr const static double kOneQuarters_ = static_cast<double>(1) / 4;
};

const static string kAscendingIntegers_ = "0123456789";

}

#endif //AUTOMATED_FINADVISOR_MOMENTUM_MODEL_H
