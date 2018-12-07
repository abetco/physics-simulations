#ifndef MIRROR_LENS_H
#define MIRROR_LENS_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class mirrorLens {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	void drawSetup();
	void drawObject();
	void drawImage(float image_distance, float image_height);

	float calculateImageDistance();
	float calculateImageHeight(float image_distance);

	mirrorLens();

private:
	float kCenterX = 800;
	float kCenterY = 384;
	ofParameter<float> focal_length_, distance_, height_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
};

#endif