#include "Menu.h"

//--------------------------------------------------------------
using std::vector;
vector<Button> mainButtons;

Menu::Menu() {
}

Menu::Menu(vector<Button> buttons) {
	mainButtons = buttons;
	ofColor background = ofColor(255, 165, 0);
	titleFont.loadFont("zorque.ttf", 96);
	ofBackground(background);
	//somanticsLogo.load("C:/Users/LukeTynan/Desktop/openFrameworks/apps/myApps/MainMenu/MainMenu/bin/data/somantics1.jpg");
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
	titleFont.drawString("Synergy Gaming", 200, 200);
	//somanticsLogo.draw(290, 50);
	for (int i = 0; i < mainButtons.size(); i++) {
		mainButtons[i].draw();
	}
}
