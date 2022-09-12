#include <catch2/catch.hpp>
#include "core/volatility-prediction/volatility_model.h"

TEST_CASE("Validate File for Volatility Model") {
    finadvisor::VolatilityModel model;

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
    }
}

TEST_CASE("Generation of Volatility Point") {
    finadvisor::VolatilityModel model;
    model.SetFileLine("-++-+--+++-+");
    model.GenerateVolatilityPoint();

    SECTION("Positive Z score probability following function call") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(0)) == 0.58333333);
    }

    SECTION("Negative Z score probability following function call") {
        REQUIRE(Approx(model.GetNegativeZScoreProbability(0)) == 0.41666667);
    }

    model.SetFileLine("+");
    model.GenerateVolatilityPoint();

    SECTION("Z score probabilities for single + character") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(1)) == 1.5833333333);
        REQUIRE(Approx(model.GetNegativeZScoreProbability(1)) == 0.4166666667);
    }

    model.SetFileLine("-");
    model.GenerateVolatilityPoint();

    SECTION("Z score probabilities for single - character") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(2)) == 1.5833333333);
        REQUIRE(Approx(model.GetNegativeZScoreProbability(2)) == 1.4166666667);
    }
}

TEST_CASE("Overload of extraction operator for Volatility model") {
    finadvisor::VolatilityModel model;
    // Call to ValidateFile invokes extraction operator
    model = model.ValidateFile("training_volatility_model_data.csv");

    // Tests elements of volatility points vector
    SECTION("Positive Z score probability of first vector element") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(0)).margin(0.01) == 0.0);
    }

    SECTION("Negative Z score probability of first vector element") {
        REQUIRE(Approx(model.GetNegativeZScoreProbability(0)).margin(0.01) == 1.0);
    }

    SECTION("Volatility Type of first vector element") {
        REQUIRE(model.GetVolatilityType(0) == "High Implied");
    }

    SECTION("Vector element probabilities sum to 1") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(4) + model.GetNegativeZScoreProbability(4)).margin(0.1) == 1);
    }

    SECTION("Positive Z score probability of middle vector element") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(5)).margin(0.01) == 0.0);
    }

    SECTION("Negative Z score probability of middle vector element") {
        REQUIRE(Approx(model.GetNegativeZScoreProbability(5)) == 1.0511945254);
    }

    SECTION("Volatility Type of middle vector element") {
        REQUIRE(model.GetVolatilityType(5) == "Low Historical");
    }

    SECTION("Positive Z score probability of last vector element") {
        REQUIRE(Approx(model.GetPositiveZScoreProbability(10)).margin(0.01) == 0.0);
    }

    SECTION("Negative Z score probability of last vector element") {
        REQUIRE(Approx(model.GetNegativeZScoreProbability(10)) == 1.0750853242);
    }

    SECTION("Volatility Type of last vector element") {
        REQUIRE(model.GetVolatilityType(10) == "Low Historical");
    }
}

TEST_CASE("Invalid vector indices for Volatility Model getter methods") {
    finadvisor::VolatilityModel model;

    SECTION("Positive Z score probability") {
        REQUIRE_THROWS_AS(model.GetPositiveZScoreProbability(449554547654), std::invalid_argument);
    }

    SECTION("Negative Z score probability") {
        REQUIRE_THROWS_AS(model.GetNegativeZScoreProbability(48340595454), std::invalid_argument);
    }

    SECTION("Volatility Type") {
        // Vector size is 1293
        REQUIRE_THROWS_AS(model.GetVolatilityType(1293), std::invalid_argument);
    }
}

TEST_CASE("Computation of new centroids") {
    finadvisor::VolatilityModel model;
    model.UpdateCentroidData();

    SECTION("Point count of first centroid vector element") {
        REQUIRE(model.GetCentroid(0).point_count == 53);
    }

    SECTION("Point count of middle centroid vector element") {
        REQUIRE(model.GetCentroid(621).point_count == 34);
    }

    SECTION("Point count of last centroid vector element") {
        REQUIRE(model.GetCentroid(1242).point_count == 45);
    }

    SECTION("X coordinate sum of first centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(0).x_coordinate_sum) == 35.4567674);
    }

    SECTION("Y coordinate sum of first centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(0).y_coordinate_sum) == 24.4565694);
    }

    SECTION("X coordinate sum of middle centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(621).x_coordinate_sum) == 26.3958656);
    }

    SECTION("Y coordinate sum of middle centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(621).y_coordinate_sum) == 34.239850);
    }

    SECTION("X coordinate sum of last centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(1242).x_coordinate_sum) == 31.389586);
    }

    SECTION("Y coordinate sum of last centroid vector element") {
        REQUIRE(Approx(model.GetCentroid(1242).y_coordinate_sum) == 32.4568978);
    }

    SECTION("Volatility type of first cluster vector element") {
        REQUIRE(model.GetCluster(0).volatility_type == "High Historical");
    }

    SECTION("Volatility type of middle cluster vector element") {
        REQUIRE(model.GetCluster(345).volatility_type == "Medium Implied");
    }

    SECTION("Volatility type of last cluster vector element") {
        REQUIRE(model.GetCluster(690).volatility_type == "High Implied");
    }

    SECTION("Positive z score probability of first cluster vector element") {
        REQUIRE(Approx(model.GetCluster(0).positive_z_score_probability) == 0.34596677);
    }

    SECTION("Negative z score probability of first cluster vector element") {
        REQUIRE(Approx(model.GetCluster(0).negative_z_score_probability) == 0.65403323);
    }

    SECTION("Positive z score probability of middle cluster vector element") {
        REQUIRE(Approx(model.GetCluster(345).positive_z_score_probability) == 0.6495866);
    }

    SECTION("Negative z score probability of middle cluster vector element") {
        REQUIRE(Approx(model.GetCluster(345).negative_z_score_probability) == 0.3504134);
    }

    SECTION("Positive z score probability of last cluster vector element") {
        REQUIRE(Approx(model.GetCluster(690).positive_z_score_probability) == 0.45769775);
    }

    SECTION("Negative z score probability of last cluster vector element") {
        REQUIRE(Approx(model.GetCluster(690).negative_z_score_probability) == 0.54230225);
    }

}

TEST_CASE("Initialization of Clusters") {
    finadvisor::VolatilityModel model;
    model.AssignClusterPoints(101);

    SECTION("Minimum distance of first volatility point") {
        REQUIRE(Approx(model.GetMinimumDistance(0)) == 0.89656089);
    }

    SECTION("Minimum distance of middle volatility point") {
        REQUIRE(Approx(model.GetMinimumDistance(50)) == 0.9586578);
    }

    SECTION("Minimum distance of last volatility point") {
        REQUIRE(Approx(model.GetMinimumDistance(100)) == 0.9332854);
    }

    SECTION("Cluster value of first volatility point") {
        REQUIRE(model.GetClusterValue(0) == 34);
    }

    SECTION("Cluster value of middle volatility point") {
        REQUIRE(model.GetClusterValue(50) == 23);
    }

    SECTION("Cluster value of last volatility point") {
        REQUIRE(model.GetClusterValue(100) == 36);
    }
}

