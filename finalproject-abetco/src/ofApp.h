#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

#include "twoBalls.h"
#include "pendulum.h"
#include "chaoticPendulum.h"
#include "buoyancy.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void tbSimButtonPressed();
		void pendSimButtonPressed();
		void cPendSimButtonPressed();
		void buoSimButtonPressed();

		twoBalls tbSim;
		Pendulum pendSim;
		chaoticPendulum cPendSim;
		Buoyancy buoSim;

		enum Simulation {TwoBalls, Pendulum, ChaoticPendulum, Buoyancy};
		Simulation sim;
		

		ofxPanel gui;
		ofxButton tbSimButton;
		ofxButton pendSimButton;
		ofxButton cPendSimButton;
		ofxButton buoSimButton;
};
