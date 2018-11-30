#ifndef PENDULUM_H
#define PENDULUM_H
#define _USE_MATH_DEFINES

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <math.h> 
#include <cmath>

class Pendulum {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	/*float calculatePeriod();
	float calculateTension();*/
	float calculateXPos(float angle);
	float calculateYPos(float angle);
	float calculateAngle(float time);
	void drawObj(float xpos, float ypos);
	/*void drawTension(float xpos, float ypos);
	void drawPeriod();*/

	Pendulum();

private:
	const float kXPivot = 500;
	const float kYPivot = 100;
	float start_time_;
	ofParameter<float> length_, gravity_, angle_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d                                 box2d_;   // the box2d world
};

#endif