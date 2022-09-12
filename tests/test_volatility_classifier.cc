#include <catch2/catch.hpp>
#include "core/volatility-prediction/volatility_model.h"
#include "core/volatility-prediction/volatility_training_data_factory.h"
#include "core/volatility-prediction/volatility_classifier.h"

TEST_CASE("Volatility Validation Accuracy") {
    std::string directory_path = "../trainingdata";
    vector<string> file_paths;
    file_paths.resize(20);
    for (const auto& file : std::filesystem::directory_iterator(directory_path)) {
        file_paths.emplace_back(file);
    }
    vector<string> file_paths = {"abengoa.csv", "acciona.csv", "acerinox.csv", "acs.csv", "atresmedia.csv",
                                 "banco-sabadell.csv", "bankinter.csv", "bbva.csv", "bme.csv", "caixabank.csv",
                                 "colonial.csv", "enags.csv", "fcc.csv", "ferrovial.csv", "grifols.csv", "iberdrola.csv",
                                 "inditex.csv", "indra.csv", "mapfre.csv", "mediaset.csv"};
    finadvisor::VolatilityTrainingDataFactory factory;
    factory = factory.ValidateFiles(file_paths);
    finadvisor::VolatilityModel model;
    model.ValidateFile(factory.WriteToOutputFile(factory));
    finadvisor::VolatilityClassifier classifier;
    classifier = classifier.ValidateFile("testvolatilitydata.txt");
    REQUIRE(classifier.CalculateValidationAccuracy(model, 5) >= 0.7);
}

TEST_CASE("Overload of volatility classifier extraction operator") {
    finadvisor::VolatilityClassifier classifier;
    // Call to ValidateFile invokes extraction operator
    classifier = classifier.ValidateFile("sample_volatility_testing_data.txt");

    SECTION("Positive z score probability of first volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(0).positive_z_score_probability == 0.3957946);
    }

    SECTION("Negative z score probability of first volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(0).negative_z_score_probability == 0.6042054);
    }

    SECTION("Volatility Type of first volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(0).volatility_type == "Low Implied");
    }

    SECTION("Positive z score probability of last volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(682).positive_z_score_probability == 0.73495563);
    }

    SECTION("Negative z score probability of last volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(682).negative_z_score_probability == 0.26504437);
    }

    SECTION("Volatility Type of last volatility testing point") {
        REQUIRE(classifier.GetVolatilityTestingPoint(682).volatility_type == "High Historical");
    }

}