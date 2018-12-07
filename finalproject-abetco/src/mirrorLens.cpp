#include "mirrorLens.h"

mirrorLens::mirrorLens() {
}

void mirrorLens::setup() {
	parameters_.setName("Parameters");
	parameters_.add(focal_length_.set("Focal Length", 100, -300, 300));
	parameters_.add(distance_.set("Distance", 200, 100, 600));
	parameters_.add(height_.set("Height of Image", 100, 50, 150));
	gui_.setup(parameters_);
}

void mirrorLens::update() {
	
}

void mirrorLens::draw() {
	gui_.draw();
	drawSetup();
	drawObject();
	float image_distance = calculateImageDistance();
	float image_height = calculateImageHeight(image_distance);
	drawImage(image_distance, image_height);

}

void mirrorLens::drawSetup() {
	ofPolyline line;
	ofPoint pt;
	pt.set(kCenterX, kCenterY);
	line.addVertex(pt);
	pt.set(0, kCenterY);
	line.addVertex(pt);
	line.draw();
	
}

void mirrorLens::drawObject() {
	ofPolyline line;
	ofPoint pt;
	pt.set(kCenterX - distance_, kCenterY);
	line.addVertex(pt);
	pt.set(kCenterX - distance_, kCenterY - height_);
	line.addVertex(pt);
	line.draw();
}

void mirrorLens::drawImage(float image_distance, float image_height) {
	ofPolyline line;
	ofPoint pt;
	pt.set(kCenterX - image_distance, kCenterY);
	line.addVertex(pt);
	pt.set(kCenterX - image_distance, kCenterY - image_height);
	line.addVertex(pt);
	line.draw();
}

void mirrorLens::keyPressed(int key) {
	
	
}

float mirrorLens::calculateImageDistance() {
	return 1 / (1 / focal_length_ - 1 / distance_);
}

float mirrorLens::calculateImageHeight(float image_distance) {
	return -(image_distance / distance_) * height_;
}

float mirrorLens::getFocalLength() {
	return focal_length_;
}
float mirrorLens::getDistance() {
	return distance_;
}
float mirrorLens::getHeight() {
	return height_;
}