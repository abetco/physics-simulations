#include "buoyancy.h"

void Buoyancy::setup() {
	myFont.load("Cabin-Regular.ttf", BuoyancyConstants::kFontSize);
	parameters_.setName("Parameters");
	parameters_.add(height_.set("Height of Box", BuoyancyConstants::kHeightStart, BuoyancyConstants::kHeightLow, BuoyancyConstants::kHeightHigh));
	parameters_.add(width_.set("Width of Box", BuoyancyConstants::kWidthStart, BuoyancyConstants::kWidthLow, BuoyancyConstants::kWidthHigh));
	parameters_.add(density_.set("Density of Fluid", BuoyancyConstants::kDensityStart, BuoyancyConstants::kDensityLow, BuoyancyConstants::kDensityHigh));
	gui_.setup(parameters_);
	box2d.init();
	box2d.setGravity(0, BuoyancyConstants::kGravity);
	box2d.setFPS(BuoyancyConstants::kFPS);
	box.setPhysics(BuoyancyConstants::kDensity, BuoyancyConstants::kFloat, BuoyancyConstants::kFriction);
	box.setup(box2d.getWorld(), ofGetWidth() * BuoyancyConstants::kBoxWidthLocation, ofGetHeight() * BuoyancyConstants::kBoxHeightLocation, height_, width_);
}
		
void Buoyancy::update() {	
	box2d.update();
	box.addRepulsionForce(box.getPosition() + ofVec2f(0, box.getHeight() / 2), calculateBuoyancyForce());
}

void Buoyancy::draw() {
	gui_.draw();
	drawWater();
	drawBox();
	drawSetup();
}

void Buoyancy::drawSetup() {
	ofSetHexColor(BuoyancyConstants::kBoxColor);
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	myFont.drawString(info, 10, ofGetHeight() / 3);
	string title = "Buoyancy Simulation";
	myFont.drawString(title, ofGetWidth() / 2 - 100, 50);
}

void Buoyancy::drawBox() {
	ofSetHexColor(BuoyancyConstants::kBoxColor);
	box.draw();
}

void Buoyancy::drawWater() {
	ofSetHexColor(BuoyancyConstants::kWaterColor);
	ofFill();
	ofDrawRectangle(0, ofGetWindowHeight() * BuoyancyConstants::kWaterLevelHeight, ofGetWindowWidth(), ofGetWindowHeight() * (1 - BuoyancyConstants::kWaterLevelHeight));
}

void Buoyancy::keyPressed(int key) {
	if (key == 'r') {
		box.setup(box2d.getWorld(), ofGetWidth() * BuoyancyConstants::kBoxWidthLocation, ofGetHeight() * BuoyancyConstants::kBoxHeightLocation, height_, width_);
	}
}

float Buoyancy::calculateBuoyancyForce() {
	if (box.getPosition().y > ofGetHeight() * BuoyancyConstants::kWaterLevelHeight + height_ && box.getPosition().y <= ofGetHeight() * BuoyancyConstants::kWaterLevelHeight + height_) {
		return density_ * box.getHeight() * box.getWidth() / ((box.getPosition().y + height_) - ofGetHeight() * BuoyancyConstants::kWaterLevelHeight) / 
			box.getPosition().y * box2d.getGravity().length() / BuoyancyConstants::kScalingFactor;
	}
	else if (box.getPosition().y > ofGetHeight() * BuoyancyConstants::kWaterLevelHeight + height_) {
		return density_ * box.getHeight() * box.getWidth() * box2d.getGravity().length() / BuoyancyConstants::kScalingFactor;
	}
	return 0;
}