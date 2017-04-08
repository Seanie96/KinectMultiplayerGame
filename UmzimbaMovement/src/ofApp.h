#pragma once

#include "ofMain.h"
#include "MainMenu/Menu.h"
#include "MainMenu/Button.h"
#include "Games/BubbleGame/BubblePoppingGame.h"
#include "AboutPage/AboutPage.h"

#include <vector>


class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);


private:
	ofTrueTypeFont titleFont;
	int screenNo;
	BubblePoppingGame bubbleGame;
};
