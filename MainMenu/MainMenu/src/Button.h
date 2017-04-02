#ifndef Button_h
#define Button_h

#include <string>

<<<<<<< HEAD
#include "ofApp.h"
=======
#include "ofMain.h"
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

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
