#pragma once

#include "ofMain.h"

class Image {
public:
	Image(string imagePath, string imageName);
	void draw();
	void update();

private:
	int previewWidth, previewHeight;
	ofTexture image;
};
