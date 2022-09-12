#ifndef AUTOMATED_FINADVISOR_MOMENTUM_CLASSIFIER_H
#define AUTOMATED_FINADVISOR_MOMENTUM_CLASSIFIER_H

#include <fstream>
#include <string>
#include <vector>
#include "core/momentum-prediction/momentum_model.h"

using std::istream;
using std::string;
using std::vector;

namespace finadvisor {

class MomentumClassifier {
    public:
        /**
         * Extracts values from input txt file into member variables of MomentumClassifer class.
         *
         * @param input istream representing txt file for extraction purposes
         * @param model instance of MomentumClassifier class
         * @return istream representing classifier
         */
        friend istream& operator>>(istream &input, MomentumClassifier &classifier);

        /**
         * Invokes extraction operator.
         *
         * @param file_path path of txt file for extraction purposes
         * @return updated instance of MomentumClassifier class with member variable values extracted from txt file
         */
        MomentumClassifier ValidateFile(const std::string &file_path);

        /**
         * Computes the proportion of momentum testing points predicted correctly by the model.
         *
         * @param model instance of MomentumModel class that stores momentum points for KNN algorithm
         * @param k Number of nearest neighbors; stands for k in KNN algorithm
         * @return fraction of momentum testing points predicted correctly over total momentum testing points
         */
        double CalculateValidationAccuracy(MomentumModel model, size_t k);

        MomentumPoint GetMomentumTestingPoint(size_t vector_index);

    private:
        vector<MomentumPoint> momentum_testing_points_;

};

}


#endif //AUTOMATED_FINADVISOR_MOMENTUM_CLASSIFIER_H
