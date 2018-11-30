#ifndef PENDULUM_H
#define PENDULUM_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class Pendulum {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	/*float calculatePeriod();
	float calculateTension();
	float calculateXPos(float angle);
	float calculateYPos(float angle);
	float calculateAngle(float time);*/

	/*void drawString(float xpos, float ypos);
	void drawObj(float xpos, float ypos);
	void drawTension(float xpos, float ypos);
	void drawPeriod();*/


	ofParameter<float> radius, gravity, angle;
	ofxPanel gui;
	ofParameterGroup parameters;
	ofPolyline                              string;
	ofxBox2d                                 box2d;   // the box2d world

	Pendulum();

private:
};

#endif