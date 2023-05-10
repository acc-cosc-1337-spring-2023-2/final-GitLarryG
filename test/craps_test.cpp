#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"

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

TEST_CASE("Test ComeOutPhase get_outcome function returns natural, craps, or point")
{
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll = shooter.shoot(die1, die2);
	ComeOutPhase come_out_phase;
	RollOutcome roll_outcome = come_out_phase.get_outcome(roll, 0);
	if (roll_outcome == RollOutcome::natural)
	{
		REQUIRE(roll_outcome == RollOutcome::natural);
	}
	else if (roll_outcome == RollOutcome::craps)
	{
		REQUIRE(roll_outcome == RollOutcome::craps);
	}
	else
	{
		REQUIRE(roll_outcome == RollOutcome::point);
	}
}

TEST_CASE("Test PointPhase get_outcome function returns point, seven_out, or nopoint")
{
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll = shooter.shoot(die1, die2);
	PointPhase point_phase(roll->roll_value());
	RollOutcome roll_outcome = point_phase.get_outcome(roll, roll->roll_value());
	if (roll_outcome == RollOutcome::point)
	{
		REQUIRE(roll_outcome == RollOutcome::point);
	}
	else if (roll_outcome == RollOutcome::seven_out)
	{
		REQUIRE(roll_outcome == RollOutcome::seven_out);
	}
	else
	{
		REQUIRE(roll_outcome == RollOutcome::nopoint);
	}
}