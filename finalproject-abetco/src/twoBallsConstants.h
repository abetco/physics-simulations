#ifndef TWO_BALLS_CONSTANTS_H
#define TWO_BALLS_CONSTANTS_H

namespace TwoBallsConstants {
	/*Setup*/
	const int kFontSize = 18;
	const int kBackground = 0xffffff;
	const int kTextColor = 0x000000;
	const float kFPS = 60.0;
	const float kGravity = 10;
	/*Velocity of Balls Parameters*/
	const float kXLeftVelLow = 1;
	const float kXRightVelLow = -1;
	const float kXLeftVelStart = 10;
	const float kXRightVelStart = -10;
	const float kXLeftVelHigh = 100;
	const float kXRightVelHigh = -100;
	const float kYVelLow = -1;
	const float kYVelStart = -10;
	const float kYVelHigh = -100;
	/*Radius of Balls Parameters*/
	const float kRadiusLow = 10;
	const float kRadiusStart = 15;
	const float kRadiusHigh = 100;
	/*Ball Physics*/
	const float kDensity = 3.0;
	const float kFloat = 0.53;
	const float kFriction = 0.9;
	/*Circle Color*/
	const int kCircleColor = 0xb3ffe0;
}

#endif