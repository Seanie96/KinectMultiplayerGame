#include "Painter.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

/*
 * Takes in the width and height of the screen the game is being ran on.
 */

void Painter::setup(int width, int height) {
	previewWidth = width;
	previewHeight = height;
	canvas.allocate(previewWidth, previewHeight);
	imageCanvas.allocate(previewWidth, previewHeight);

	// Takes a .png image only!!
	chosenImage = Image("african-elephant-bull.png", width, height);

	// the number of times the image is iterated.
	imageIterations = 3;

	numOfCanvasPixelsUsed = 0;
	numOfImageCanvasPixelsUsed = chosenImage.getNumOfPixels();
	drawImageToImageCanvas();

	timeToPaintNormally = false;
	displayingImage = false;
}

/*
 * Draws the circles to the ofFbo object.
 * If the game is in the first half i.e the image has to find and paint to an image hidden on the screen, then, it might not draw the circle to the ofFbo object, 
 * this depends on whether the positions the user is trying to paint to is within the image or not. If it is, it will draw circle, if not, it will not draw the circle.
 * To find out whether the coordinates of the users hand is within the image, the checkIfPosInFbo method is called.
 * In the second half of the game, the user will paint to the screen normally.
 */

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

/*
 * Checks whether the coordinates of the ofVec2f object is within the image drawn to the ofFbo object.
 */

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

/*
 * Drawing the Image object to an ofFbo object.
 */

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

/*
 * Updates the the ofFbo objects and checks whether the amount of times drawn to it has rendered the background image fully drawn in.
 * If so, a new Image object is drawn to the cleared ofFbo object, and the cycle starts over again, with imageIterations decrementing.
 * If imageIterations reaches 0, then the user can paint normally.
 */

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

/*
 * Sets a timer, to track the amount of time spent on display the background image.
 */

void Painter::displayImageTime()
{
	displayingImage = true;
	beginTime = clock();
}

/*
 * Clears the ofFbo object and draws a new Image object to it.
 */

void Painter::drawImage()
{
	canvas.begin();
	ofClear(255, 255, 255, 0);
	chosenImage.draw();
	canvas.end();
}

/*
 * Draws the ofFbo object.
 */

void Painter::draw() {
	canvas.draw(0, 0);
}