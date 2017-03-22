#pragma once

#include "ofMain.h"

class Painter {
public:
	void setup(int width, int height);
	void drawCircles(ofVec2f, ofColor);
	void draw();

private:
	int previewWidth, previewHeight;
	ofFbo canvas;
};
