#ifndef AUTOMATED_FINADVISOR_MOMENTUM_CALCULATOR_H
#define AUTOMATED_FINADVISOR_MOMENTUM_CALCULATOR_H
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace finadvisor {

/**
 * Enum representing types of momentum.
 */
enum class MomentumCategory {
    Bullish = 0,
    Bearish = 1,
    Indecision = 2
};

/**
 * Enum representing direction each momentum category may take
 */
enum class MomentumDirection {
    Reversal = 0,
    Continuation = 1,
    None = 2
};

/**
 * Constructs momentum based on category and direction.
 */
struct Momentum {
    MomentumCategory category;
    MomentumDirection direction;
};

class MomentumCalculator {
    public:
        /**
         * Calculates slope of line of best fit with day count on x axis and price difference on y axis.
         *
         * @param price_differences Vector containing differences between closing and opening price.
         * @return slope of line of best fit
         */
        double ComputeLinearRegressionSlope(const vector<double>& price_differences);
        /**
         * Computes relative strength index based on current average gains and losses.
         *
         * @param price_differences Vector containing differences between closing and opening price.
         * @return relative strength index
         */
        double CalculateRelativeStrengthIndex(const vector<double>& price_differences);
        /**
         * Categroizes momentum based on type and direction.
         *
         * @param price_differences Vector containing differences between closing and opening price.
         * @return momentum struct indicating category and direction.
         */
        Momentum IdentifyMomentum(const vector<double>& price_differences);
    private:
        const static int kFullPercentage_ = 100;
};

const static vector<string> kMomentumCategories_ = {"Bullish", "Bearish", "Reversal"};
const static vector<string> kMomentumDirections_ = {"Reversal", "Continuation", "None"};

}

#endif //AUTOMATED_FINADVISOR_MOMENTUM_CALCULATOR_H
