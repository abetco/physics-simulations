#include "chaoticPendulum.h"

chaoticPendulum::chaoticPendulum() {
}

void chaoticPendulum::setup() {
	parameters_.setName("Parameters");
	parameters_.add(length_.set("String Length", 400, 100, 700));
	parameters_.add(gravity_.set("Gravity", 10, 1, 100));
	parameters_.add(angle_.set("Starting Angle", 10, 1, 60));
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
	ofDrawBitmapString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of a Simple Pendulum";
	ofDrawBitmapString(title, ofGetWidth() / 2 - 50, 10);

	float curr_angle = calculateAngle((ofGetElapsedTimeMillis() - start_time_) / 1000);
	float xpos = calculateXPos(curr_angle);
	float ypos = calculateYPos(curr_angle);
	drawObj(xpos, ypos);
	drawPeriod(calculatePeriod());
}

float chaoticPendulum::calculateAngle(float time) {
	return angle_ * M_PI / 180 * cos(sqrt(gravity_ / length_) * time);
}

float chaoticPendulum::calculateXPos(float angle) {
	return kXPivot + length_ * sin(angle);
}
float chaoticPendulum::calculateYPos(float angle) {
	return kYPivot + length_ * cos(angle);
}

float chaoticPendulum::calculatePeriod() {
	return 2 * M_PI * sqrt(length_ / gravity_);
}

void chaoticPendulum::drawObj(float xpos, float ypos) {
	ofPolyline pend_string;
	ofPoint pt;
	pt.set(kXPivot, kYPivot);
	pend_string.addVertex(pt);
	pt.set(xpos, ypos);
	pend_string.addVertex(pt);
	pend_string.draw();
	ofDrawCircle(xpos, ypos, 5);
}

void chaoticPendulum::drawPeriod(float period) {
	string pend_period = std::to_string(period);
	pend_period = "Period = 2pi * sqrt(L/g) = " + pend_period;
	ofDrawBitmapString(pend_period, ofGetWidth() / 2 - 50, 100);
}

void chaoticPendulum::keyPressed(int key) {
	if (key == 'r') {
		start_time_ = ofGetElapsedTimeMillis();
	}
}

float chaoticPendulum::getAngle() {
	return angle_;
}

float chaoticPendulum::getGravity() {
	return gravity_;
}

float chaoticPendulum::getLength() {
	return length_;
}

float chaoticPendulum::getStartTime() {
	return start_time_;
}