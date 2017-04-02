#include "ofApp.h"
//--------------------------------------------------------------

using std::vector;
vector<Button> buttons;
Menu mainMenu = Menu();

void ofApp::setup() {
	//somanticsLogo.load("C:/Users/LukeTynan/Desktop/openFrameworks/apps/myApps/MainMenu/MainMenu/bin/data/somantics1.jpg");
	Button button1 = Button(300, 250, "Bubbles", 300, 150);
	Button button2 = Button(300, 450, "Paint", 300, 150);
	Button button3 = Button(700, 250, "Combo", 300, 150);
	Button button4 = Button(700, 450, "About", 300, 150);

	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
	mainMenu = Menu(buttons);

	Game bubblePainting;
	games.push_back(bubblePainting);

	gameNo = 4;				// draw the main menu setup screen
	if (gameNo == 4)
	{
		ofColor background = ofColor(255, 165, 0);
		titleFont.loadFont("zorque.ttf", 96);
		ofBackground(background);
	}

}

//--------------------------------------------------------------
void ofApp::update() {
	if (gameNo == 4) {
		mainMenu.update();
	}
	else if (gameNo == 0) {
		//bubbles.update();
	}
	else if (gameNo == 1) {
		//painter.update();
	}
	else if (gameNo == 2) {
		//combo.update();
	}
	else if (gameNo == 3)
	{
		//about.update();
	}


	/*for (int i = 0; i < buttons.size(); i++) {
	buttons[i].update();
	}*/
}

//-----------------------------------------------------------------------------------
void ofApp::draw() {
	if (gameNo == 4) {
		mainMenu.draw();
	}
	else if (gameNo == 0) {
		//bubbles.draw();
	}
	else if (gameNo == 1) {
		//painter.draw();
	}
	else if (gameNo == 2) {
		//combo.draw();
	}
	else if (gameNo == 3)
	{
		//about.draw();
	}

	/*ofSetColor(ofColor::white);				 // draw game title in white
	titleFont.drawString("Synergy", 385, 200);
	//somanticsLogo.draw(290, 50);
	for (int i = 0; i < buttons.size(); i++) {
	buttons[i].draw();
	}*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	/*for (int i = 0; i < buttons.size(); i++) {
	float button_x = buttons[i].get_x();
	float button_y = buttons[i].get_y();
	float button_width = buttons[i].get_width();
	float button_height = buttons[i].get_height();

	if ((x > button_x) && (x < button_x + button_width)
	&& (y > button_y) && (y < button_y + button_height)) {
	buttons[i].hoverButton(true);
	}
	else
	{
	buttons[i].hoverButton(false);
	}
	}*/
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
			&& (y > button_y) && (y < button_y + button_height) && gameNo == 4) {
			buttons[i].pressButton(true);
			gameNo = i;
			Game type = games.begin() + i;
			type = new Game();
			currentGame = type;
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
