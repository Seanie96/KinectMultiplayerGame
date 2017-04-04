#ifndef Menu_h
#define Menu_h

#include "ofMain.h"
#include "Button.h"

class Menu {

public:
	Menu();
	Menu(vector<Button> buttons);
	void update();
	void draw();
	ofImage somanticsLogo;
	ofTrueTypeFont titleFont;
	int gameNo;

};

#endif
