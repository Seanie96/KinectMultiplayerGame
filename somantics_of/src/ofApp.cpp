#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//ofBackground(255, 0, 0);
	ofSetFrameRate(60);
	camera.initGrabber(1024, 768);
}

//--------------------------------------------------------------
void ofApp::update() {
	//counter = counter + 1;
	camera.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	float radius = 3.0f;
	ofCircle(mouseX, mouseY, radius);
	/*
	float amplitude = 100.0f;
	ofSetColor(100, 100, 100);
	ofLine(0, 125, 1024, 125);
	ofSetColor(200, 200, 200);
	for (int i = 1; i < 1024; i++) {
	float x1 = (float)i / 250.0;
	float y1 = amplitude * sin(x1 * 2.0*PI);
	float x2 = (float)(i - 1) / 250.0;
	float y2 = amplitude * sin(x2 * 2.0*PI);
	ofLine(x1 * 250.0f, -y1 + 125, x2 * 250.f, -y2 + 125);
	}*/
	ofBackground(0);
	camera.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case 's':
		camera.videoSettings();
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
