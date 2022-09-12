#include <catch2/catch.hpp>
#include "core/data_processor.h"

TEST_CASE("Split string into vector") {
    std::string input_string = "Hello there this is some text";
    DataProcessor processor;

    SECTION("First word") {
        REQUIRE(processor.Split(input_string, " ")[0] == "Hello");
    }

    SECTION("Middle word in vector") {
        REQUIRE(processor.Split(input_string, " ")[2] == "this");
    }

    SECTION("Last word in vector") {
        REQUIRE(processor.Split(input_string, " ")[5] == "text");
    }

    SECTION("Invalid parse character") {
        // Control flow should not end
        REQUIRE(processor.Split(input_string, ",")[0] == "Hello there this is some text");
    }
}
