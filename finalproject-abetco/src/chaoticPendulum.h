#ifndef CHAOTIC_PENDULUM_H
#define CHAOTIC_PENDULUM_H
#define _USE_MATH_DEFINES

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <math.h> 
#include <cmath>

class chaoticPendulum {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	float calculatePeriod();
	/*float calculateTension();*/

	/*Calculate the x position of the pendulum object based on the angle of the string with the vertical
	@param angle: angle of the pendulum
	@return the x position of the pendulum object*/
	float calculateXPos(float angle, float xpivot, float length);

	/*Calculate the y position of the pendulum object based on the angle of the string with the vertical
	@param angle: angle of the pendulum
	@return the y position of the pendulum object*/
	float calculateYPos(float angle, float ypivot, float length);

	/*Calculate the angle of the pendulum object based on the time elapsed
	@param time: time passed since beginning of simulation or reset
	@return the angle of the pendulum with the verticle
	*/
	float calculateAngle(float time, float angle, float length);

	/*Draws the string and circle representing the pendulum
	@param xpos: X coordinate of the pendulum object
	@param ypos: Y coordinate of the pendulum object
	*/
	void drawObj(float xpos, float ypos, float xpivot, float ypivot);

	/*void drawTension(float xpos, float ypos);*/
	void drawPeriod(float period);

	chaoticPendulum();

	float getAngle();
	float getLength();
	float getGravity();
	float getStartTime();

private:
	const float kXPivot = 500;
	const float kYPivot = 120;
	float start_time_;
	ofParameter<float> length1_, gravity_, angle1_, length2_, angle2_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d_;
};

#endif