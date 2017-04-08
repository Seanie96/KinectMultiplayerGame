#ifndef AboutPage_h
#define AboutPage_h

#include "ofMain.h"
#include "Button.h"

class AboutPage {

public:
	AboutPage();
	void setup();
	void update();
	void draw();
	ofTrueTypeFont titleFont;
	Button back_button;
};

#endif