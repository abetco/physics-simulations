#include "ofApp.h"
//static int pts[] = { 257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188 };
//static int nPts = 61 * 2;
//--------------------------------------------------------------
void ofApp::setup(){
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(60.0);
	parameters.setName("parameters");
	parameters.add(x_vel.set("X Velocity", 10, 1, 100));
	parameters.add(y_vel.set("Y Velocity", -10, -100, -1));
	parameters.add(radius.set("radius", 15, 10, 100));
	gui.setup(parameters);
	auto circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.0, 0.53, 0.9);
	circle.get()->setup(box2d.getWorld(), radius , ofGetHeight() - radius, radius);
	circle.get()->setVelocity(x_vel, y_vel);
	circles.push_back(circle);
	circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.9, 0.53, 0.9);
	circle.get()->setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, radius);
	circle.get()->setVelocity(-3.0, -10.0);
	circles.push_back(circle);

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	for (int i = 0; i < circles.size(); i++) {
		ofFill();
		ofSetHexColor(0xf6c738);
		circles[i].get()->draw();
	}
	// draw the ground
	box2d.drawGround();

	//string info = "";
	//info += "Press [c] for circles\n";
	//info += "Press [b] for blocks\n";
	//info += "Total Bodies: " + ofToString(box2d.getBodyCount()) + "\n";
	//info += "Total Joints: " + ofToString(box2d.getJointCount()) + "\n\n";
	//info += "FPS: " + ofToString(ofGetFrameRate(), 1) + "\n";
	//ofSetHexColor(0x444342);
	//ofDrawBitmapString(info, 30, 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if (key == 'c') {
	//	float r = ofRandom(14, 20);		// a random radius 4px - 20px
	//	auto circle = std::make_shared<ofxBox2dCircle>();
	//	circle.get()->setPhysics(3.0, 0.53, 0.9);
	//	circle.get()->setup(box2d.getWorld(), mouseX, mouseY, r);
	//	circles.push_back(circle);
	//}

	//if (key == 'b') {
	//	float w = ofRandom(14, 20);
	//	float h = ofRandom(14, 20);
	//	auto rect = std::make_shared<ofxBox2dRect>();
	//	rect.get()->setPhysics(3.0, 0.53, 0.9);
	//	rect.get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
	//	boxes.push_back(rect);
	//}

	//if (key == 't') ofToggleFullscreen();
	ofVec2f pos_reset1(radius, ofGetHeight() - radius);
	ofVec2f vel_reset1(x_vel, y_vel);
	ofVec2f pos_reset2(ofGetWidth() / 2, ofGetHeight() / 2);
	ofVec2f vel_reset2(-3, -10);
	if (key == 'r') {
		circles[0].get()->setPosition(pos_reset1);
		circles[0].get()->setVelocity(vel_reset1);
		circles[0].get()->setRadius(radius);
		circles[1].get()->setPosition(pos_reset2);
		circles[1].get()->setVelocity(vel_reset2);
	}
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
