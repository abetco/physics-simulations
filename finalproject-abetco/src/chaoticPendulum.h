#ifndef CHAOTIC_PENDULUM_H
#define CHAOTIC_PENDULUM_H
#define _USE_MATH_DEFINES

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <chaoticPendulumConstants.h>
#include <math.h> 
#include <cmath>

class chaoticPendulum {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	float calculatePeriod();

	/*Calculate the x position of the pendulum object based on the angle of the string with the vertical and pivot position
	@param angle: angle of the pendulum
	@param xpivot: x coordinate of the pivot
	@param length: length of the pendulum string
	@return the x position of the pendulum object*/
	float calculateXPos(float angle, float xpivot, float length);

	/*Calculate the y position of the pendulum object based on the angle of the string with the vertical and pivot position
	@param angle: angle of the pendulum
	@param ypivot: y coordinate of the pivot
	@param length: length of the pendulum string
	@return the y position of the pendulum object*/
	float calculateYPos(float angle, float ypivot, float length);

	/*Calculate the angle of the pendulum object based on the time elapsed
	@param time: time passed since beginning of simulation or reset
	@param angle: initial angle of the pendulm
	@param length: length of the pendulum string
	@return the angle of the pendulum with the vertical
	*/
	float calculateAngle(float time, float angle, float length);

	/*Draws the string and circle representing the pendulum
	@param xpos: X coordinate of the pendulum object
	@param ypos: Y coordinate of the pendulum object
	@param xpivot: X coordinate of the pivot
	@param ypivot: Y coordinate of the pivot
	*/
	void drawObj(float xpos, float ypos, float xpivot, float ypivot);

	/*Draws the period formula and time*/
	void drawPeriod(float period);

	chaoticPendulum();

	float getAngle1();
	float getLength1();
	float getAngle2();
	float getLength2();
	float getGravity();
	float getStartTime();

private:
	ofTrueTypeFont myFont;
	float start_time_;
	ofParameter<float> length1_, gravity_, angle1_, length2_, angle2_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d box2d_;
};

#endif