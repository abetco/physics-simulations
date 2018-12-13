#include "mirrorLens.h"

mirrorLens::mirrorLens() {
}

void mirrorLens::setup() {
	myFont.load("Cabin-Regular.ttf", MirrorLensConstants::kFontSize);
	draw_rays_ = false;
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
	ofSetHexColor(MirrorLensConstants::kColorBlack);
	drawSetup();
	drawObject();
	float image_distance = calculateImageDistance();
	float image_height = calculateImageHeight(image_distance);
	drawImage(image_distance, image_height);
	if (draw_rays_) {
		drawRays(image_distance, image_height);
	}
}

void mirrorLens::drawSetup() {
	drawMirror();
	drawAxis();
	drawInstructions();
}

void mirrorLens::drawInstructions() {
	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press the [f] key if you would like to display the rays\n";
	myFont.drawString(info, 10, ofGetHeight() / 4 - 50);
	string title = "Mirror Simulation";
	myFont.drawString(title, ofGetWidth() / 2 - 100, 50);
}

void mirrorLens::drawMirror() {
	ofPath path;
	path.arc(MirrorLensConstants::kCenterX - 2 * focal_length_, MirrorLensConstants::kCenterY, 0, 2 * focal_length_, 
		2 * focal_length_, -MirrorLensConstants::kMirrorAngle, MirrorLensConstants::kMirrorAngle);
	path.setFilled(false);
	path.setStrokeWidth(MirrorLensConstants::kStrokeWidth);
	path.setStrokeHexColor(MirrorLensConstants::kColorBlack);
	path.setArcResolution(MirrorLensConstants::kArcRes);
	path.draw();
	ofPath cover;
	cover.moveTo(MirrorLensConstants::kCenterX - 2 * focal_length_, MirrorLensConstants::kCenterY);
	cover.lineTo(MirrorLensConstants::kCenterX - 2 * focal_length_ + 2 * focal_length_ * 
		cos(MirrorLensConstants::kMirrorAngle * M_PI / 180), 
		MirrorLensConstants::kCenterY - 2 * focal_length_ * sin(MirrorLensConstants::kMirrorAngle * M_PI / 180));
	cover.setFilled(false);
	cover.setStrokeWidth(MirrorLensConstants::kStrokeWidth);
	cover.setStrokeHexColor(MirrorLensConstants::kColorWhite);
	cover.draw();
}

void mirrorLens::drawAxis() {
	ofPolyline line;
	ofPoint pt;
	pt.set(ofGetWindowWidth(), MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(0, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	line.draw();
}

void mirrorLens::drawObject() {
	ofPolyline line;
	ofPoint pt;
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY - height_);
	line.addVertex(pt);
	line.draw();
	ofDrawCircle(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY - height_, MirrorLensConstants::kCircleRad);
}

void mirrorLens::drawImage(float image_distance, float image_height) {
	ofPolyline line;
	ofPoint pt;
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY - image_height);
	line.addVertex(pt);
	line.draw();
	ofDrawCircle(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY - image_height, MirrorLensConstants::kCircleRad);
}

void mirrorLens::drawRays(float image_distance, float image_height) {
	float mirror_distance = calculateMirrorPoint();
	ofPolyline line;
	ofPoint pt;
	ofSetHexColor(MirrorLensConstants::kColorYellow);
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY - height_);
	line.addVertex(pt);
	if (focal_length_ > 0) {
		pt.set(MirrorLensConstants::kCenterX - 2 * focal_length_ + mirror_distance, MirrorLensConstants::kCenterY - height_);
	}
	else {
		pt.set(MirrorLensConstants::kCenterX - 2 * focal_length_ - mirror_distance, MirrorLensConstants::kCenterY - height_);
	}
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY - image_height);
	line.addVertex(pt);
	line.draw();
	line.clear();
	pt.set(MirrorLensConstants::kCenterX - distance_, MirrorLensConstants::kCenterY - height_);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX, MirrorLensConstants::kCenterY);
	line.addVertex(pt);
	pt.set(MirrorLensConstants::kCenterX - image_distance, MirrorLensConstants::kCenterY - image_height);
	line.addVertex(pt);
	line.draw();
}

float mirrorLens::calculateMirrorPoint() {
	return sqrt(pow(2 * focal_length_, 2) - pow(height_, 2));
}

void mirrorLens::keyPressed(int key) {
	if (key == 'f') {
		draw_rays_ = true;
	}
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