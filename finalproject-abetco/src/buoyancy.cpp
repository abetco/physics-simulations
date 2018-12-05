#include "buoyancy.h"

void Buoyancy::setup() {
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.setFPS(60.0);
	box.setPhysics(3.0, 0.53, 0.9);
	box.setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, 10, 10);
}

void Buoyancy::update() {
	box2d.update();
	box.addRepulsionForce(box.getWidth(), box.getHeight() + 10, 1000 * calculateBuoyancyForce());
}

void Buoyancy::draw() {
	box.draw();
	ofPolyline water_level;
	ofPoint pt;
	pt.set(0, ofGetHeight() * 3 / 4);
	water_level.addVertex(pt);
	pt.set(ofGetWidth(), ofGetHeight() * 3 / 4);
	water_level.addVertex(pt);
	water_level.draw();

}

void Buoyancy::keyPressed(int key) {
	if (key == 'r') {
		box.setPosition(ofGetWidth() / 2, ofGetHeight() / 2);
	}
}

float Buoyancy::calculateBuoyancyForce() {
	if (box.getHeight() > ofGetHeight() * 3 / 4 + 10 && box.getHeight() <= ofGetHeight() * 3 / 4 + 10) {
		return ((box.getHeight() + 10) - ofGetHeight() * 3 / 4) / box.getHeight() * box2d.getGravity().length() * 0.5;
	}
	else if (box.getHeight() > ofGetHeight() * 3 / 4 + 10) {
		return box2d.getGravity().length() * 0.5;
	}
	return 0;
}