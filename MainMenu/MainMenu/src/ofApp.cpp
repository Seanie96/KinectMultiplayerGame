#include "ofApp.h"
<<<<<<< HEAD
#include "Menu.h"
=======
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
//--------------------------------------------------------------

using std::vector;
vector<Button> buttons;
<<<<<<< HEAD

void ofApp::setup(){
=======
Menu mainMenu = Menu();

void ofApp::setup() {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	//somanticsLogo.load("C:/Users/LukeTynan/Desktop/openFrameworks/apps/myApps/MainMenu/MainMenu/bin/data/somantics1.jpg");
	Button button1 = Button(300, 250, "Bubbles", 300, 150);
	Button button2 = Button(300, 450, "Paint", 300, 150);
	Button button3 = Button(700, 250, "Combo", 300, 150);
	Button button4 = Button(700, 450, "About", 300, 150);
<<<<<<< HEAD
=======

>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
<<<<<<< HEAD
	Menu mainMenu = Menu(buttons);
	
=======
	mainMenu = Menu(buttons);

	Game bubblePainting;
	games.push_back(bubblePainting);

>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	gameNo = 4;				// draw the main menu setup screen
	if (gameNo == 4)
	{
		ofColor background = ofColor(255, 165, 0);
		titleFont.loadFont("zorque.ttf", 96);
		ofBackground(background);
	}
<<<<<<< HEAD
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (gameNo == 4) {
		Menu.update();
	}
	else if (gameNo == 0) {
		bubbles.update();
	}
	else if (gameNo == 1) {
		painter.update();
	}
	else if (gameNo == 2) {
		combo.update();
	}
	else if(gameNo ==3)
	{
		about.update();
=======

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
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}


	/*for (int i = 0; i < buttons.size(); i++) {
<<<<<<< HEAD
		buttons[i].update();
=======
	buttons[i].update();
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}*/
}

//-----------------------------------------------------------------------------------
<<<<<<< HEAD
void ofApp::draw(){
	if (gameNo == 4) {
		Menu.draw();
	}
	else if (gameNo == 0) {
		bubbles.draw();
	}
	else if (gameNo == 1) {
		painter.draw();
	}
	else if (gameNo == 2) {
		combo.draw();
	}
	else if(gameNo == 3)
	{
		about.draw();
=======
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
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}

	/*ofSetColor(ofColor::white);				 // draw game title in white
	titleFont.drawString("Synergy", 385, 200);
	//somanticsLogo.draw(290, 50);
	for (int i = 0; i < buttons.size(); i++) {
<<<<<<< HEAD
		buttons[i].draw();
=======
	buttons[i].draw();
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}*/
}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::keyPressed(int key){
=======
void ofApp::keyPressed(int key) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::keyReleased(int key){
=======
void ofApp::keyReleased(int key) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseMoved(int x, int y ){
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
=======
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
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
	}*/
}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseDragged(int x, int y, int button){
=======
void ofApp::mouseDragged(int x, int y, int button) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

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
<<<<<<< HEAD
				&& (y > button_y) && (y < button_y + button_height)) {
			buttons[i].pressButton(true);

=======
			&& (y > button_y) && (y < button_y + button_height) && gameNo == 4) {
			buttons[i].pressButton(true);
			gameNo = i;
			Game type = games.begin() + i;
			type = new Game();
			currentGame = type;
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547
		}
		else
		{
			buttons[i].pressButton(false);
		}
	}
}


//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseReleased(int x, int y, int button){
=======
void ofApp::mouseReleased(int x, int y, int button) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseExited(int x, int y){
=======
void ofApp::mouseExited(int x, int y) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::windowResized(int w, int h){
=======
void ofApp::windowResized(int w, int h) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::gotMessage(ofMessage msg){
=======
void ofApp::gotMessage(ofMessage msg) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::dragEvent(ofDragInfo dragInfo){ 
=======
void ofApp::dragEvent(ofDragInfo dragInfo) {
>>>>>>> 09149b973c68c0d967153a95afdc24ce6cfdd547

}
