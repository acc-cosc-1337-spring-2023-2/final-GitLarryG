#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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

TEST_CASE("Test roll die rolls return a value from 2 to 12")
{
	Die die1;
	Die die2;
	Roll roll(die1, die2);
	roll.roll_dice();
	int roll_value = roll.roll_value();
	REQUIRE(roll_value >= 2);
	REQUIRE(roll_value <= 12);
}

TEST_CASE("Test Shooter class shoot function")
{
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll = shooter.shoot(die1, die2);
	REQUIRE(roll->roll_value() >= 2);
	REQUIRE(roll->roll_value() <= 12);
}
