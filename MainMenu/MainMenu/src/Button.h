#ifndef Button_h
#define Button_h

#include <string>

#include "ofApp.h"

class Button {

public:
	Button(float xpos, float ypos, string passText, float w, float h);
	void update();
	void draw();
	void pressButton(bool press);
	float get_x();
	float get_y();
	float get_height();
	float get_width();
	ofTrueTypeFont myFont;

private:
	float x, y, height, width;
	string buttonText;
	bool buttonPressed, buttonHovered;
	ofColor buttonColor;
};

#endif
