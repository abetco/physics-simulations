#ifndef BUOYANCY_H
#define BUOYANCY_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <buoyancyConstants.h>

class Buoyancy {
public:
	void setup();
	void update();
	void draw();
	void drawSetup();
	void drawBox();
	void drawWater();
	void keyPressed(int key);
	
	float calculateBuoyancyForce();

	ofTrueTypeFont myFont;
	ofParameter<float> width_,  height_, density_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d;
	ofxBox2dRect box;
};

#endif