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

	/*void drawObj(float xpos, float ypos);*/
	/*void drawTension(float xpos, float ypos);
	void drawPeriod();*/


	ofParameter<float> radius_, gravity_, angle_);
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofPolyline                              pend_string_;
	ofxBox2d                                 box2d_;   // the box2d world

	Pendulum();

private:
};

#endif