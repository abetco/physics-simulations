#include "pendulum.h"

Pendulum::Pendulum() {
}

void Pendulum::setup() {
	myFont.load("Cabin-Regular.ttf", 18);
	parameters_.setName("Parameters");
	parameters_.add(length_.set("String Length", PendulumConstants::kLengthStart, PendulumConstants::kLengthLow, PendulumConstants::kLengthHigh));
	parameters_.add(gravity_.set("Gravity", PendulumConstants::kGravityStart, PendulumConstants::kGravityLow, PendulumConstants::kGravityHigh));
	parameters_.add(angle_.set("Starting Angle", PendulumConstants::kAngleStart, PendulumConstants::kAngleLow, PendulumConstants::kAngleHigh));
	gui_.setup(parameters_);
	start_time_ = 0;
}

void Pendulum::update() {
}

void Pendulum::draw() {
	gui_.draw();
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	myFont.drawString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of a Simple Pendulum";
	myFont.drawString(title, ofGetWidth() / 2 - 100, 50);

	float curr_angle = calculateAngle((ofGetElapsedTimeMillis() - start_time_) / 1000);
	float xpos = calculateXPos(curr_angle);
	float ypos = calculateYPos(curr_angle);
	drawObj(xpos, ypos);
	drawPeriod(calculatePeriod());
}

float Pendulum::calculateAngle(float time) {
	return angle_ * M_PI / 180 * cos(sqrt(gravity_ / length_) * time);
}

float Pendulum::calculateXPos(float angle) {
	return PendulumConstants::kXPivot + length_ * sin(angle);
}
float Pendulum::calculateYPos(float angle) {
	return PendulumConstants::kYPivot + length_ * cos(angle);
}

float Pendulum::calculatePeriod() {
	return 2 * M_PI * sqrt(length_ / gravity_);
}

void Pendulum::drawObj(float xpos, float ypos) {
	ofPolyline pend_string;
	ofPoint pt;
	pt.set(PendulumConstants::kXPivot, PendulumConstants::kYPivot);
	pend_string.addVertex(pt);
	pt.set(xpos, ypos);
	pend_string.addVertex(pt);
	pend_string.draw();
	ofDrawCircle(xpos, ypos, 5);
}

void Pendulum::drawPeriod(float period) {
	string pend_period = std::to_string(period);
	pend_period = "Period = 2*pi*sqrt(L/g) = " + pend_period;
	myFont.drawString(pend_period, ofGetWidth() / 2 - 50, 100);
}

void Pendulum::keyPressed(int key) {
	if (key == 'r') {
		start_time_ = ofGetElapsedTimeMillis();
	}
}

float Pendulum::getAngle() {
	return angle_;
}

float Pendulum::getGravity() {
	return gravity_;
}

float Pendulum::getLength() {
	return length_;
}

float Pendulum::getStartTime() {
	return start_time_;
}