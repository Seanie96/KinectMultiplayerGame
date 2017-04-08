#ifndef Menu_h
#define Menu_h

#include "ofMain.h"
#include "Button.h"

class Menu {

public:
	Menu();
	Menu(vector<Button> buttons, int width, int height);
	void update();
	void draw();

	ofImage somanticsLogo;
	ofTrueTypeFont titleFont;
	int gameNo;
	int previewWidth, previewHeight;
};

#endif
