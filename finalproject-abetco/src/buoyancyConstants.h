#ifndef BUOYANCY_CONSTANTS_H
#define BUOYANCY_CONSTANTS_H

namespace BuoyancyConstants {
	/*Parameters*/
	const float kHeightLow = 5;
	const float kHeightStart = 10;
	const float kHeightHigh = 100;
	const float kWidthLow = 5;
	const float kWidthStart = 10;
	const float kWidthHigh = 100;
	const float kDensityLow = 0.5;
	const float kDensityStart = 1;
	const float kDensityHigh = 1.5;
	/*Setup*/
	const float kGravity = 10;
	const float kFPS = 60;
	/*Box Physics*/
	const float kDensity = 3.0;
	const float kFloat = 0.53;
	const float kFriction = 0.9;
	/*Box*/
	const float kBoxWidthLocation = 0.5;
	const float kBoxHeightLocation = 0.6;
	const int kBoxColor = 0x000000;
	const float kScalingFactor = 500;
	/*Water*/
	const float kWaterLevelHeight = 0.75;
	const int kWaterColor = 0x0000ff;
}

#endif