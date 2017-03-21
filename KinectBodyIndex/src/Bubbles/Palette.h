#pragma once

#include "ofMain.h"

class Palette
{
public:
	Palette();
	Palette(int x, int y, int width, int height);
	void draw();
	void add_color(ofColor col);
	void clear();
	void getColorsChosen(vector< pair<int, ofVec2f> > handPositions);
	ofColor getColorChosen(int body);
	//vector<ofColor> mergePlayerColors(map<int, ofColor> playerColor1, map<int, ofColor> playerColor2);
	//ofColor Palette::getFirstColorOnPalette();

private:
	void changeColor(ofColor col, int body);
	void initalisePlayerColors(int size);
	vector< pair<ofVec2f, ofColor> > getColorPositions();
	vector< pair<ofVec2f, ofColor> > colorPositions;
	vector<ofColor> colors_on_palette;
	vector< pair<int, ofColor> > playerColor;
	float palette_width;
	float palette_height;
	int palette_color;
	int color_radius;
	int palette_x;
	int palette_y;
};
