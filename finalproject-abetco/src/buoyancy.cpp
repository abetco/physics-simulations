#include "buoyancy.h"

void Buoyancy::setup() {
	parameters_.setName("Parameters");
	parameters_.add(height_.set("Height of Box", 10, 5, 100));
	parameters_.add(width_.set("Width of Box", 10, 5, 100));
	parameters_.add(density_.set("Density of Fluid", 1, 0.5, 1.5));
	gui_.setup(parameters_);
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.setFPS(60.0);
	box.setPhysics(3.0, 0.53, 0.9);
	box.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() * 3 / 5, height_, width_);
}
		
void Buoyancy::update() {	
	box2d.update();
	box.addRepulsionForce(box.getPosition() + ofVec2f(0, box.getHeight() / 2), calculateBuoyancyForce());
}

void Buoyancy::draw() {
	gui_.draw();
	ofSetHexColor(0x0000ff);
	ofFill();
	ofDrawRectangle(0, ofGetWindowHeight() * 3 / 4, ofGetWindowWidth(), ofGetWindowHeight() / 4);
	ofSetHexColor(0x000000);
	box.draw();
}

void Buoyancy::keyPressed(int key) {
	if (key == 'r') {
		box.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() * 3 / 5, height_, width_);
	}
}

float Buoyancy::calculateBuoyancyForce() {
	/*if (box.getVelocity().y < 0) {
		return 0;
	}
	else */if (box.getPosition().y > ofGetHeight() * 3 / 4 + 10 && box.getPosition().y <= ofGetHeight() * 3 / 4 + 10) {
		return density_ * ((box.getPosition().y + 10) - ofGetHeight() * 3 / 4) / box.getPosition().y * box2d.getGravity().length() * 0.5;
	}
	else if (box.getPosition().y > ofGetHeight() * 3 / 4 + 10) {
		return density_ * box2d.getGravity().length() * 0.5;
	}
	return 0;
}