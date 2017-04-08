#include "Button.h"

Button::Button()
{
	// do nothing
}

Button::Button(float xpos, float ypos, string passText, float w, float h)
{
	x = xpos;
	y = ypos;
	buttonText = passText;
	width = w;
	height = h;
	buttonColor = ofColor(200, 0, 0);
	buttonText = passText;
	buttonPressed = false;
	//buttonHovered = false;
	myFont.loadFont("arial.ttf", 24);
}


void Button::update()
{
	if (buttonPressed)
	{
		buttonColor = ofColor(255, 0, 0);
	}
	else
	{
		buttonColor = ofColor(200, 0, 0);
	}
}

void Button::draw(int screenNo)
{
	ofSetColor(buttonColor);			// draw button in red
	ofDrawRectangle(x, y, width, height);
	ofSetColor(ofColor::white);	// draw button text in white
	if (screenNo == 2)			// main menu text
	{
		myFont.drawString(buttonText, x + 80, y + 85);
	}
	else 
	{
		myFont.drawString(buttonText, x + 12, y + 40);					// game screen text for back button
	}
}

/*void Button::hoverButton(bool hover)
{
buttonHovered = hover;
}*/

void Button::pressButton(bool press)
{
	buttonPressed = press;
}

float Button::get_x() { return x; }

float Button::get_y() { return y; }

float Button::get_width() { return width; }

float Button::get_height() { return height; }
