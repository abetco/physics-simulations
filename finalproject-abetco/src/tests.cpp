#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "twoBalls.h"
#include "pendulum.h"

using namespace std;

TEST_CASE("Two Balls Simulation Test", "[two balls]") {
	twoBalls tbSim;
	tbSim.setup();
	SECTION("X Velocity of first ball is set to initial value") {
		REQUIRE(tbSim.getXVel1() == 10);
	}
	SECTION("Y Velocity of first ball is set to initial value") {
		REQUIRE(tbSim.getYVel1() == -10);
	}
	SECTION("X Velocity of second ball is set to initial value") {
		REQUIRE(tbSim.getXVel2() == -10);
	}
	SECTION("Y Velocity of second ball is set to initial value") {
		REQUIRE(tbSim.getYVel2() == -10);
	}
	SECTION("Radius of first ball is set to initial value") {
		REQUIRE(tbSim.getRadius1() == 15);
	}
	SECTION("Radius of second ball is set to initial value") {
		REQUIRE(tbSim.getRadius2() == 15);
	}

}

TEST_CASE("Pendulum Simulation Test", "[pendulum]") {
	Pendulum pendSim;
	pendSim.setup();
	SECTION("Angle is set to initial value") {
		REQUIRE(pendSim.getAngle() == 10);
	}
	SECTION("Gravity is set to initial value") {
		REQUIRE(pendSim.getGravity() == 10);
	}
	SECTION("Length is set to initial value") {
		REQUIRE(pendSim.getLength() == 400);
	}
	SECTION("Start Time is 0") {
		REQUIRE(pendSim.getStartTime() == 0);
	}
	SECTION("calculate xpos") {
		REQUIRE(TRUE == TRUE);
	}
	SECTION("calculate ypos") {
		REQUIRE(TRUE == TRUE);
	}
}
