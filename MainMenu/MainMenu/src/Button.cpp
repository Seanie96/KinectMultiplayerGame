#include "Button.h"

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
<<<<<<< HEAD
	{ 
=======
	{
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
		buttonColor = ofColor(255, 0, 0);
	}
	else
	{
		buttonColor = ofColor(200, 0, 0);
	}
}

void Button::draw()
{
	ofSetColor(buttonColor);			// draw button in red
<<<<<<< HEAD
	ofDrawRectangle(x,y,width,height);
	ofSetColor(ofColor::white);				 // draw button text in white
	myFont.drawString(buttonText, x+ 85, y+85);
=======
	ofDrawRectangle(x, y, width, height);
	ofSetColor(ofColor::white);				 // draw button text in white
	myFont.drawString(buttonText, x + 85, y + 85);
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
}

/*void Button::hoverButton(bool hover)
{
<<<<<<< HEAD
	buttonHovered = hover;
=======
buttonHovered = hover;
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
}*/

void Button::pressButton(bool press)
{
	buttonPressed = press;
}

float Button::get_x() { return x; }

float Button::get_y() { return y; }

float Button::get_width() { return width; }

float Button::get_height() { return height; }
