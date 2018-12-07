#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

#include "twoBalls.h"
#include "pendulum.h"
#include "chaoticPendulum.h"
#include "buoyancy.h"
#include "mirrorLens.h"


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

		/*Changes the simulation to the two balls simulation if the button is pressed*/
		void tbSimButtonPressed();
		/*Changes the simulation to the pendulum simulation if the button is pressed*/
		void pendSimButtonPressed();
		/*Changes the simulation to the chaotic pendulum simulation if the button is pressed*/
		void cPendSimButtonPressed();
		/*Changes the simulation to the buoyancy simulation if the button is pressed*/
		void buoSimButtonPressed();
		/*Changes the simulation to the mirror and lens simulation if the button is pressed*/
		void mirLensSimButtonPressed();

		twoBalls tbSim;
		Pendulum pendSim;
		chaoticPendulum cPendSim;
		Buoyancy buoSim;
		mirrorLens mirLensSim;

		enum Simulation {TwoBalls, Pendulum, ChaoticPendulum, Buoyancy, MirrorLens};
		Simulation sim;
		

		ofxPanel gui;
		ofxButton tbSimButton;
		ofxButton pendSimButton;
		ofxButton cPendSimButton;
		ofxButton buoSimButton;
		ofxButton mirLensSimButton;
};
