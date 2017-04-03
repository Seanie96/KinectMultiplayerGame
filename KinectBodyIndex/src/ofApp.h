#pragma once

#include "ofMain.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Bubbles/Palette.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Bubbles/Bubble.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/SkeletalAPI/Skeletal.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Painting/Painter.h"
#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Painting/Image.h"

#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	//ofApp();
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
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
