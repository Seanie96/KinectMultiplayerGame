#pragma once
#pragma once

#include "ofMain.h"
#include "../addons/ofxKinectForWindows2/src/ofxKinectForWindows2.h"


class Skeletal {
public:
	void setup(int width, int height);
	vector<ofVec2f> gethandPositions(ofxKFW2::ProjectionCoordinates proj);
	void update();
	void drawBodies();

private:
	ofxKFW2::Device kinect;
	int previewWidth, previewHeight;
	ICoordinateMapper * coordinateMapper;
	vector<ofVec2f> handPositions;

};
