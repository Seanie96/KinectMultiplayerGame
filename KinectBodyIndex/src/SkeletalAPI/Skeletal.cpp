#include "Skeletal.h"

void Skeletal::setup(int width, int height) {
	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();
	kinect.initInfraredSource();
	kinect.initBodySource();
	kinect.initBodyIndexSource();

	previewWidth = width;
	previewHeight = height;
}

vector<ofVec2f> Skeletal::gethandPositions(ofxKFW2::ProjectionCoordinates proj) {
	int numOfBodies = 0;
	vector<ofxKFW2::Data::Body> bodies;
	bodies = kinect.getBodySource()->getBodies();
	for (auto body : bodies) {
		numOfBodies++;
	}

	handPositions.clear();

	int w, h;
	w = 1920;
	h = 1080;

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
		handPositions.push_back(jntsProj[JointType_HandLeft]);
		handPositions.push_back(jntsProj[JointType_HandRight]);
	}
	return handPositions;
}

void Skeletal::update() {
	kinect.update();
}

void Skeletal::drawBodies() {
	kinect.getColorSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getColorSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getBodySource()->drawProjected(0, 0, previewWidth, previewHeight);
}