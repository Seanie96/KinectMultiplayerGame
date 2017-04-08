#include "Palette.h"

using std::find;

Palette::Palette() {
}

/*
* Creates a new palette with hard coded dimensions.
* If screen size comes into play we'll have to work
* them out based on that.
*/
Palette::Palette(int x, int y, int width, int height)
{
	palette_width = width;
	palette_height = height;
	color_radius = width / 14;
	palette_color = 0x999999;
	palette_x = x;
	palette_y = y;

	initalisePlayerColors(20); //max number of people to be tracked!
}

/*
 * Draws the palette to the screen with the currently
 * available colors on it
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

/*
 * Add an ofColor object to the palette vector list.
 */

void Palette::add_color(ofColor col)
{
	//Adds the color of it's not already on the palette
	if (find(colors_on_palette.begin(), colors_on_palette.end(), col) == colors_on_palette.end())
	{
		colors_on_palette.push_back(col);
	}
}

/*
 * Clears the palette color list.
 */
void Palette::clear()
{
	colors_on_palette.clear();
}

/*
 * Gets the color chosen from the palette, by a body.
 * First, this method will check if the current hand positions of the body are on a color on the palette.
 * If it is, then the color that that body will be painting with will be changed to that the hand posiiton is on.
 * If the hand Position is not on a color, then the previous color associated with that body, is kept.
 * These color to body associations are maintained by using a vector list of pairs, each pair having a body index and an ofColor object.
 */

void Palette::getColorsChosen(vector< pair<int, ofVec2f>> handPositions) {
	for (vector< pair<int, ofVec2f> >::iterator it1 = handPositions.begin(); it1 != handPositions.end(); ++it1) {
		for (vector< pair<ofVec2f, ofColor> >::iterator it2 = colorPositions.begin(); it2 != colorPositions.end(); ++it2) {
			float handx = (it1->second).x;
			float handy = (it1->second).y;
			float bubblex = (it2->first).x;
			float bubbley = (it2->first).y;
			if ((handx < (bubblex + color_radius) && handx >(bubblex - color_radius)) && (handy < (bubbley + color_radius) && handy >(bubbley - color_radius))) {
				cout << "color being chosen!" << endl;
				changeColor(it2->second, it1->first);
			}
		}
	}
	colorPositions.clear();
}

/*
 * Gets the color that a perticular body should be painting with. It does this by 
 * keeping track of the color and body index pairs using a vector<int, ofColo> list.
 */

ofColor Palette::getColorChosen(int body)
{
	for (vector< pair<int, ofColor> >::iterator it = playerColor.begin(); it != playerColor.end(); ++it) {
		if (it->first == body)
		{
			return it->second;
		}
	}
}

/*
 * Changes the color that a user will paint with, by storing a different ofColor object at the index of 
 * a vector<int, ofColor> list, which resembles the that body/user.
 */

void Palette::changeColor(ofColor col, int body)
{
	for (vector< pair<int, ofColor> >::iterator it = playerColor.begin(); it != playerColor.end(); ++it) {
		if (it->first == body)
		{
			it->second = col;
		}
	}
}

/*
 * Stores black as the default colors of all bodies recognised by the kinect.
 */

void Palette::initalisePlayerColors(int size)
{
	for (int i = 0; i < size; i++)
	{
		playerColor.push_back(pair<int, ofColor>(i, ofColor(0, 0, 0, 125)));
	}
}
