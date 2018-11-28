#include "twoBalls.h"

twoBalls::twoBalls() {
}

void twoBalls::setup() {
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(60.0);
	parameters.setName("parameters");
	parameters.add(x_vel1.set("X Velocity Ball 1", 10, 1, 100));
	parameters.add(y_vel1.set("Y Velocity Ball 1", -10, -1, -100));
	parameters.add(x_vel2.set("X Velocity Ball 2", -10, -1, -100));
	parameters.add(y_vel2.set("Y Velocity Ball 2", -10, -1, -100));
	parameters.add(radius1.set("Radius Ball 1", 15, 10, 100));
	parameters.add(radius2.set("Radius Ball 2", 15, 10, 100));
	gui.setup(parameters);
	auto circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.0, 0.53, 0.9);
	circle.get()->setup(box2d.getWorld(), radius1, ofGetHeight() - radius1, radius1);
	circle.get()->setVelocity(x_vel1, y_vel1);
	circles.push_back(circle);
	circle = std::make_shared<ofxBox2dCircle>();
	circle.get()->setPhysics(3.0, 0.53, 0.9);
	circle.get()->setup(box2d.getWorld(), ofGetWidth() - radius2, ofGetHeight() - radius2, radius2);
	circle.get()->setVelocity(x_vel2, y_vel2);
	circles.push_back(circle);
}

void twoBalls::update() {
	box2d.update();
}

void twoBalls::draw() {
	gui.draw();
	for (int i = 0; i < circles.size(); i++) {
		ofFill();
		ofSetHexColor(0xf6c738);
		circles[i].get()->draw();
	}

	box2d.drawGround();

	string info = "";
	info += "Use the sliders to adjust the parameters!\n";
	info += "Press [r] to reset!\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 10, ofGetHeight() / 3);

	string title = "Simulation of Two Balls";
	ofDrawBitmapString(title, ofGetWidth() / 2 - 50, 10);
}

void twoBalls::keyPressed(int key) {
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
	ofVec2f pos_reset1(radius1, ofGetHeight() - radius1);
	ofVec2f vel_reset1(x_vel1, y_vel1);
	ofVec2f pos_reset2(ofGetWidth() - radius2, ofGetHeight() - radius2);
	ofVec2f vel_reset2(x_vel2, y_vel2);
	if (key == 'r') {
		circles[0].get()->setPosition(pos_reset1);
		circles[0].get()->setVelocity(vel_reset1);
		circles[0].get()->setRadius(radius1);
		circles[1].get()->setPosition(pos_reset2);
		circles[1].get()->setVelocity(vel_reset2);
		circles[1].get()->setRadius(radius2);
	}
}