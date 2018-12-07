#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "twoBalls.h"
#include "pendulum.h"
#include "mirrorLens.h"
#include "buoyancy.h"
#include "chaoticPendulum.h"

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
	SECTION("X Velocity of first ball is reset to initial value") {
		tbSim.setXVel1(12322);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getXVel1() == 10);
	}
	SECTION("Y Velocity of first ball is reset to initial value") {
		tbSim.setYVel1(12312322);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getYVel1() == -10);
	}
	SECTION("X Velocity of second ball is reset to initial value") {
		tbSim.setXVel2(123412322);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getXVel2() == -10);
	}
	SECTION("Y Velocity of second ball is reset to initial value") {
		tbSim.setYVel2(12320902);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getYVel2() == -10);
	}
	SECTION("Radius of first ball is reset to initial value") {
		tbSim.setRadius1(123042322);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getRadius1() == 15);
	}
	SECTION("Radius of second ball is reset to initial value") {
		tbSim.setRadius2(12322989805);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getRadius2() == 15);
	}
	SECTION("X Velocity of first ball is reset to initial value") {
		tbSim.setXVel1(12322);
		tbSim.keyPressed('r');
		REQUIRE(tbSim.getXVel1() == 10);
	}
	SECTION("Y Velocity of first ball is not reset to initial value") {
		tbSim.setYVel1(12312322);
		tbSim.keyPressed('z');
		REQUIRE(tbSim.getYVel1() == 12312322);
	}
	SECTION("X Velocity of second ball is reset to initial value") {
		tbSim.setXVel2(123412322);
		tbSim.keyPressed('p');
		REQUIRE(tbSim.getXVel2() == 123412322);
	}
	SECTION("Y Velocity of second ball is reset to initial value") {
		tbSim.setYVel2(12320902);
		tbSim.keyPressed('u');
		REQUIRE(tbSim.getYVel2() == 12320902);
	}
	SECTION("Radius of first ball is reset to initial value") {
		tbSim.setRadius1(123042322);
		tbSim.keyPressed('l');
		REQUIRE(tbSim.getRadius1() == 123042322);
	}
	SECTION("Radius of second ball is reset to initial value") {
		tbSim.setRadius2(12322989805);
		tbSim.keyPressed('h');
		REQUIRE(tbSim.getRadius2() == 12322989805);
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
	SECTION("Calculate Starting Angle") {
		REQUIRE((pendSim.calculateAngle(0) - M_PI / 18) < 0.000001);
	}
	SECTION("Calculate X Position at Bottom") {
		REQUIRE(pendSim.calculateXPos(0) == 500);
	}
	SECTION("Calculate Y Position at Bottom") {
		REQUIRE(pendSim.calculateYPos(0) == 500);
	}
}

TEST_CASE("Chaotic Pendulum Simulation Test", "[chaotic pendulum]") {
	chaoticPendulum cPendSim;
	cPendSim.setup();
}

TEST_CASE("Mirror and Lens Simulation Test", "[mirror lens]") {
	mirrorLens mirLensSim;
	mirLensSim.setup();
	SECTION("Focal Length is set to initial value") {
		REQUIRE(mirLensSim.getFocalLength == 100);
	}
	SECTION("Object Distance is set to initial value") {
		REQUIRE(mirLensSim.getDistance() == 200);
	}
	SECTION("Object Height is set to initial value") {
		REQUIRE(mirLensSim.getHeight() == 100);
	}
}

TEST_CASE("Buoyancy Simulation Test", "[buoyancy]") {
	Buoyancy buoSim;
	buoSim.setup();
}