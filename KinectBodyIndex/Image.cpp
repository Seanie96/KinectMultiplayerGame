#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Painting/Image.h"

void Painter::setup(int width, int height) {
	previewWidth = width;
	previewHeight = height;
	canvas.allocate(previewWidth, previewHeight);
	imageCanvas.allocate(previewWidth, previewHeight);

	canvas.begin();
	ofClear(255, 255, 255);
	canvas.end();

	image.load("african-elephant-bull.png");
	image.resize(previewWidth / 5, previewHeight / 5);
	text = image.getTexture();

	int w = width - text.getWidth();
	int h = height - text.getHeight();
	float xPos = rand() % w;
	float yPos = rand() % h;

	imageCanvas.begin();
	ofClear(255, 255, 255, 0);
	text.draw(width / 2, height / 2);
	imageCanvas.end();

	imageCanvas.readToPixels(pixelsOfImageCanvas, 0);
}

void Painter::drawCircles(ofVec2f pos, ofColor col) {
	canvas.begin();
	if (checkIfPosInFbo(pos)) {
		ofSetColor(col);
		ofDrawCircle(pos, 25);
	}
	canvas.end();
}

bool Painter::checkIfPosInFbo(ofVec2f pos) {
	imageCanvas.readToPixels(pixelsOfImageCanvas, 0);
	ofColor colorOfPixel = pixelsOfImageCanvas.getColor(pos.x, pos.y);
	int alphaVal = colorOfPixel.a;
	if (alphaVal != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Painter::update()
{

}

void Painter::draw() {
	canvas.draw(0, 0);
}