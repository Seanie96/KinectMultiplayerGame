#pragma once

#include "ofMain.h"

class Bubble {

public:
	Bubble(int width, int height, float rad);
	void enhance();
	void update(int);
	void draw();
	void reset();
	float get_x();
	float get_y();
	float get_radius();
	ofColor get_color();
	const ofColor colors[5] = { ofColor(0, 0, 255, 125), ofColor(0, 255, 0, 125), ofColor(255, 0, 0, 125), ofColor(255, 255, 0, 125), ofColor(0, 255, 255, 125) };

private:
	int times_enhanced;
	float radius, x, y, radi;
	bool popped;
	int speed;
	ofColor color;
	int previewWidth, previewHeight;
};
