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
	beginTime = clock();
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
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	glClear(GL_DEPTH_BUFFER_BIT);
	skeletal.drawBodies();
	if (beginPainting == true) {
		painter.draw();
	}
	else
	{
		for (int i = 0; i < bubbles.size(); i++) {
			bubbles[i].draw();
		}
	}
	ofDisableAlphaBlending();
	palette.draw();
}

void ofApp::checkForCollision(vector< pair<int, ofVec2f>> positions) {
	for (vector< pair<int, ofVec2f> >::iterator handPosition = positions.begin(); handPosition != positions.end(); ++handPosition) {
		ofVec2f pos = handPosition->second;
		float x = pos.x;
		float y = pos.y;
		for (int i = 0; i < bubbles.size(); i++)
		{
			float bub_x = bubbles[i].get_x();
			float bub_y = bubbles[i].get_y();
			float rad = bubbles[i].get_radius();
			if ((x < bub_x + rad && x > bub_x - rad) && (y < bub_y + rad && y > bub_y - rad))
			{
				bubbles[i].pop();
				sounds.play();
				palette.add_color(bubbles[i].get_color());
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
