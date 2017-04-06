#include "ofApp.h"
//--------------------------------------------------------------

using std::vector;
vector<Button> buttons;
Menu mainMenu = Menu();

void ofApp::setup() {
	//somanticsLogo.load("C:/Users/LukeTynan/Desktop/openFrameworks/apps/myApps/MainMenu/MainMenu/bin/data/somantics1.jpg");
	Button button1 = Button(300, 350, "Bubble Game", 300, 150);
	Button button2 = Button(700, 350, "About", 300, 150);
	//Button button3 = Button(700, 250, "Combo", 300, 150);
	//Button button4 = Button(700, 450, "About", 300, 150);

	Button back_button = Button(20, 20, "Back", 100, 50);

	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(back_button);
	//buttons.push_back(button3);
	//buttons.push_back(button4);
	mainMenu = Menu(buttons);

	screenNo = 4;				// draw the main menu setup screen
	if (screenNo == 4)
	{
		ofColor background = ofColor(255, 165, 0);
		titleFont.loadFont("zorque.ttf", 96);
		ofBackground(background);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	if (screenNo == 4) {
		mainMenu.update();
	}
	else if(screenNo == 0)
	{
		bubbleGame.update();
	}
	else if (screenNo == 1)
	{
		bubbleGame.update();
	}
	else if (screenNo == 2)
	{
		bubbleGame.update();
	}
	else if (screenNo == 3)
	{
		bubbleGame.update();
	}
}

//-----------------------------------------------------------------------------------
void ofApp::draw() {
	if (screenNo == 4) {
		mainMenu.draw();
	}
	else if(screenNo == 0)
	{
		 bubbleGame.draw();
	}
	else if (screenNo == 1)
	{
		 bubbleGame.draw();
	}
	else if (screenNo == 2)
	{
		 bubbleGame.draw();
	}
	else if (screenNo == 3)
	{
		 bubbleGame.draw();

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	for (int i = 0; i < buttons.size(); i++) {
		float button_x = buttons[i].get_x();
		float button_y = buttons[i].get_y();
		float button_width = buttons[i].get_width();
		float button_height = buttons[i].get_height();

		if ((x > button_x) && (x < button_x + button_width)
			&& (y > button_y) && (y < button_y + button_height) && screenNo == 4) {
			buttons[i].pressButton(true);
			screenNo = i;
			if (screenNo == 0)
			{
				bubbleGame.setup();
			}
			else if (screenNo == 1)
			{
				bubbleGame.setup();
			}
			else if (screenNo == 2)
			{
				bubbleGame.setup();
			}
			else if (screenNo == 3)
			{
				bubbleGame.setup();
			}
		}
		else if ((x > button_x) && (x < button_x + button_width) && (y > button_y) && (y < button_y + button_height) && screenNo == 0) {
			screenNo = 4;
			mainMenu.draw();
			mainMenu.update();
		}
		else
		{
			buttons[i].pressButton(false);
		}
		

	}
}


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
