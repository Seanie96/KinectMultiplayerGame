#include "ofApp.h"
#include <iostream>
#include <string>

int previewWidth = 640;
int previewHeight = 480;

//--------------------------------------------------------------
void ofApp::setup() {
	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();
	kinect.initInfraredSource();
	kinect.initBodySource();
	kinect.initBodyIndexSource();

	ofSetWindowShape(previewWidth, previewHeight);

	drawImage = false;
	paintedObjects.allocate(previewWidth, previewHeight);
	paintedObjects.begin();
	ofClear(255, 255, 255);
	paintedObjects.end();


}

//--------------------------------------------------------------
void ofApp::update() {
	kinect.update();

	//--
	//Getting bones (connected joints)
	//--
	//#
	int numOfBodies = 0;
	vector<ofxKFW2::Data::Body> bodies;
	bodies = kinect.getBodySource()->getBodies();
	for (auto body : bodies) {
		numOfBodies++;
	}
	//
	//--
	handPositions.clear();
	{
		int w, h;
		w = 1920;
		h = 1080;
		std::map<HandState, ofVec2f>::iterator it1 = handPositions.begin();

		coordinateMapper = kinect.getBodySource()->getCoordinateMapper();

		for (auto & body : bodies) {
			if (!body.tracked) continue;

			map<JointType, ofVec2f> jntsProj;

			for (auto & j : body.joints) {
				ofVec2f & p = jntsProj[j.second.getType()] = ofVec2f();

				TrackingState state = j.second.getTrackingState();
				if (state == TrackingState_NotTracked) continue;

				p.set(j.second.getProjected(coordinateMapper, ofxKFW2::ProjectionCoordinates::ColorCamera));
				p.x = 0 + p.x / w * previewWidth;
				p.y = 0 + p.y / h * previewHeight;
			}

			drawCircles(body.leftHandState, jntsProj[JointType_HandLeft]);
			drawCircles(body.rightHandState, jntsProj[JointType_HandRight]);
		}

	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	glClear(GL_DEPTH_BUFFER_BIT);
	kinect.getColorSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getBodySource()->drawProjected(0, 0, previewWidth, previewHeight);
	paintedObjects.draw(0, 0);
	ofDisableAlphaBlending();
}

void ofApp::drawCircles(HandState state, ofVec2f pos) {
	ofColor color;
	switch (state)
	{
	case HandState_Unknown: case HandState_NotTracked:
		return;
	case HandState_Open:
		color = ofColor(0, 255, 0, 80);
		break;
	case HandState_Closed:
		color = ofColor(255, 255, 0, 80);
		break;
	case HandState_Lasso:
		color = ofColor(0, 255, 255, 80);
		break;
	}
	paintedObjects.begin();
	ofSetColor(color);
	ofDrawCircle(pos, 25);
	paintedObjects.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}
