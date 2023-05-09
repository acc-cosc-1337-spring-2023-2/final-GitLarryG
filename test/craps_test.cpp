#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

// Test case for Die class
TEST_CASE("Test Die class roll function") {
    Die die;
    int roll_value = die.roll();
    REQUIRE(roll_value >= 1);
    REQUIRE(roll_value <= 6);
}