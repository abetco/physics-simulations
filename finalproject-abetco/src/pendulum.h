#ifndef PENDULUM_H
#define PENDULUM_H
#define _USE_MATH_DEFINES

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <pendulumConstants.h>
#include <math.h> 
#include <cmath>

class Pendulum {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	/*Calculates the period of the first pendulum based on the parameters
	@param: period of the pendulum*/
	float calculatePeriod();

	/*Calculate the x position of the pendulum object based on the angle of the string with the vertical
	@param angle: angle of the pendulum
	@return the x position of the pendulum object*/
	float calculateXPos(float angle);

	/*Calculate the y position of the pendulum object based on the angle of the string with the vertical
	@param angle: angle of the pendulum
	@return the y position of the pendulum object*/
	float calculateYPos(float angle);

	/*Calculate the angle of the pendulum object based on the time elapsed
	@param time: time passed since beginning of simulation or reset
	@return the angle of the pendulum with the verticle
	*/
	float calculateAngle(float time);

	/*Draws the string and circle representing the pendulum
	@param xpos: X coordinate of the pendulum object
	@param ypos: Y coordinate of the pendulum object
	*/
	void drawObj(float xpos, float ypos);
	
	/*void drawTension(float xpos, float ypos);*/
	void drawPeriod(float period);

	Pendulum();

	float getAngle();
	float getLength();
	float getGravity();
	float getStartTime();

private:
	ofTrueTypeFont myFont;
	float start_time_;
	ofParameter<float> length_, gravity_, angle_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d_;
};

#endif