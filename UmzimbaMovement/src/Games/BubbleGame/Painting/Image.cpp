#include "Image.h"

Image::Image()
{
	// does nothing. VS complains that there is a missing contructor, that's why this is here!
}

/*
 * Image class constructor. Takes in the height and width of the screen that the game is being ran on.
 * Then, it sets the coordinates that it's going to draw to on the screen, using an ofec2f object.
 */

Image::Image(string imagePath, int width, int height) 
{
	pathName = imagePath;
	img.load(imagePath);

	image = img.getTexture();
	int w = width - image.getWidth();
	int h = height - image.getHeight();
	xPos = rand() % w;
	yPos = rand() % h;

	position = ofVec2f(xPos, yPos);
}

/*
 * Image class constructor. Takes in the height and width of the screen that the game is being ran on.
 * Then, it sets the coordinates that it's going to draw to on the screen, using an ofec2f object.
 * the only difference between this one and the last one, is that this one takes an x and y position to draw to on the screen, instead of generating a position randomly.
 */

Image::Image(string imagePath,  int width, int height, float x, float y)
{
	pathName = imagePath;
	img.load(imagePath);

	if (img.getWidth() > (width / 2) || img.getHeight() > (height / 2))
	{
		img.resize(img.getWidth() / 2, img.getHeight() / 2);
	}

	image = img.getTexture();

	xPos = x;
	yPos = y;

	position = ofVec2f(x, y);
}

/*
 * Draws the specified image, given by the path name passed into the constructor, to the screen.
 */

void Image::draw() 
{
	image.draw(position.x, position.y);
}

/*
 * Gets the path name to the image being loaded.
 */

string Image::getPathName()
{
	return pathName;
}

/*
 * Gets the number of pixels of the image.
 */

int Image::getNumOfPixels()
{
	int size = 0;
	for(int i = 0; i < img.getWidth(); i++)
	{
		for (int j = 0; j < img.getHeight(); j++)
		{
			ofColor tmp = img.getColor(i, j);
			if(tmp.a != 0)
			{
				size++;
			}
		}
	}
	return size;
}

/*
 * Gets the x element of the index coordinate of the image.
 */

float Image::getXPos()
{
	return xPos;
}

/*
 * Gets the y element of the index coordinate of the image.
 */

float Image::getYPos()
{
	return yPos;
}