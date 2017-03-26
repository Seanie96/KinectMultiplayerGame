#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Bubbles/Palette.h"

using std::find;
/*
Creates a new palette with hard coded dimensions.
If screen size comes into play we'll have to work
them out based on that
*/
Palette::Palette() {
}

Palette::Palette(int x, int y, int width, int height)
{
	palette_width = width;
	palette_height = height;
	color_radius = width / 14;
	palette_color = 0xFFFFFF;
	palette_x = x;
	palette_y = y;

	initalisePlayerColors(20); //max number of people to be tracked!
}

/*
Draws the palette to the screen with the currently
available colors on it
*/
void Palette::draw()
{
	ofSetHexColor(palette_color);
	ofDrawRectangle(palette_x, palette_y, palette_width, palette_height);

	for (int i = 0; i < colors_on_palette.size(); i++)
	{
		ofSetColor(colors_on_palette[i]);
		float circle_x = palette_x + (color_radius * 1.5) + ((color_radius * 2.5) * i);
		float circle_y = palette_y + (color_radius * 1.2);
		ofVec2f pos(circle_x, circle_y);
		colorPositions.push_back(pair<ofVec2f, ofColor>(pos, colors_on_palette[i]));
		ofDrawCircle(circle_x, circle_y, color_radius);
	}
	ofSetHexColor(0xFFFFFF);
}

void Palette::add_color(ofColor col)
{
	//Adds the color of it's not already on the palette
	if (find(colors_on_palette.begin(), colors_on_palette.end(), col) == colors_on_palette.end())
	{
		colors_on_palette.push_back(col);
	}
}

void Palette::clear()
{
	colors_on_palette.clear();
}

void Palette::getColorsChosen(vector< pair<int, ofVec2f>> handPositions) {
	for (vector< pair<int, ofVec2f> >::iterator it1 = handPositions.begin(); it1 != handPositions.end(); ++it1) {
		for (vector< pair<ofVec2f, ofColor> >::iterator it2 = colorPositions.begin(); it2 != colorPositions.end(); ++it2) {
			float handx = (it1->second).x;
			float handy = (it1->second).y;
			float bubblex = (it2->first).x;
			float bubbley = (it2->first).y;
			if ((handx < (bubblex + color_radius) && handx > (bubblex - color_radius)) && (handy < (bubbley + color_radius) && handy > (bubbley - color_radius))) {
				cout << "color being chosen!" << endl;
				changeColor(it2->second, it1->first);
			}
		}
	}
	colorPositions.clear();
}

ofColor Palette::getColorChosen(int body)
{
	for (vector< pair<int, ofColor> >::iterator it = playerColor.begin(); it != playerColor.end(); ++it) {
		if (it->first == body)
		{
			return it->second;
		}
	}
}

void Palette::changeColor(ofColor col, int body)
{
	for (vector< pair<int, ofColor> >::iterator it = playerColor.begin(); it != playerColor.end(); ++it) {
		if(it->first == body)
		{
			it->second = col;
		}
	}
}

void Palette::initalisePlayerColors(int size)
{
	for(int i = 0; i < size; i++)
	{
		playerColor.push_back(pair<int, ofColor>(i, ofColor(0, 0, 0, 125)));
	}
}
