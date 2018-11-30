#include "twoBalls.h"

twoBalls::twoBalls() {
}

void twoBalls::setup() {
	box2d_.init();
	box2d_.setGravity(0, 10);
	box2d_.createGround();
	box2d_.setFPS(60.0);
	parameters_.setName("Parameters");
	parameters_.add(x_vel1_.set("X Velocity Ball 1", 10, 1, 100));
	parameters_.add(y_vel1_.set("Y Velocity Ball 1", -10, -1, -100));
	parameters_.add(x_vel2_.set("X Velocity Ball 2", -10, -1, -100));
	parameters_.add(y_vel2_.set("Y Velocity Ball 2", -10, -1, -100));
	parameters_.add(radius1_.set("Radius Ball 1", 15, 10, 100));
	parameters_.add(radius2_.set("Radius Ball 2", 15, 10, 100));
	gui_.setup(parameters_);
	auto circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.0, 0.53, 0.9);
	circle.get()->setup(box2d_.getWorld(), radius1_, ofGetHeight() - radius1_, radius1_);
	circle.get()->setVelocity(x_vel1_, y_vel1_);
	circles_.push_back(circle);
	circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.0, 0.53, 0.9);
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
		ofSetHexColor(0xf6c738);
		circles_[i].get()->draw();
	}

	box2d_.drawGround();

	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of Two Balls";
	ofDrawBitmapString(title, ofGetWidth() / 2 - 50, 10);
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