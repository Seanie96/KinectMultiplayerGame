#include "Menu.h"

//--------------------------------------------------------------
<<<<<<< HEAD

Menu::Menu(vector<Button> buttons) {
=======
using std::vector;
vector<Button> mainButtons;

Menu::Menu() {
}

Menu::Menu(vector<Button> buttons) {
	mainButtons = buttons;
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	ofColor background = ofColor(255, 165, 0);
	titleFont.loadFont("zorque.ttf", 96);
	ofBackground(background);
	//somanticsLogo.load("C:/Users/LukeTynan/Desktop/openFrameworks/apps/myApps/MainMenu/MainMenu/bin/data/somantics1.jpg");
}

void Menu::update()
{
<<<<<<< HEAD
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].update();
=======
	for (int i = 0; i < mainButtons.size(); i++) {
		mainButtons[i].update();
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}
}

void Menu::draw()
{
	ofSetColor(ofColor::white);				 // draw game title in white
	titleFont.drawString("Synergy Gaming", 200, 200);
	//somanticsLogo.draw(290, 50);
<<<<<<< HEAD
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].draw();
=======
	for (int i = 0; i < mainButtons.size(); i++) {
		mainButtons[i].draw();
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}
}


