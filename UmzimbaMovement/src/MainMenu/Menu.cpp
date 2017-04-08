#include "Menu.h"

//--------------------------------------------------------------
using std::vector;
vector<Button> mainButtons;

Menu::Menu() {
}

Menu::Menu(vector<Button> buttons, int width, int height) {
	mainButtons = buttons;
	ofColor background = ofColor(255, 165, 0);
	titleFont.loadFont("zorque.ttf", 70);
	ofBackground(background);
	previewWidth = width;
	previewHeight = height;
}

void Menu::update()
{
	for (int i = 0; i < mainButtons.size(); i++) {
		mainButtons[i].update();
	}
}

void Menu::draw()
{
	ofSetColor(ofColor::white);				 // draw game title in white
	titleFont.drawString("Umzimba Movement", previewWidth / 3, previewHeight / 8);
	//somanticsLogo.draw(290, 50);
	for (int i = 0; i < mainButtons.size(); i++) {
		if (i != 2)			// do not draw the back button on the main screen
		{
			mainButtons[i].draw(2);
		}
	}
}
