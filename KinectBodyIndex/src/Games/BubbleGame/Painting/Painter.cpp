#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Painting/Painter.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

void Painter::setup(int width, int height) {
	previewWidth = width;
	previewHeight = height;
	canvas.allocate(previewWidth, previewHeight);
	imageCanvas.allocate(previewWidth, previewHeight);
	chosenImage = Image("african-elephant-bull.png", width, height);

	imageIterations = 3;

	numOfCanvasPixelsUsed = 0;
	numOfImageCanvasPixelsUsed = chosenImage.getNumOfPixels();
	drawImageToImageCanvas();

	timeToPaintNormally = false;
	displayingImage = false;
}

void Painter::drawCircles(ofVec2f pos, ofColor col, int radius) {
	if (timeToPaintNormally == false) {
		if (displayingImage == false) {
			canvas.begin();
			if (checkIfPosInFbo(pos)) {
				ofSetColor(col);
				ofDrawCircle(pos, radius);
				cout << "Pixels drawn : " << numOfCanvasPixelsUsed << endl;
				numOfCanvasPixelsUsed += (PI * (radius * radius)) / 12;
			}
			canvas.end();
		}
	}
	else
	{
		if(displayingImage == false)
		{
			canvas.begin();
			ofSetColor(col);
			ofDrawCircle(pos, radius);
			canvas.end();
		}
	}
}

bool Painter::checkIfPosInFbo(ofVec2f pos) {
	ofColor colorOfPixel = pixelsOfImageCanvas.getColor(pos.x, pos.y);
	int alphaVal = colorOfPixel.a;
	if(alphaVal > 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Painter::drawImageToImageCanvas() {
	imageCanvas.begin();
	ofClear(255, 255, 255, 0);
	chosenImage.draw();
	imageCanvas.end();
	imageCanvas.readToPixels(pixelsOfImageCanvas);
	canvas.begin();
	ofClear(255, 255, 255, 0);
	canvas.end();
}

void Painter::update() {
	if (timeToPaintNormally == false) {
		if (numOfCanvasPixelsUsed >= numOfImageCanvasPixelsUsed)
		{
			if (displayingImage == false) {
				imageIterations--;
				if(imageIterations == 0)
				{
					timeToPaintNormally = true;
				}
				displayImageTime();
				drawImage();
			}
			else
			{
				float elapsedTime = float(clock() - beginTime) / CLOCKS_PER_SEC;
				if (elapsedTime >= 5)
				{
					displayingImage = false;
					numOfCanvasPixelsUsed = 0;
					chosenImage = Image("african-elephant-bull.png", previewWidth, previewHeight);
					numOfImageCanvasPixelsUsed = chosenImage.getNumOfPixels();
					drawImageToImageCanvas();
				}
			}
		}
	}
	else
	{
		if (displayingImage == true)
		{
			float elapsedTime = float(clock() - beginTime) / CLOCKS_PER_SEC;
			if (elapsedTime >= 5)
			{
				displayingImage = false;
				canvas.begin();
				ofClear(255, 255, 255, 0);
				canvas.end();
			}
		}
	}
}

void Painter::displayImageTime()
{
	displayingImage = true;
	beginTime = clock();
}

void Painter::drawImage()
{
	canvas.begin();
	ofClear(255, 255, 255, 0);
	chosenImage.draw();
	canvas.end();
}

void Painter::draw() {
	canvas.draw(0, 0);
}