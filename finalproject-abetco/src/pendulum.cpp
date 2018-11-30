#include "pendulum.h"

Pendulum::Pendulum() {
}

void Pendulum::setup() {
	parameters.setName("Parameters");
	parameters.add(radius.set("Radius", 10, 1, 20));
	parameters.add(gravity.set("Gravity", 10, 1, 100));
	parameters.add(angle.set("Starting Angle", -10, -1, -100));
	gui.setup(parameters);
}

void Pendulum::update() {
}

void Pendulum::draw() {
	gui.draw();
	std::string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 10, ofGetHeight() / 3);

	std::string title = "Simulation of a Simple Pendulum";
	ofDrawBitmapString(title, ofGetWidth() / 2 - 50, 10);
}

void Pendulum::keyPressed(int key) {
}