#pragma once

#include "ofMain.h"

class Bubble {

public:
	Bubble(int width, int height, float rad);
	void update(int);
	void draw();
	void reset();
	void pop();
	float get_x();
	float get_y();
	float get_radius();
	ofColor get_color();
	const ofColor colors[5] = { ofColor(0, 0, 255, 255), ofColor(0, 255, 0, 255), ofColor(255, 0, 0, 255), ofColor(255, 255, 0, 255), ofColor(0, 255, 255, 255) };

private:
	float radius, x, y, radi;
	bool popped;
	int speed;
	ofColor color;
	int previewWidth, previewHeight;
};
