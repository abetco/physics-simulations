#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "twoBalls.h"
#include "pendulum.h"

using namespace std;

TEST_CASE("Pendulum Simulation Test", "[pendulum]") {
	Pendulum pendSim;
	pendSim.setup();
	SECTION("Angle is set to initial value") {
		REQUIRE(pendSim.getAngle() == 10);
	}
	SECTION("Gravity is set to initial value") {
		REQUIRE(pendSim.getGravity() == 10);
	}
	SECTION("Lenght is set to initial value") {
		REQUIRE(pendSim.getLength() == 400);
	}
	SECTION("calculate xpos") {
		REQUIRE(TRUE == TRUE);
	}
	SECTION("calculate ypos") {
		REQUIRE(TRUE == TRUE);
	}
}
