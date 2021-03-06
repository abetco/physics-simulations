#ifndef TWO_BALLS_H
#define TWO_BALLS_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <twoBallsConstants.h>

class twoBalls {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	float getXVel1();
	float getXVel2();
	float getYVel1();
	float getYVel2();
	float getRadius1();
	float getRadius2();

	void setXVel1(float newValue);
	void setYVel1(float newValue);
	void setXVel2(float newValue);
	void setYVel2(float newValue);
	void setRadius1(float newValue);
	void setRadius2(float newValue);

	twoBalls();

private:
	ofTrueTypeFont myFont;
	ofParameter<float> x_vel1_, y_vel1_, radius1_, x_vel2_, y_vel2_, radius2_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d                                 box2d_;
	vector     <shared_ptr<ofxBox2dCircle> > circles_;
};

#endif