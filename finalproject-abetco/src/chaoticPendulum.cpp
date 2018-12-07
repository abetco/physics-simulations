#include "chaoticPendulum.h"

chaoticPendulum::chaoticPendulum() {
}

void chaoticPendulum::setup() {
	myFont.load("Cabin-Regular.ttf", 18);
	parameters_.setName("Parameters");
	parameters_.add(length1_.set("String Length 1", 200, 50, 400));
	parameters_.add(angle1_.set("Starting Angle 1", 10, 1, 60));
	parameters_.add(length2_.set("String Length 2", 200, 50, 400));
	parameters_.add(angle2_.set("Starting Angle 2", 10, 1, 180));
	parameters_.add(gravity_.set("Gravity", 10, 1, 100));
	gui_.setup(parameters_);
	start_time_ = 0;
}

void chaoticPendulum::update() {
}

void chaoticPendulum::draw() {
	gui_.draw();
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	ofSetHexColor(0x444342);
	myFont.drawString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of a Chaotic Pendulum";
	myFont.drawString(title, ofGetWidth() / 2 -100, 50);

	float curr_angle1 = calculateAngle((ofGetElapsedTimeMillis() - start_time_) / 1000, angle1_, length1_);
	float xpos1 = calculateXPos(curr_angle1, kXPivot, length1_);
	float ypos1 = calculateYPos(curr_angle1, kYPivot, length1_);
	drawObj(xpos1, ypos1, kXPivot, kYPivot);
	float curr_angle2 = calculateAngle((ofGetElapsedTimeMillis() - start_time_) / 1000, angle2_, length2_);
	float xpos2 = calculateXPos(curr_angle2, xpos1, length2_);
	float ypos2 = calculateYPos(curr_angle2, ypos1, length2_);
	drawObj(xpos2, ypos2, xpos1, ypos1);

	drawPeriod(calculatePeriod());
}

float chaoticPendulum::calculateAngle(float time, float angle, float length) {
	return angle * M_PI / 180 * cos(sqrt(gravity_ / length) * time);
}

float chaoticPendulum::calculateXPos(float angle, float xpivot, float length) {
	return xpivot + length * sin(angle);
}
float chaoticPendulum::calculateYPos(float angle, float ypivot, float length) {
	return ypivot + length * cos(angle);
}

float chaoticPendulum::calculatePeriod() {
	return 2 * M_PI * sqrt(length1_ / gravity_);
}

void chaoticPendulum::drawObj(float xpos, float ypos, float xpivot, float ypivot) {
	ofPolyline pend_string;
	ofPoint pt;
	pt.set(xpivot, ypivot);
	pend_string.addVertex(pt);
	pt.set(xpos, ypos);
	pend_string.addVertex(pt);
	pend_string.draw();
	ofDrawCircle(xpos, ypos, 5);
}

void chaoticPendulum::drawPeriod(float period) {
	string pend_period = std::to_string(period);
	pend_period = "Period = 2pi * sqrt(L/g) = " + pend_period;
	myFont.drawString(pend_period, ofGetWidth() / 2 - 50, 100);
}

void chaoticPendulum::keyPressed(int key) {
	if (key == 'r') {
		start_time_ = ofGetElapsedTimeMillis();
	}
}

float chaoticPendulum::getAngle() {
	return angle1_;
}

float chaoticPendulum::getGravity() {
	return gravity_;
}

float chaoticPendulum::getLength() {
	return length1_;
}

float chaoticPendulum::getStartTime() {
	return start_time_;
}