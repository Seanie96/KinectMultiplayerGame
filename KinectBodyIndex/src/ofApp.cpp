#include "ofApp.h"

#define NUM_BUBBLES 20

using std::vector;

vector<Bubble> bubbles;
Palette palette;

int previewWidth;
int previewHeight;

//--------------------------------------------------------------
void ofApp::setup() {
	previewWidth = GetSystemMetrics(SM_CXSCREEN);
	previewHeight = GetSystemMetrics(SM_CYSCREEN);

	skeletal.setup(previewWidth, previewHeight);	
	painter.setup(previewWidth, previewHeight);

	for (int i = 0; i < NUM_BUBBLES; i++)
	{
		Bubble b = Bubble(previewWidth, previewHeight, 30);
		bubbles.push_back(b);
	}
	int paletteWidth = previewWidth / 3;
	int paletteHeight = previewHeight / 10;
	int x = (previewWidth / 2) - (paletteWidth / 2);
	int y = previewHeight - 2 * (paletteHeight);
	palette = Palette(x, y, paletteWidth, paletteHeight);
	sounds.load("pop_sound.mp3");

	beginPainting = false;
	bubblesPopped = 0;
	beginTime = clock();
	int fontSize = previewHeight / 40;
	group.loadFont("AYearWithoutRain.ttf", fontSize, true, true, 0);
	group.setBackgroundColor(0x999999);
}

//--------------------------------------------------------------
void ofApp::update() {
	skeletal.update();
	vector< pair<int, ofVec2f> > handPositions = skeletal.gethandPositions(ofxKFW2::ProjectionCoordinates::ColorCamera);
	if (!beginPainting) {
		for (int i = 0; i < bubbles.size(); i++) {
			bubbles[i].update(i);
		}
		checkForCollision(handPositions);
		float elapsedTime = float(clock() - beginTime) / CLOCKS_PER_SEC;
		if (elapsedTime >= 20) {
			beginPainting = true;
		}
	}
	else
	{
		palette.getColorsChosen(handPositions);
		for (vector< pair<int, ofVec2f> >::iterator it = handPositions.begin(); it != handPositions.end(); ++it) {
			painter.drawCircles(it->second, palette.getColorChosen(it->first));
		}
	}
	value.set("Number of Bubbles Burst: ", bubblesPopped); // name, default value, min, max
	group.setup();
	group.add(value);

	group.setPosition((previewWidth / 8) * 3, 0);
	group.setDefaultHeight(previewHeight/14);
	group.setDefaultWidth(previewWidth/4);
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	glClear(GL_DEPTH_BUFFER_BIT);
	skeletal.drawBodies();
	group.draw();
	if (beginPainting == true) {
		painter.draw();
	}
	else
	{
		for (int i = 0; i < bubbles.size(); i++) {
			bubbles[i].draw();
		}
	}
	palette.draw();
	ofDisableAlphaBlending();
}

void ofApp::checkForCollision(vector< pair<int, ofVec2f>> positions) {
	for (vector< pair<int, ofVec2f> >::iterator handPosition = positions.begin(); handPosition != positions.end(); ++handPosition) {
		ofVec2f pos = handPosition->second;
		float x = pos.x;
		float y = pos.y;
		for (int i = 0; i < bubbles.size(); i++)
		{
			if(bubbles[i].has_been_popped(x, y))
			{
				sounds.play();
				palette.add_color(bubbles[i].get_color());
				bubblesPopped++;
				cout << "bubbles popped:" << bubblesPopped << endl;
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'r') {
		palette.clear();
	}
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
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

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

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}
