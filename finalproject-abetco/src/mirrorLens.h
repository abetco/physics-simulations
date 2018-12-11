#ifndef MIRROR_LENS_H
#define MIRROR_LENS_H
#define _USE_MATH_DEFINES

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include <math.h> 
#include <cmath>
#include <mirrorLensConstants.h>

class mirrorLens {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	/*Draw the setup of the mirror simulation, which includes the mirror itself and the line at which the object and image are on*/
	void drawSetup();

	/*Draws the mirror*/
	void drawMirror();
	/*Draws the focus*/
	void drawFocus();
	/*Draws the center axis*/
	void drawAxis();

	/*Draws the object*/
	void drawObject();

	/*Draws the image
	@param: image_distance is the distance of the image from the mirror
	@param: image_height is how tall the image is*/
	void drawImage(float image_distance, float image_height);

	/*Calculates the distance of the image in the mirror
	@return: image distance, where a positive distance means the image is to the left of the mirror, on the same side of the object*/
	float calculateImageDistance();

	/*Calculates the image height using the magnification equation and the image distance
	@param: image_distance is the distance of the image from the mirror
	@return: the image height which is how tall the image is*/
	float calculateImageHeight(float image_distance);

	mirrorLens();

	float getFocalLength();
	float getDistance();
	float getHeight();

private:
	ofParameter<float> focal_length_, distance_, height_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
};

#endif