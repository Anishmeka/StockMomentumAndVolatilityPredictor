#include "core/volatility-prediction/volatility_calculator.h"
#include "core/momentum-prediction/momentum_calculator.h"
#include <cmath>
#include <numeric>
#include <iostream>

using std::transform;
using std::accumulate;

namespace finadvisor {

vector<double> VolatilityCalculator::StandardizeQuartilePrices(const vector<double>& quartile_prices) const {
    vector<double> standardized_quartile_prices;
    standardized_quartile_prices.reserve(quartile_prices.size());
    // Z-score = (observed value - mean) / standard deviation
    double mean = accumulate(quartile_prices.begin(), quartile_prices.end(), 0.0) /
                  quartile_prices.size();
    double standard_deviation = sqrt((inner_product(quartile_prices.begin(), quartile_prices.end(),
                                                    quartile_prices.begin(), 0.0) / quartile_prices.size()) - pow(mean, 2));
    for (double quartile_price : quartile_prices) {
        standardized_quartile_prices.emplace_back((quartile_price - mean) / standard_deviation);
    }
    return standardized_quartile_prices;
}

double VolatilityCalculator::CalculateQuartilePrice(double opening_price, double closing_price, double high_price,
                                                    double low_price) const {
    // The average of the first and third quartiles is employed as a representative measure of the overall price
    // during the hour since closing, opening, low, and high prices, at an individual level, are prone to variation.
    double upper_quartile_average = (closing_price + high_price) / 2;
    double lower_quartile_average = (low_price + opening_price) / 2;
    return (upper_quartile_average + lower_quartile_average) / 2;
}

double VolatilityCalculator::ComputeBetaRiskProportion(const vector<double>& quartile_prices, double price_variance) const {
    if (quartile_prices.empty() || price_variance == 0) {
        return 0;
    }
    // Slope of linear regression is the covariance divided by variance of an independent variable.
    // So, covariance = linear regression slope * variance
    MomentumCalculator calculator;
    double price_covariance = calculator.ComputeLinearRegressionSlope(quartile_prices) * price_variance;
    // Ignore denominator in conventional beta risk formula as the variance is standardized during computation of
    // linear regression slope.
    return sqrt((1 / static_cast<double>(quartile_prices.size())) * price_variance) * price_covariance;
}

double VolatilityCalculator::CalculatePriceVariance(const vector<double>& quartile_prices) const {
    vector<double> quartile_price_deviations;
    quartile_price_deviations.reserve(quartile_prices.size());
    double quartile_price_average = 0;

    for (double quartile_price : quartile_prices) {
        quartile_price_deviations.emplace_back(quartile_price);
        quartile_price_average += quartile_price;
    }
    quartile_price_average /= quartile_price_deviations.size();
    // Subtract quartile price average from each element of vector and then square each element
    transform(quartile_price_deviations.begin(), quartile_price_deviations.end(), quartile_price_deviations.begin(),
              [&](double quartile_price) { return pow(quartile_price - quartile_price_average, 2); });
    // Return sum of price deviations
    return accumulate(quartile_price_deviations.begin(), quartile_price_deviations.end(), 0.0);
}

Volatility VolatilityCalculator::IdentifyVolatility(const vector<double>& quartile_prices) {
    Volatility volatility;
    // Note: The use of volatility index below cannot be confounded with the CBOE volatility index
    double volatility_index = CalculatePriceVariance(quartile_prices);
    // Beta risk proportion is an indicator of the volatility's ability to predict the future dispersion of market
    // returns or securities or to reflect the past dispersion.
    if (abs(ComputeBetaRiskProportion(quartile_prices, volatility_index)) >= kHalfProportion_) {
        volatility.category = VolatilityCategory::Implied;
    } else {
        volatility.category = VolatilityCategory::Historical;
    }

    volatility_index /= quartile_prices.size();
    if (volatility_index >= (kTwoThirdsProportion_ * quartile_prices.size())) {
        volatility.measure = VolatilityMeasure::High;
    } else if (volatility_index >= (kOneThirdsProportion_) * quartile_prices.size()) {
        volatility.measure = VolatilityMeasure::Medium;
    } else {
        volatility.measure = VolatilityMeasure::Low;
    }
    return volatility;
}

}
