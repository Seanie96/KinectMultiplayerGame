#include "ofApp.h"
#include "Bubble.hpp"
#include "Palette.hpp"

#define NUM_BUBBLES 20

using std::vector;

vector<Bubble> bubbles;
Palette palette;

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < NUM_BUBBLES; i++)
    {
        Bubble b = Bubble();
        bubbles.push_back(b);
    }
    palette = Palette();
    sounds.load("pop_sound.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < bubbles.size(); i++)
    {
        bubbles[i].update(i);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < bubbles.size(); i++)
    {
        bubbles[i].draw();
    }
    palette.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Reset the palette
    if(key == 'r')
    {
        palette.clear();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0; i < bubbles.size(); i++)
    {
        float bub_x = bubbles[i].get_x();
        float bub_y = bubbles[i].get_y();
        float rad = bubbles[i].get_radius();
        
        if((x < bub_x + rad && x > bub_x - rad) && (y < bub_y + rad && y > bub_y - rad))
        {
            bubbles[i].pop();
            sounds.play();
            palette.add_color(bubbles[i].get_color());
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
