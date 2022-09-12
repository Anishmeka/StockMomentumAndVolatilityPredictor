#include <catch2/catch.hpp>
#include "core/momentum-prediction/momentum_training_data_factory.h"
#include <sstream>

TEST_CASE("Validate Files for Momentum Training Data Factory") {
    finadvisor::MomentumTrainingDataFactory factory;
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

TEST_CASE("Overload of Extraction Operator for Momentum Training Data Factory") {
    finadvisor::MomentumTrainingDataFactory factory;
    std::vector<std::string> file_paths = {"stock_data.csv"};
    factory = factory.ValidateFiles(file_paths);

    // Call to ValidateFiles invokes extraction operator
    SECTION("Momentum of first map element") {
        REQUIRE(factory.GetMomentum(0).category == finadvisor::MomentumCategory::Bearish);
        REQUIRE(factory.GetMomentum(0).direction == finadvisor::MomentumDirection::Reversal);
    }

    SECTION("Momentum of middle map element") {
        REQUIRE(static_cast<int>(factory.GetMomentum(5).category) == 0);
        REQUIRE(static_cast<int>(factory.GetMomentum(5).direction) == 1);
    }

    SECTION("Momentum of last map element") {
        REQUIRE(static_cast<int>(factory.GetMomentum(10).category) == 0);
        REQUIRE(static_cast<int>(factory.GetMomentum(10).direction) == 0);
    }

    SECTION("Price Differences of first map element") {
        // Check index within price differences vector to find price difference
        std::vector<double> price_differences = {0.54, 0.345, -0.456, 0.55};
        REQUIRE(Approx(factory.GetPriceDifferences(0)[0]) == -0.47);
    }

    SECTION("Price Differences of middle map element") {
        std::vector<double> price_differences = {-0.24, -0.355, 0.87, 0.97, 0.65, 0.74, -0.87};
        REQUIRE(Approx(factory.GetPriceDifferences(5)[3]).margin(0.01) == 0.1);
    }

    SECTION("Price Differences of last map element") {
        std::vector<double> price_differences = {-0.34, 0.67, 0.54};
        REQUIRE(Approx(factory.GetPriceDifferences(10)[2]).margin(0.01) == 0.15);
    }
}

TEST_CASE("Overload of insertion operator for Momentum Training Data Factory") {
    finadvisor::MomentumTrainingDataFactory factory;
    std::vector<std::string> file_paths = {"stock_data.csv"};
    factory = factory.ValidateFiles(file_paths);
    std::stringstream stream;
    stream << factory;

    SECTION("Momentum Label of First Line") {
        REQUIRE(stream.str().substr(0, 16) == "Bearish Reversal");
    }


}
