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
	/*Draws the center axis*/
	void drawAxis();
	/*Draws the instructions*/
	void drawInstructions();

	/*Draws the object*/
	void drawObject();

	/*Draws the image
	@param: image_distance is the distance of the image from the mirror
	@param: image_height is how tall the image is*/
	void drawImage(float image_distance, float image_height);

	/*Draws the rays of light which shows the correlation between object and image
	@param image_distance: distance of the image from the mirror
	@param image_height: height of the image above the axis*/
	void drawRays(float image_distance, float image_height);

	/*Calculates the distance of the image in the mirror
	@return: image distance, where a positive distance means the image is to the left of the mirror, on the same side of the object*/
	float calculateImageDistance();

	/*Calculates the image height using the magnification equation and the image distance
	@param: image_distance is the distance of the image from the mirror
	@return: the image height which is how tall the image is*/
	float calculateImageHeight(float image_distance);

	/*Calculates the point on the mirror at which the ray of light parallel to the axis strikes
	@return the x coordinate of the point on the mirror in which the ray strikes*/
	float calculateMirrorPoint();

	mirrorLens();

	float getFocalLength();
	float getDistance();
	float getHeight();

private:
	ofTrueTypeFont myFont;
	ofParameter<float> focal_length_, distance_, height_;
	ofxPanel gui_;
	ofParameterGroup parameters_;
};

#endif