#include "core/momentum-prediction/momentum_calculator.h"
#include <numeric>

using std::iota;
using std::accumulate;
using std::invalid_argument;
using std::count_if;
using std::for_each;

namespace finadvisor {

double MomentumCalculator::ComputeLinearRegressionSlope(const vector<double>& price_differences) {
    vector<size_t> day_counts(price_differences.size());
    // Populate vector with values from 0 - 99
    iota(day_counts.begin(), day_counts.end(), 0);
    // Add 1 to each vector element
    for_each(day_counts.begin(), day_counts.end(), [](size_t& day_count) { day_count += 1; });

    double day_count_average = accumulate(day_counts.begin(), day_counts.end(), 0.0) / price_differences.size();
    double price_difference_average = accumulate(price_differences.begin(), price_differences.end(), 0.0) /
            price_differences.size();
    double slope_numerator = 0.0;
    double slope_denominator = 0.0;

    for (size_t i = 0; i < price_differences.size(); i++) {
        slope_numerator += (day_counts[i] - day_count_average) * (price_differences[i] - price_difference_average);
        if (day_counts[i] != day_count_average) {
            slope_denominator += (day_counts[i] - day_count_average) * (day_counts[i] - day_count_average);
        } else {
            slope_denominator += pow(day_counts[i], 2);
        }
    }

    if (slope_denominator == 0.0){
        throw invalid_argument("Divide by 0 error for denominator of slope of line of best fit");
    }

    return slope_numerator / slope_denominator;
}

// RSI measures the magnitude of recent price changes to evaluate overbought and oversold conditions.
// The calculation below makes use of the first step in RSI calculation as the previous average gains and previous
// average losses calculations are negligible and taken into account in calculations of current average gains and losses.
double MomentumCalculator::CalculateRelativeStrengthIndex(const vector<double>& price_differences) {
    if (price_differences.empty()) {
        throw std::invalid_argument("Divide by 0 error: Price differences vector is empty");
    }
    double average_gain = 0.0;
    double average_loss = 0.0;
    size_t positive_price_count = 0;
    size_t negative_price_count = 0;
    for (double price_difference : price_differences) {
        if (price_difference > 0) {
            average_gain += price_difference;
            positive_price_count++;
        } else if (price_difference < 0){
            average_loss += price_difference;
            negative_price_count++;
        }
    }
    average_gain /= positive_price_count;
    average_loss /= negative_price_count;

    double lookback_period_percentage = kFullPercentage_ / (1 + (average_gain / average_loss));
    return kFullPercentage_ - lookback_period_percentage;
}

Momentum MomentumCalculator::IdentifyMomentum(const vector<double> &price_differences) {
    Momentum momentum;
    double linear_regression_slope = ComputeLinearRegressionSlope(price_differences);
    if (linear_regression_slope > 0) {
        momentum.category = MomentumCategory::Bullish;
    } else if (linear_regression_slope < 0) {
        momentum.category = MomentumCategory::Bearish;
    } else {
        momentum.category = MomentumCategory::Indecision;
        momentum.direction = MomentumDirection::None;
        return momentum;
    }
    double relative_strength_index = CalculateRelativeStrengthIndex(price_differences);
    if ((relative_strength_index > 0 && momentum.category == MomentumCategory::Bullish) ||
        (relative_strength_index < 0 && momentum.category == MomentumCategory::Bearish)) {
        momentum.direction = MomentumDirection::Continuation;
    } else {
        momentum.direction = MomentumDirection::Reversal;
    }
    return momentum;
}

}