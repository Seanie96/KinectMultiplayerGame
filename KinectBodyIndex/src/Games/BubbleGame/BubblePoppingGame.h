#ifndef Bubble_Game_h
#define Bubble_Game_h

#include "ofMain.h"
#include "../src/Games/Game.h"
#include "ofMain.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Bubbles/Palette.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Bubbles/Bubble.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Skeletal/Skeletal.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Painting/Painter.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Games/BubbleGame/Painting/Image.h"

#include "ofxGui.h"

class BubblePoppingGame : public Game {
public:
	BubblePoppingGame();
	void setup() override;
	void update() override;
	void draw() override;
	
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
};


#endif