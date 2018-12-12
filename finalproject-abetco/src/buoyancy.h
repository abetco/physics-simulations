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
	void keyPressed(int key);

	/*Draws the instructions and title*/
	void drawSetup();
	/*Draws the box*/
	void drawBox();
	/*Draws the water*/
	void drawWater();
	
	/*Calculates the buoyancy force based on how much of the box is in the water
	@return a float of the buoyancy force to be exerted on the box*/
	float calculateBuoyancyForce();

	ofTrueTypeFont myFont;
	ofParameter<float> width_,  height_, density_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d;
	ofxBox2dRect box;
};

#endif