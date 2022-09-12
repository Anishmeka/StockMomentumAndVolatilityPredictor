#ifndef AUTOMATED_FINADVISOR_VOLATILITY_CALCULATOR_H
#define AUTOMATED_FINADVISOR_VOLATILITY_CALCULATOR_H

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace finadvisor {

/**
 * Enum representing volatility scales.
 */
enum class VolatilityMeasure {
    High = 0,
    Medium = 1,
    Low = 2
};

/**
 * Enum representing types of volatility.
 */
enum class VolatilityCategory {
    Implied = 0,
    Historical = 1
};

/**
 * Constructs volatility based on measure and category.
 */
struct Volatility {
    VolatilityMeasure measure;
    VolatilityCategory category;
};

class VolatilityCalculator {
    public:
        /**
         * Computes quartile price as a representation of the overall price during daily market time periods.
         *
         * @param opening_price Price upon start of day
         * @param closing_price Price upon end of day
         * @param high_price Highest price during day
         * @param low_price Lowest price during day
         * @return Average of first and third quartile prices
         */
        double CalculateQuartilePrice(double opening_price, double closing_price, double high_price,
                                      double low_price) const;
        /**
         * Calculates systematic market securities in comparison to the market as a whole.
         *
         * @param quartile_prices Vector containing quartile prices of each trading day of month.
         * @param price_variance Average of squared price differences from mean quartile price.
         * @return Proportion of price covariance over variance.
         */
        double ComputeBetaRiskProportion(const vector<double>& quartile_prices, double price_variance) const;
        /**
         * Computes the average of squared price differences from the mean quartile price.
         *
         * @param quartile_prices Vector containing quartile prices of each trading day of month.
         * @return Total sum of individual price deviations.
         */
        double CalculatePriceVariance(const vector<double>& quartile_prices) const;
        /**
         * Calculates Z-score of each quartile price in relation to standard deviation and mean.
         *
         * @param quartile_prices Vector containing quartile prices of each trading day of month.
         * @return Vector containing Z-scores of each quartile price
         */
        vector<double> StandardizeQuartilePrices(const vector<double>& quartile_prices) const;

        /**
         * Categorizes volatility based on category and measure.
         *
         * @param quartile_prices Vector containing quartile prices of each trading day of month.
         * @return Volatility struct indicating category and measure.
         */
        Volatility IdentifyVolatility(const vector<double>& quartile_prices);
    private:
        constexpr const static double kHalfProportion_ = 0.5;
        constexpr const static double kTwoThirdsProportion_ = 2 / static_cast<double>(3);
        constexpr const static double kOneThirdsProportion_ = 1 / static_cast<double>(3);
};

const static vector<string> kVolatilityMeasures_ = {"High", "Medium", "Low"};
const static vector<string> kVolatilityCategories_ = {"Implied", "Historical"};

}

#endif //AUTOMATED_FINADVISOR_VOLATILITY_CALCULATOR_H
