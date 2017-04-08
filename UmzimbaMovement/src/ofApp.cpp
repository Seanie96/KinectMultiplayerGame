#include "ofApp.h"
//--------------------------------------------------------------

using std::vector;
vector<Button> buttons;
Menu mainMenu = Menu();
AboutPage about = AboutPage();

/*
 * Sets up the main game, uses a vector too hold a set of buttons.
 * Each game will have a button, and the main menu.
 * 
 */
void ofApp::setup() {
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	Button button1 = Button((width / 6) * 1.5, (height / 8) * 5, "Bubble Game", width / 6, height / 7);
	Button button2 = Button((width / 5) * 3, (height / 8) * 5, "About", width / 6, height / 7);

	Button back_button = Button(20, 20, "Back", 100, 50);

	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(back_button);
	mainMenu = Menu(buttons, width, height);

	screenNo = 2;				// draw the main menu screen on startup
	if (screenNo == 2)
	{
		ofColor background = ofColor(255, 165, 0);
		titleFont.loadFont("zorque.ttf", 96);
		ofBackground(background);
	}

}

/*
 * Checks what current screen is being drawn. Then it will update that game/screen.
 */

void ofApp::update() {
	if (screenNo == 2) {
		mainMenu.update();
	}
	else if(screenNo == 0)
	{
		bubbleGame.update();
	}
	else if (screenNo == 1)
	{
		about.update();
	}
}

/*
 * draws the current game/Screen.
 */

void ofApp::draw() {
	if (screenNo == 2) {
		mainMenu.draw();
	}
	else if(screenNo == 0)
	{
		 bubbleGame.draw();
	}
	else if (screenNo == 1)
	{
		 about.draw();
	}
}

/*
 * Checks to see whether button has been pressed. If one has been pressed then the Application will shift to the next according screen.
 * i.e if a game is pressed, the game will initiate. If a back button is pressed, then the user is brought to the main-menu.
 * 
 * If a button is pressed, the screenNo variable is changed to a number that sybmolises that screen. 2 = main menu, 0 = the bubble popping game, 1 = About page.
 */

void ofApp::mousePressed(int x, int y, int button)
{
	for (int i = 0; i < buttons.size(); i++) {
		float button_x = buttons[i].get_x();
		float button_y = buttons[i].get_y();
		float button_width = buttons[i].get_width();
		float button_height = buttons[i].get_height();

		if ((x > button_x) && (x < button_x + button_width) && (y > button_y) && (y < button_y + button_height) && screenNo == 2) {
			buttons[i].pressButton(true);
			screenNo = i;
			if (screenNo == 0)
			{
				bubbleGame.setup();
			}
			else if (screenNo == 1)
			{
				about.setup();
			}
		}
		else if ((x > button_x) && (x < button_x + button_width) && (y > button_y) && (y < button_y + button_height) && (screenNo == 0 || screenNo == 1) && i==2) {
			buttons[i].pressButton(true);
			screenNo = 2;
			mainMenu.draw();
			mainMenu.update();
		}
		else
		{
			buttons[i].pressButton(false);
		}
		

	}
}
