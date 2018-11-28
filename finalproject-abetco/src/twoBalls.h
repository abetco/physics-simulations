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

	ofParameter<float> x_vel1, y_vel1, radius1, x_vel2, y_vel2, radius2;
	ofxPanel gui;
	ofParameterGroup parameters;
	ofPolyline                              drawing;         // we draw with this first
	ofxBox2d                                 box2d;   // the box2d world
	vector     <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
	vector     <shared_ptr<ofxBox2dRect> >   boxes;   // defalut box2d rects
	ofxBox2dEdge                            edgeLine;        // the box2d edge/line shape (min 2 points)

	twoBalls();

private:
};

#endif