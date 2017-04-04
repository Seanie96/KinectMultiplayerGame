#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Painting/Image.h"

Image::Image()
{
	
}

Image::Image(string imagePath, int width, int height) 
{
	pathName = imagePath;
	img.load(imagePath);

	/*
	if(img.getWidth() > (width / 2.5) || img.getHeight() > (height / 2.5))
	{
		img.resize(img.getWidth() / 2, img.getHeight() / 2);
	}
	*/
	image = img.getTexture();
	int w = width - image.getWidth();
	int h = height - image.getHeight();
	xPos = rand() % w;
	yPos = rand() % h;

	position = ofVec2f(xPos, yPos);
}

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

void Image::draw() 
{
	image.draw(position.x, position.y);
}

string Image::getPathName()
{
	return pathName;
}

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

float Image::getXPos()
{
	return xPos;
}

float Image::getYPos()
{
	return yPos;
}