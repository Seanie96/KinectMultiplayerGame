#pragma once

#include "ofMain.h"

class Image {
public:
	Image();
	Image(string imagePath, int width, int height);
	Image(string imagePath, int width, int height, float x, float y);
	void draw();
	string getPathName();
	int getNumOfPixels();
	float getXPos();
	float getYPos();

private:
	int previewWidth, previewHeight;
	ofTexture image;
	ofVec2f position;
	string name, pathName;
	ofImage img;
	float xPos, yPos;
};
