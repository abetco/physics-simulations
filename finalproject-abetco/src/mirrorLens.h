#ifndef MIRROR_LENS_H
#define MIRROR_LENS_H

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class mirrorLens {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	mirrorLens();

private:
	ofParameter<float> focal_length_, ;
	ofxPanel gui_;
	ofParameterGroup parameters_;
	ofxBox2d                                 box2d_;
	vector     <shared_ptr<ofxBox2dCircle> > circles_;
};

#endif