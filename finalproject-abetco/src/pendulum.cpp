#include "pendulum.h"

Pendulum::Pendulum() {
}

void Pendulum::setup() {
	parameters_.setName("Parameters");
	parameters_.add(radius_.set("Radius", 10, 1, 20));
	parameters_.add(gravity_.set("Gravity", 10, 1, 100));
	parameters_.add(angle_.set("Starting Angle", -10, -1, -100));
	gui_.setup(parameters_);
}

void Pendulum::update() {
}

void Pendulum::draw() {
	gui_.draw();
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of a Simple Pendulum";
	ofDrawBitmapString(title, ofGetWidth() / 2 - 50, 10);

	ofPoint pt;
	pt.set
}

//void Pendulum::drawObj(float xpos, float ypos) {
//	ofPoint pt;
//	pt.set()
//}

void Pendulum::keyPressed(int key) {
}