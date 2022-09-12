#include <catch2/catch.hpp>
#include "core/volatility-prediction/volatility_calculator.h"

TEST_CASE("Standardized quartile prices") {
    finadvisor::VolatilityCalculator calculator;
    std::vector<double> quartile_prices;

    SECTION("Quartile prices with high variance") {
        quartile_prices = {11, 15, 6, 3, 1};
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[0]) == 0.7373429);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[1]) == 1.5134935);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[2]) == -0.2328451);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[3]) == -0.8149580);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[4]) == -1.2030333);
    }

    SECTION("Quartile prices with low variance") {
        quartile_prices = {1, 2, 3, 4};
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[0]) == -1.3416407);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[1]) == -0.4472135);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[2]) == 0.4472135);
        REQUIRE(Approx(calculator.StandardizeQuartilePrices(quartile_prices)[3]) == 1.3416407);
    }
}

TEST_CASE("Average of Upper and Lower Quartile Prices") {
    finadvisor::VolatilityCalculator calculator;

    SECTION("Opening, Closing, High, and Low prices are all 0") {
        REQUIRE(calculator.CalculateQuartilePrice(0, 0, 0, 0) == 0);
    }

    SECTION("Opening price exceeds Closing price") {
        REQUIRE(calculator.CalculateQuartilePrice(6, 3, 7, 2) == 4.5);
    }

    SECTION("Closing price exceeds Opening price") {
        REQUIRE(calculator.CalculateQuartilePrice(3, 5, 7, 2) == 4.25);
    }

    SECTION("High price matches low price") {
        REQUIRE(calculator.CalculateQuartilePrice(1, 1, 1, 1) == 1.0);
    }

    SECTION("High and Low price match opening and closing prices") {
        REQUIRE(calculator.CalculateQuartilePrice(5, 2, 5, 2) == 3.5);
    }
}

TEST_CASE("Beta Risk Proportion") {
    finadvisor::VolatilityCalculator calculator;
    std::vector<double> quartile_prices;

    SECTION("Empty quartile prices vector") {
        REQUIRE(calculator.ComputeBetaRiskProportion(quartile_prices, 5) == 0);
    }

    SECTION("Single quartile price") {
        quartile_prices = {6};
        REQUIRE(calculator.ComputeBetaRiskProportion(quartile_prices, 3) == 0);
    }

    SECTION("Price variance is 0") {
        quartile_prices = {2, 5};
        REQUIRE(calculator.ComputeBetaRiskProportion(quartile_prices, 0) == 0);
    }

    SECTION("Multiple quartile prices") {
        quartile_prices = {3, 7, 5, 3, 10};
        REQUIRE(Approx(calculator.ComputeBetaRiskProportion(quartile_prices, 4)) == 1.8830046126);
    }

    SECTION("Price variance exceeds all quartile prices") {
        quartile_prices = {2, 3, 4};
        REQUIRE(Approx(calculator.ComputeBetaRiskProportion(quartile_prices, 10)) == 6.0858061945);
    }

}

TEST_CASE("Price variance") {
    finadvisor::VolatilityCalculator calculator;
    std::vector<double> quartile_prices;

    SECTION("Empty quartile prices vector") {
        REQUIRE(calculator.CalculatePriceVariance(quartile_prices) == 0);
    }

    SECTION("Single quartile price") {
        quartile_prices = {5};
        REQUIRE(calculator.CalculatePriceVariance(quartile_prices) == 0);
    }

    SECTION("Multiple quartile prices of different values") {
        quartile_prices = {6, 2, 3, 5, 2};
        REQUIRE(calculator.CalculatePriceVariance(quartile_prices) == 13.2);
    }

    SECTION("Multiple quartile prices of same value") {
        quartile_prices = {9, 9, 9, 9, 9};
        REQUIRE(calculator.CalculatePriceVariance(quartile_prices) == 0);
    }
}

TEST_CASE("Volatility Categorization") {
    finadvisor::VolatilityCalculator calculator;
    std::vector<double> quartile_prices;

    SECTION("Empty quartile prices vector") {
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).category) == 1);
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).measure) == 2);
    }

    SECTION("High Implied Volatility") {
        quartile_prices = {2, 6, 4, 5, 3, 7, 1, 9, 8};
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).category == finadvisor::VolatilityCategory::Implied);
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).measure == finadvisor::VolatilityMeasure::High);
    }

    SECTION("Low Implied Volatility") {
        quartile_prices = {4, 3, 5, 5, 3, 2, 1};
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).category == finadvisor::VolatilityCategory::Implied);
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).measure == finadvisor::VolatilityMeasure::Low);
    }

    SECTION("Medium Implied Volatility") {
        quartile_prices = {3, 5, 6, 4, 5, 6, 6};
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).category == finadvisor::VolatilityCategory::Implied);
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).measure) == 2);
    }

    SECTION("High Historical Volatility") {
        quartile_prices = {2, 9, 10, 15, 13, 12, 14};
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).category) == 0);
        REQUIRE(calculator.IdentifyVolatility(quartile_prices).measure == finadvisor::VolatilityMeasure::High);
    }

    SECTION("Low Historical Volatility") {
        quartile_prices = {20, 16, 12, 4, 3, 2, 2};
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).category) == 0);
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).measure) == 0);
    }

    SECTION("Medium Historical Volatility") {
        quartile_prices = {15, 16, 17, 16, 15, 14, 15};
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).category) == 0);
        REQUIRE(static_cast<int>(calculator.IdentifyVolatility(quartile_prices).measure) == 2);
    }
}