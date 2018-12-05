#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	tbSimButton.addListener(this, &ofApp::tbSimButtonPressed);
	pendSimButton.addListener(this, &ofApp::pendSimButtonPressed);
	cPendSimButton.addListener(this, &ofApp::cPendSimButtonPressed);
	buoSimButton.addListener(this, &ofApp::buoSimButtonPressed);
	mirLensSimButton.addListener(this, &ofApp::mirLensSimButtonPressed);
	gui.setup();
	gui.add(tbSimButton.setup("Two Balls Simulation"));
	gui.add(pendSimButton.setup("Pendulum Simulation"));
	gui.add(cPendSimButton.setup("Chaotic Pendulum Simulation"));
	gui.add(buoSimButton.setup("Buoyancy Simulation"));
	gui.add(mirLensSimButton.setup("Mirror Lens Simulation"));
	gui.setPosition(ofGetWindowWidth() - 250, 0);

	sim = TwoBalls;

	tbSim.setup();
	pendSim.setup();
	cPendSim.setup();
	buoSim.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (sim == TwoBalls) {
		tbSim.update();
	}
	if (sim == Pendulum) {
		pendSim.update();
	}
	if (sim == ChaoticPendulum) {
		cPendSim.update();
	}
	if (sim == Buoyancy) {
		buoSim.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	if (sim == TwoBalls) {
		tbSim.draw();
	}
	if (sim == Pendulum) {
		pendSim.draw();
	}
	if (sim == ChaoticPendulum) {
		cPendSim.draw();
	}
	if (sim == Buoyancy) {
		buoSim.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (sim == TwoBalls) {
		tbSim.keyPressed(key);
	}
	if (sim == Pendulum) {
		pendSim.keyPressed(key);
	}
	if (sim == ChaoticPendulum) {
		cPendSim.keyPressed(key);
	}
	if (sim == Buoyancy) {
		buoSim.keyPressed(key);
	}
}

void ofApp::tbSimButtonPressed() {
	sim = TwoBalls;
}

void ofApp::pendSimButtonPressed() {
	sim = Pendulum;
}

void ofApp::cPendSimButtonPressed() {
	sim = ChaoticPendulum;
}

void ofApp::buoSimButtonPressed() {
	sim = Buoyancy;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
