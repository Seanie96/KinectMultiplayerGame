#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Bubbles/Bubble.h"

using std::rand;

/*
 * Creates a new instance of bubble.
 * Each new instance has a randomised speed,
 * radius, x position and y position (within
 * the bounds of the sreeen).
 */
Bubble::Bubble(int width, int height, float rad)
{
	previewHeight = height;
	previewWidth = width;
	radi = rad;

	speed = rand() % (3 - 1) + 1;
	radius = rand() % (35 - 30) + radi;
	x = rand() % (previewWidth - 1) + 1;
	y = rand() % (previewHeight - 250) + 250;
	popped = false;
	int color_index = rand() % 5;
	color = colors[color_index];
	times_enhanced = 0;
}

void Bubble::update(int i)
{
	//Move the bubble up the screen at its given speed
	y -= speed;

	//This adds some random movement on the x-axis for more natural looking bubbles
	if (i % 2 == 0 && rand() > 5)
	{
		x += 0.3;
	}
	else
	{
		x -= 0.3;
	}

	//Reset the bubble if it goes out of bounds
	if (y < 0 - radius || x < 0 - radius || x > previewWidth + radius)
	{
		reset();
	}
}

void Bubble::enhance()
{
	times_enhanced++;
	radius += 3;
}

void Bubble::draw()
{
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}

/*
 * Resets the bubble to the bottom of the screen.
 * Essentially the same as creating a new bubble,
 * but quicker.
 */
void Bubble::reset()
{
	speed = rand() % (3 - 1) + 1;
	radius = rand() % (35 - 30) + radi;
	x = rand() % (previewWidth - 1) + 1;
	// Y position not randomised this time, want it to appear from the bottom.
	y = previewHeight;
	int color_index = rand() % 5;
	color = colors[color_index];
}

ofColor Bubble::get_color() { return color; }

float Bubble::get_x() { return x; }

float Bubble::get_y() { return y; }

float Bubble::get_radius() { return radius; }












