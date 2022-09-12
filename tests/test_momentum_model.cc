#include <catch2/catch.hpp>
#include "core/momentum-prediction/momentum_model.h"

TEST_CASE("Validate File for Momentum Model") {
    finadvisor::MomentumModel model;

    SECTION("Invalid File Path for existent file") {
        REQUIRE_THROWS_AS(model.ValidateFile("/../..abengoa.csv"), std::invalid_argument);
    }

    SECTION("Non-existent file") {
        REQUIRE_THROWS_AS(model.ValidateFile("fakefile.csv"), std::invalid_argument);
    }

    SECTION("Incorrect number of lines for file") {
        REQUIRE_THROWS_AS(model.ValidateFile("invalid.csv"), std::invalid_argument);
    }

    SECTION("Valid file path") {
        // Control flow will end here if file path is invalid due to invalid argument exception, so test should
        // pass if no exception is thrown
        model.ValidateFile("training_model_data.csv");
    }
}

TEST_CASE("Generation of Momentum Point") {
    finadvisor::MomentumModel model;
    model.SetFileLine("↗↘---↘↘↗↘↘↘↗↘↘-");
    model.GenerateMomentumPoint();

    SECTION("Price increase value following function call") {
        REQUIRE(model.GetPriceIncreaseProbability(0) == 0.2);
    }

    SECTION("Price decrease value following function call") {
        REQUIRE(model.GetPriceDecreaseProbability(0) == 0.53333333333);
    }

    SECTION("Static price value following function call") {
        REQUIRE(model.GetStaticPriceProbability(0) == 0.26666666666);
    }
}

TEST_CASE("Overload of extraction operator for Momentum Model") {
    finadvisor::MomentumModel model;
    // Call to ValidateFile invokes extraction operator
    model = model.ValidateFile("training_model_data.csv");

    // Tests elements of the momentum points vector
    SECTION("Price Increase Probability of first vector element") {
        REQUIRE(Approx(model.GetPriceIncreaseProbability(0)) == 0.4334322);
    }

    SECTION("Price Decrease Probability of first vector element") {
        REQUIRE(Approx(model.GetPriceDecreaseProbability(0)) == 0.122334);
    }

    SECTION("Static Price Probability of first vector element") {
        REQUIRE(Approx(model.GetStaticPriceProbability(0)) == 0.4442338);
    }

    SECTION("Momentum Trend of first vector element") {
        REQUIRE(model.GetMomentumTrend(0) == "Bearish Reversal");
    }

    SECTION("Vector element probabilities sum to 1") {
        REQUIRE(model.GetPriceIncreaseProbability(3) + model.GetPriceDecreaseProbability(3) +
                model.GetStaticPriceProbability(3) == 1);
    }

    SECTION("Price Increase Probability of middle vector element") {
        REQUIRE(Approx(model.GetPriceIncreaseProbability(646)) == 0.4397832);
    }

    SECTION("Price Decrease Probability of middle vector element") {
        REQUIRE(Approx(model.GetPriceDecreaseProbability(646)) == 0.312679);
    }

    SECTION("Static Price Probability of middle vector element") {
        REQUIRE(Approx(model.GetStaticPriceProbability(646)) == 0.2475378);
    }

    SECTION("Momentum Trend of middle vector element") {
        REQUIRE(model.GetMomentumTrend(646) == "Indecision None");
    }

    SECTION("Price Increase Probability of last vector element") {
        REQUIRE(Approx(model.GetPriceIncreaseProbability(1292)) == 0.324976);
    }

    SECTION("Price Decrease Probability of last vector element") {
        REQUIRE(Approx(model.GetPriceDecreaseProbability(1292)) == 0.1234334);
    }

    SECTION("Static Price Probability of last vector element") {
        REQUIRE(Approx(model.GetStaticPriceProbability(1292)) == 0.5515906);
    }

    SECTION("Momentum Trend of last vector element") {
        REQUIRE(model.GetMomentumTrend(1292) == "Bearish Continuation");
    }
}

TEST_CASE("Invalid vector indices for Momentum model getter methods") {
    finadvisor::MomentumModel model;

    SECTION("Price increase probability") {
        REQUIRE_THROWS_AS(model.GetPriceIncreaseProbability(78903), std::invalid_argument);
    }

    SECTION("Price decrease probability") {
        REQUIRE_THROWS_AS(model.GetPriceDecreaseProbability(34097), std::invalid_argument);
    }

    SECTION("Static price probability") {
        REQUIRE_THROWS_AS(model.GetStaticPriceProbability(59843454), std::invalid_argument);
    }

    SECTION("Momentum Trend") {
        REQUIRE_THROWS_AS(model.GetMomentumTrend(435950545), std::invalid_argument);
    }

    SECTION("Distance") {
        REQUIRE_THROWS_AS(model.GetDistance(64453546), std::invalid_argument);
    }

}

TEST_CASE("Euclidean Distance Calculation") {
    finadvisor::MomentumPoint point;
    finadvisor::MomentumModel model;

    SECTION("Uninitialized current momentum point struct") {
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, 0.15, 0.35, 0.5)) == 0.62849025455);
    }

    SECTION("X, y, and z coordinate are all 0") {
        REQUIRE(model.CalculateEuclideanDistance(point, 0, 0, 0) == 0);
    }

    SECTION("X, y, and z query coordinates do not sum to 0") {
        REQUIRE(model.CalculateEuclideanDistance(point, 0.3, 0.6, 0.2) == 0.7);
    }

    SECTION("Initialized current momentum point struct") {
        point.price_increase_probability = 0.2;
        point.price_decrease_probability = 0.5;
        point.static_price_probability = 0.3;
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, 0.35, 0.6, 0.05)) == 0.3082207001);
    }

    SECTION("X, y, and z coordinates of current and query point match") {
        point.price_increase_probability = 0.1;
        point.price_decrease_probability = 0.3;
        point.static_price_probability = 0.6;
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, 0.1, 0.3, 0.6)) == 0);
    }
    SECTION("X coordinate is negative") {
        // Should not occur but exception should not be thrown if it is negative
        point.price_decrease_probability = 0.2;
        point.price_increase_probability = 0.2;
        point.static_price_probability = 0.6;
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, -0.3, 1.0, 0.3)) == 0.98994937);
    }

    SECTION("Y coordinate is negative") {
        point.price_increase_probability = 0.3;
        point.price_decrease_probability = 0.3;
        point.static_price_probability = 0.4;
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, 0.9, -0.9, 1.0)) == 1.469693846);
    }

    SECTION("Z coordinate is negative") {
        point.price_decrease_probability = 0.1;
        point.price_increase_probability = 0.8;
        point.static_price_probability = 0.1;
        REQUIRE(Approx(model.CalculateEuclideanDistance(point, 0.6, 1.0, -0.6)) == 0.8831760866);
    }
}

TEST_CASE("K Nearest Label Average") {
    finadvisor::MomentumModel model;
    model = model.ValidateFile("training_model_data.csv");

    SECTION("K value is 0") {
        REQUIRE(model.ComputeKNearestLabelsAverage(0, 0.4, 0.2, 0.4) == 0);
    }

    SECTION("X, y, and z coordinates are all 0") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(3, 0, 0, 0)) == 0.56738595);
    }

    SECTION("K value is 1") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(1, 0.2, 0.3, 0.6)) == 0.44865646);
    }

    SECTION("K value is 5") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(5, 0.4, 0.1, 0.5)) == 0.359686944);
    }

    SECTION("X, y, and z query coordinates do not sum to 0") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(2, 0.4, 0.4, 0.4)) == 0.8439466967);
    }

    SECTION("X coordinate is negative") {
        // Should not occur but exception should not be thrown if it is negative
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(3, -0.3, 1.0, 0.3)) == 0.3457046562);
    }

    SECTION("Y coordinate is negative") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(6, 0.9, -0.9, 1.0)) == 0.259650566);
    }

    SECTION("Z coordinate is negative") {
        REQUIRE(Approx(model.ComputeKNearestLabelsAverage(4, 0.6, 1.0, -0.6)) == 0.456978567);
    }
}