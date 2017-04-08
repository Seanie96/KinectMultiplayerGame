#include "AboutPage.h"

//--------------------------------------------------------------

AboutPage::AboutPage() {
	// does nothing. VS complains that there is a missing contructor, that's why this is here!
}

void AboutPage::setup()
{
	back_button = Button(20, 20, "Back", 90, 50);
	ofColor background = ofColor(255, 165, 0);
	titleFont.loadFont("zorque.ttf", 70);
	ofBackground(background);
}

void AboutPage::update()
{
	back_button.update();
}

void AboutPage::draw()
{
	ofSetColor(ofColor::white);				 // draw game title in white
	titleFont.drawString("Umzimba Movement", 200, 200);
	back_button.draw(1);
	ofDrawBitmapString("This Game was developed by Sean McDonagh, Luke Tynan, Maurice Buckley, Mark Hanley, Cian Guinee and Gordon Hind.", 200, 300);
}