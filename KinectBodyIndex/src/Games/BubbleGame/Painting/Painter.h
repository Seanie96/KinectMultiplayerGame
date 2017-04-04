#pragma once

#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Painting/Image.h"
#include "ofMain.h"


class Painter {
public:
	void setup(int width, int height);
	void drawCircles(ofVec2f, ofColor, int);
	void draw();
	bool checkIfPosInFbo(ofVec2f);
	void update();

private:
	void chooseNextImage();
	void drawImageToImageCanvas();
	void displayImageTime();
	void drawImage();
	int numOfImageCanvasPixelsUsed;
	int numOfCanvasPixelsUsed;

	bool timeToPaintNormally;
	int previewWidth, previewHeight, imageIterations;
	ofFbo canvas;
	ofFbo imageCanvas;
	vector<ofImage> imagesToPaint;
	ofPixels pixelsOfImageCanvas, pixelsOfCanvas;
	Image chosenImage;
	vector<ofVec2f> pixelsAlreadyPainted;
	bool displayingImage;
	clock_t beginTime;
};
