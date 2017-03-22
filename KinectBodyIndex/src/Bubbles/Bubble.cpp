#include "Bubble.h"

using std::rand;

/*
Creates a new instance of bubble.
Each new instance has a randomised speed,
radius, x position and y position (within
the bounds of the sreeen).
*/
Bubble::Bubble()
{
	speed = rand() % (3 - 1) + 1;
	radius = rand() % (35 - 30) + 30;
	x = rand() % (1920 - 1) + 1;
	y = rand() % (1080 - 250) + 250;
	popped = false;
	int color_index = rand() % 5;
	color = colors[color_index];
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
	if (y < 0 - radius || x < 0 - radius || x > 1920 + radius)
	{
		reset();
	}

	if (popped)
	{
		pop();
	}
}

void Bubble::draw()
{
	ofSetHexColor(color);
	ofDrawCircle(x, y, radius);
}

/*
Resets the bubble to the bottom of the screen.
Essentially the same as creating a new bubble,
but quicker.
*/
void Bubble::reset()
{
	speed = rand() % (3 - 1) + 1;
	radius = rand() % (35 - 30) + 30;
	x = rand() % (1920 - 1) + 1;
	//Y position not randomised this time, want it to appear from the bottom
	y = 1080;
	int color_index = rand() % 5;
	color = colors[color_index];
}

void Bubble::pop()
{
	popped = true;
	if (radius < 40)
	{
		radius += 3;
	}
	else
	{
		popped = false;
		reset();
	}
}

int Bubble::get_color() { return color; }

float Bubble::get_x() { return x; }

float Bubble::get_y() { return y; }

float Bubble::get_radius() { return radius; }












