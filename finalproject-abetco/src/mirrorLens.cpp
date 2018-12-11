#include "mirrorLens.h"

mirrorLens::mirrorLens() {
}

void mirrorLens::setup() {
	parameters_.setName("Parameters");
	parameters_.add(focal_length_.set("Focal Length", MirrorLensConstants::kFocalStart, MirrorLensConstants::KFocalLow, MirrorLensConstants::kFocalHigh));
	parameters_.add(distance_.set("Distance", MirrorLensConstants::kDistanceStart, MirrorLensConstants::kDistanceLow, MirrorLensConstants::kDistanceHigh));
	parameters_.add(height_.set("Height of Image", MirrorLensConstants::kHeightStart, MirrorLensConstants::kHeightLow, MirrorLensConstants::kHeightHigh));
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
	pt.set(MirrorLensConstants::kCenterX, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(0, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	line.draw();
	ofPath path;
	path.arc(MirrorLensConstants::kCenterX - 2 * focal_length_, MirrorLensConstants::kCenterY, 0, 2 * focal_length_, 2 * focal_length_, -45, 45);
	path.setFilled(false);
	path.setStrokeWidth(1);
	path.setStrokeHexColor(0x000000);
	path.setArcResolution(200);
	path.draw();
	ofPath cover;
	cover.moveTo(MirrorLensConstants::kCenterX - 2 * focal_length_, MirrorLensConstants::kCenterY);
	cover.lineTo(MirrorLensConstants::kCenterX - 2 * focal_length_ + 2 * focal_length_ * cos(45 * M_PI / 180), MirrorLensConstants::kCenterY - 2 * focal_length_ * sin(45 * M_PI / 180));
	cover.setFilled(false);
	cover.setStrokeWidth(1);
	cover.setStrokeHexColor(0xffffff);
	cover.draw();
}

void mirrorLens::drawObject() {
	ofPolyline line;
	ofPoint pt;
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY - height_);
	line.addVertex(pt);
	line.draw();
}

void mirrorLens::drawImage(float image_distance, float image_height) {
	ofPolyline line;
	ofPoint pt;
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY - image_height);
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