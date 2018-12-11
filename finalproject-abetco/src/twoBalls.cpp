#include "twoBalls.h"

twoBalls::twoBalls() {
}

void twoBalls::setup() {
	myFont.load("Cabin-Regular.ttf", TwoBallsConstants::kFontSize);
	ofSetBackgroundColorHex(TwoBallsConstants::kBackground);
	box2d_.init();
	box2d_.setGravity(0, TwoBallsConstants::kGravity);
	box2d_.createGround();
	box2d_.setFPS(TwoBallsConstants::kFPS);
	parameters_.setName("Parameters");
	parameters_.add(x_vel1_.set("X Velocity Ball 1", TwoBallsConstants::kXLeftVelStart, TwoBallsConstants::kXLeftVelLow, TwoBallsConstants::kXLeftVelHigh));
	parameters_.add(y_vel1_.set("Y Velocity Ball 1", TwoBallsConstants::kYVelStart, TwoBallsConstants::kYVelLow, TwoBallsConstants::kYVelHigh));
	parameters_.add(x_vel2_.set("X Velocity Ball 2", TwoBallsConstants::kXRightVelStart, TwoBallsConstants::kXRightVelLow, TwoBallsConstants::kXRightVelHigh));
	parameters_.add(y_vel2_.set("Y Velocity Ball 2", TwoBallsConstants::kYVelStart, TwoBallsConstants::kYVelLow, TwoBallsConstants::kYVelHigh));
	parameters_.add(radius1_.set("Radius Ball 1", TwoBallsConstants::kRadiusStart, TwoBallsConstants::kRadiusLow, TwoBallsConstants::kRadiusHigh));
	parameters_.add(radius2_.set("Radius Ball 2", TwoBallsConstants::kRadiusStart, TwoBallsConstants::kRadiusLow, TwoBallsConstants::kRadiusHigh));
	gui_.setup(parameters_);
	auto circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(TwoBallsConstants::kDensity, TwoBallsConstants::kFloat, TwoBallsConstants::kFriction);
	circle.get()->setup(box2d_.getWorld(), radius1_, ofGetHeight() - radius1_, radius1_);
	circle.get()->setVelocity(x_vel1_, y_vel1_);
	circles_.push_back(circle);
	circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(TwoBallsConstants::kDensity, TwoBallsConstants::kFloat, TwoBallsConstants::kFriction);
	circle.get()->setup(box2d_.getWorld(), ofGetWidth() - radius2_, ofGetHeight() - radius2_, radius2_);
	circle.get()->setVelocity(x_vel2_, y_vel2_);
	circles_.push_back(circle);
}

void twoBalls::update() {
	box2d_.update();
}

void twoBalls::draw() {
	gui_.draw();
	for (int i = 0; i < circles_.size(); i++) {
		ofFill();
		ofSetHexColor(TwoBallsConstants::kCircleColor);
		circles_[i].get()->draw();
	}

	box2d_.drawGround();

	ofSetHexColor(TwoBallsConstants::kTextColor);
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	myFont.drawString(info, 10, ofGetHeight() / 3);
	string title = "Simulation of Two Balls";
	myFont.drawString(title, ofGetWidth() / 2 - 100, 50);
}

void twoBalls::keyPressed(int key) {
	ofVec2f pos_reset1(radius1_, ofGetHeight() - radius1_);
	ofVec2f vel_reset1(x_vel1_, y_vel1_);
	ofVec2f pos_reset2(ofGetWidth() - radius2_, ofGetHeight() - radius2_);
	ofVec2f vel_reset2(x_vel2_, y_vel2_);
	if (key == 'r') {
		circles_[0].get()->setPosition(pos_reset1);
		circles_[0].get()->setVelocity(vel_reset1);
		circles_[0].get()->setRadius(radius1_);
		circles_[1].get()->setPosition(pos_reset2);
		circles_[1].get()->setVelocity(vel_reset2);
		circles_[1].get()->setRadius(radius2_);
	}
}

float twoBalls::getXVel1() {
	return x_vel1_;
}
float twoBalls::getXVel2() {
	return x_vel2_;
}
float twoBalls::getYVel1() {
	return y_vel1_;
}
float twoBalls::getYVel2() {
	return y_vel2_;
}
float twoBalls::getRadius1() {
	return radius1_;
}
float twoBalls::getRadius2() {
	return radius2_;
}

void twoBalls::setXVel1(float newValue) {
	x_vel1_ = newValue;
}
void twoBalls::setYVel1(float newValue) {
	y_vel1_ = newValue;
}
void twoBalls::setXVel2(float newValue) {
	x_vel2_ = newValue;
}
void twoBalls::setYVel2(float newValue) {
	y_vel2_ = newValue;
}
void twoBalls::setRadius1(float newValue) {
	radius1_ = newValue;
}
void twoBalls::setRadius2(float newValue) {
	radius2_ = newValue;
}