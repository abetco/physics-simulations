#ifndef TWOBALLS_H
#define TWOBALLS_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class twoBalls {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	twoBalls();

private:
	ofParameter<float> x_vel1_, y_vel1_, radius1_, x_vel2_, y_vel2_, radius2_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d                                 box2d_;   // the box2d world
	vector     <shared_ptr<ofxBox2dCircle> > circles_; // default box2d circles
};

#endif