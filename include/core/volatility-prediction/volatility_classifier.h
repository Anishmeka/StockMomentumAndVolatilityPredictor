#ifndef AUTOMATED_FINADVISOR_VOLATILITY_CLASSIFIER_H
#define AUTOMATED_FINADVISOR_VOLATILITY_CLASSIFIER_H

#include <fstream>
#include <string>
#include <vector>
#include "core/volatility-prediction/volatility_model.h"

using std::istream;
using std::string;
using std::vector;

namespace finadvisor {

class VolatilityClassifier {
    public:
        /**
         * Extracts values from input txt file into member variables of VolatilityClassifer class.
         *
         * @param input istream representing txt file for extraction purposes
         * @param model instance of VolatilityClassifier class
         * @return istream representing classifier
         */
        friend istream &operator>>(istream &input, VolatilityClassifier &classifier);

        /**
         * Invokes extraction operator.
         *
         * @param file_path path of txt file for extraction purposes
         * @return updated instance of VolatilityClassifier class with member variable values extracted from txt file
         */
        VolatilityClassifier ValidateFile(const std::string &file_path);

        /**
         * Computes the proportion of volatility testing points predicted correctly by the model.
         *
         * @param model instance of VolatilityModel class that stores volatility points for k-means clustering algorithm
         * @param cluster_size number of volatility points in each cluster
         * @return fraction of volatility testing points predicted correctly over total volatility testing points
         */
        double CalculateValidationAccuracy(VolatilityModel model, size_t cluster_size);

        VolatilityPoint GetVolatilityTestingPoint(size_t vector_index);
    private:
        vector<VolatilityPoint> volatility_testing_points_;
};

}

#endif //AUTOMATED_FINADVISOR_VOLATILITY_CLASSIFIER_H
