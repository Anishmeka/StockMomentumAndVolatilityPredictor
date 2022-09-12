#include <catch2/catch.hpp>
#include "core/volatility-prediction/volatility_training_data_factory.h"
#include "core/volatility-prediction/volatility_calculator.h"
#include <sstream>

TEST_CASE("Validate Files for Valatility Training Data Factory") {
    finadvisor::VolatilityTrainingDataFactory factory;
    std::vector<std::string> file_paths;

    SECTION("Invalid File Path for existent file") {
        file_paths = {"/../..abengoa.csv", "/../..bme.csv"};
        REQUIRE_THROWS_AS(factory.ValidateFiles(file_paths), std::invalid_argument);
    }

    SECTION("Non-existent file") {
        factory.ValidateFiles(file_paths);
    }

    SECTION("Incorrect number of lines for file") {
        file_paths = {"invalid.csv"};
        REQUIRE_THROWS_AS(factory.ValidateFiles(file_paths), std::invalid_argument);
    }

    SECTION("Valid file path") {
        // Control flow will end here if file path is invalid due to invalid argument exception, so test should
        // pass if no exception is thrown
        file_paths = {"stock_data.csv"};
        factory.ValidateFiles(file_paths);
    }
}

TEST_CASE("Overload of Extraction Operator for Volatility Training Data Factory") {
    finadvisor::VolatilityTrainingDataFactory factory;
    std::vector<std::string> file_paths = {"stock_data.csv"};
    factory = factory.ValidateFiles(file_paths);

    // Call to ValidateFiles invokes extraction operator
    SECTION("Volatility of first map element") {
        REQUIRE(factory.GetVolatility(0).measure == finadvisor::VolatilityMeasure::Low);
        REQUIRE(static_cast<int>(factory.GetVolatility(0).category) == 1);
    }

    SECTION("Volatility of middle map element") {
        REQUIRE(static_cast<int>(factory.GetVolatility(5).measure) == 2);
        REQUIRE(factory.GetVolatility(5).category == finadvisor::VolatilityCategory::Historical);
    }

    SECTION("Volatility of last map element") {
        REQUIRE(static_cast<int>(factory.GetVolatility(10).measure) == 2);
        REQUIRE(static_cast<int>(factory.GetVolatility(10).category) == 1);
    }

    SECTION("Standardized Quartile Prices of first map element") {
        std::vector<double> standardized_quartile_prices = {0.4354, -0.4653, -0.7643, 0.6543};
        REQUIRE(Approx(factory.GetStandardizedQuartilePrices(0)[0]) == -2.9031606032);
    }

    SECTION("Standardized Quartile Prices of middle map element") {
        std::vector<double> standardized_quartile_prices = {-0.5643, 0.7684, 0.9465, 0.9574, -0.43234, 0.4824, 0.4328};
        REQUIRE(Approx(factory.GetStandardizedQuartilePrices(5)[3]) == -1.0038978863);
    }

    SECTION("Standardized Quartile Prices of last map element") {
        std::vector<double> standardized_quartile_prices = {0.9432, -0.3545, 0.4545};
        REQUIRE(Approx(factory.GetStandardizedQuartilePrices(10)[2]) == -1.8675681209);
    }
}
