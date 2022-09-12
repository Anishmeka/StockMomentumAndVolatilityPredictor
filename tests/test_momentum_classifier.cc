#include <catch2/catch.hpp>
#include "core/momentum-prediction/momentum_model.h"
#include "core/momentum-prediction/momentum_training_data_factory.h"
#include "core/momentum-prediction/momentum_classifier.h"

TEST_CASE("Momentum Validation Accuracy") {
    vector<string> file_paths = {"abengoa.csv"};
    double accuracy = 0.7;
    finadvisor::MomentumTrainingDataFactory factory;
    factory = factory.ValidateFiles(file_paths);
    finadvisor::MomentumModel model;
    model.ValidateFile(factory.WriteToOutputFile(factory));
    finadvisor::MomentumClassifier classifier;
    classifier = classifier.ValidateFile("testmomentumdata.txt");

    REQUIRE(classifier.CalculateValidationAccuracy(model, 5) >= accuracy);
}

TEST_CASE("Overload of momentum classifier extraction operator") {
    finadvisor::MomentumClassifier classifier;
    // Call to ValidateFile invokes extraction operator

    SECTION("Price increase probability of first momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(0).price_increase_probability == 0.3245767);
    }

    SECTION("Price decrease probability of first momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(0).price_decrease_probability == 0.34553623);
    }

    SECTION("Static price probability of first momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(0).static_price_probability == 0.32988707);
    }

    SECTION("Momentum trend of first momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(0).momentum_trend == "Bearish Reversal");
    }

    SECTION("Price increase probability of last momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(682).price_increase_probability == 0.5986535);
    }

    SECTION("Price decrease probability of last momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(682).price_decrease_probability == 0.22445666);
    }

    SECTION("Static price probability of last momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(682).static_price_probability == 0.17688984);
    }

    SECTION("Momentum trend of last momentum testing point") {
        REQUIRE(classifier.GetMomentumTestingPoint(682).momentum_trend == "Bullish Continuation");
    }

}