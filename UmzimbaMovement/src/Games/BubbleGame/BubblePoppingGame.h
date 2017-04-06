#ifndef Bubble_Game_h
#define Bubble_Game_h

#include "ofMain.h"
#include "ofMain.h"
#include "Bubbles/Palette.h"
#include "Bubbles/Bubble.h"
#include "Skeletal/Skeletal.h"
#include "Painting/Painter.h"
#include "Painting/Image.h"
#include "../src/MainMenu/Button.h"

#include "ofxGui.h"

class BubblePoppingGame {
public:
	BubblePoppingGame();
	void setup();
	void update();
	void draw();
	
private:
	void checkForCollision(vector< pair<int, ofVec2f> > positions);

protected:
	Painter painter;
	Skeletal skeletal;
	ofSoundPlayer sounds;
	ofImage bodyIndexImg, foregroundImg;
	bool beginPainting;
	clock_t beginTime;
	ofParameter<float> value;
	int bubblesPopped;
	ofxGuiGroup group;
	Button back_button;
};


#endif