#ifndef BUOYANCY_H
#define BUOYANCY_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class Buoyancy {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	float calculateBuoyancyForce();

	ofParameter<float> width_,  height_, density_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d;
	ofxBox2dRect box;
};

#endif