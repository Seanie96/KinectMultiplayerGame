#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofSetupOpenGL(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), OF_FULLSCREEN);			// <-------- setup the GL context

																										// this kicks off the running of my app
																										// can be OF_WINDOW or OF_FULLSCREEN
																										// pass in width and height too:
	ofRunApp(new ofApp());
}