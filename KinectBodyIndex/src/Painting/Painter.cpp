#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Painting/Painter.h"

void Painter::setup(int width, int height) {
	previewWidth = width;
	previewHeight = height;
	canvas.allocate(previewWidth, previewHeight);
	canvas.begin();
	ofClear(255, 255, 255);
	canvas.end();
}

void Painter::drawCircles(ofVec2f pos, ofColor col) {
	canvas.begin();
	ofSetColor(col);
	ofDrawCircle(pos, 35);
	canvas.end();
}

void Painter::draw() {
	canvas.draw(0, 0);
}