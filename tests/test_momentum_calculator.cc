#include <catch2/catch.hpp>
#include "core/momentum-prediction/momentum_calculator.h"

TEST_CASE("Linear Regression Slope") {
    finadvisor::MomentumCalculator calculator;
    std::vector<double> price_differences;

    SECTION("Empty price differences vector") {
        REQUIRE_THROWS_AS(calculator.ComputeLinearRegressionSlope(price_differences), std::invalid_argument);
    }

    SECTION("Mixture of positive and negative price differences") {
        price_differences = {-5, 4, 3, -2, 9};
        REQUIRE(Approx(calculator.ComputeLinearRegressionSlope(price_differences)) == 1.1578947368);
    }

    SECTION("All price differences are positive") {
        price_differences = {1, 2, 3, 4, 5, 6, 7};
        REQUIRE(Approx(calculator.ComputeLinearRegressionSlope(price_differences)) == 0.6363636364);
    }

    SECTION("All price differences are negative") {
        price_differences = {-10, -5, -4, -2};
        REQUIRE(Approx(calculator.ComputeLinearRegressionSlope(price_differences)) == 2.5);
    }
}

TEST_CASE("Relative strength index") {
    finadvisor::MomentumCalculator calculator;
    std::vector<double> price_differences;

    SECTION("Empty price differences vector") {
        REQUIRE_THROWS_AS(calculator.CalculateRelativeStrengthIndex(price_differences), std::invalid_argument);
    }

    SECTION("Average gains outweigh average losses") {
        price_differences = {10, 15, 16, 17, 9, -4, -2};
        REQUIRE(Approx(calculator.CalculateRelativeStrengthIndex(price_differences)) == 128.8461538462);
    }

    SECTION("Average losses outweigh average gains") {
        price_differences = {-3, -10, 8, -7, 2};
        REQUIRE(Approx(calculator.CalculateRelativeStrengthIndex(price_differences)) == -300.0);
    }
}

TEST_CASE("Momentum Categorization") {
    finadvisor::MomentumCalculator calculator;
    std::vector<double> price_differences;

    SECTION("Empty price differences vector") {
        // Caused by call to both ComputeLinearRegressionSlope and CalculateRelativeStrengthIndex, which both throw
        // invalid argument exception.
        REQUIRE_THROWS_AS(calculator.CalculateRelativeStrengthIndex(price_differences), std::invalid_argument);
    }

    SECTION("Bullish Reversal") {
        price_differences = {6, 3, 2, 1, 5, 7};
        REQUIRE(calculator.IdentifyMomentum(price_differences).direction == finadvisor::MomentumDirection::Reversal);
        REQUIRE(calculator.IdentifyMomentum(price_differences).category == finadvisor::MomentumCategory::Bullish);
    }

    SECTION("Bearish Reversal") {
        price_differences = {10, 15, 17, 18, 14, 1};
        REQUIRE(calculator.IdentifyMomentum(price_differences).direction == finadvisor::MomentumDirection::Reversal);
        REQUIRE(calculator.IdentifyMomentum(price_differences).category == finadvisor::MomentumCategory::Bearish);
    }

    SECTION("Bullish Continuation") {
        price_differences = {10, 15, 20};
        REQUIRE(static_cast<int>(calculator.IdentifyMomentum(price_differences).direction) == 0);
        REQUIRE(calculator.IdentifyMomentum(price_differences).category == finadvisor::MomentumCategory::Bullish);
    }

    SECTION("Bearish Continuation") {
        price_differences = {20, 15, 10, 5};
        REQUIRE(static_cast<int>(calculator.IdentifyMomentum(price_differences).direction) == 0);
        REQUIRE(calculator.IdentifyMomentum(price_differences).category == finadvisor::MomentumCategory::Bearish);
    }

    SECTION("Bullish/Bearish Indecision") {
        price_differences = {10, 3, 17, 2, 8, 6};
        REQUIRE(static_cast<int>(calculator.IdentifyMomentum(price_differences).direction) == 0);
        REQUIRE(static_cast<int>(calculator.IdentifyMomentum(price_differences).category) == 1);
    }
}
