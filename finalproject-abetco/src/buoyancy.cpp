#include "buoyancy.h"

void Buoyancy::setup() {
	box2d.init();
	box2d.setGravity(10, 0);
	box2d.setFPS(60.0);
	box.setPhysics(3.0, 0.53, 0.9);
	box.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, 10, 10);
}

void Buoyancy::update() {
	box2d.update();
	box.addRepulsionForce(0, 1, calculateBuoyancyForce());
}

void Buoyancy::draw() {
	box.draw();
	ofPolyline water_level;
	ofPoint pt;
	pt.set(0, ofGetHeight() / 4);
	water_level.addVertex(pt);
	pt.set(ofGetWidth(), ofGetHeight() / 4);
	water_level.addVertex(pt);
	water_level.draw();

}

void Buoyancy::keyPressed(int key) {
	if (key == 'r') {
		box.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

float Buoyancy::calculateBuoyancyForce() {
	if (box.getHeight() < ofGetHeight() / 4 + 10 && box.getHeight() >= ofGetHeight() / 4 - 10) {
		return (ofGetHeight() / 4 - (box.getHeight() - 10)) / box.getHeight() * box2d.getGravity * 0.5;
	}
	else if (box.getHeight() < ofGetHeight() / 4 - 10) {
		return box2d.getGravity * 0.5;
	}
	return 0;
}