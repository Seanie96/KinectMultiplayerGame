#include "../apps/myApps/KinectMultiplayerGame/KinectBodyIndex/src/Bubbles/Palette.h"

using std::find;
/*
Creates a new palette with hard coded dimensions.
If screen size comes into play we'll have to work
them out based on that
*/
Palette::Palette()
{
	palette_width = 650;
	palette_height = 100;
	color_radius = 40;
	palette_color = 0xFFFFFF;
	palette_x = 540;
	palette_y = 940;
}

/*
Once again, a lot of the dimensions in this are hard
coded.

Draws the palette to the screen with the currently
available colors on it
*/
void Palette::draw()
{
	ofSetHexColor(palette_color);
	ofDrawRectangle(palette_x, palette_y, palette_width, palette_height);

	for (int i = 0; i < colors_on_palette.size(); i++)
	{
		ofSetHexColor(colors_on_palette[i]);
		float circle_x = palette_x + color_radius + 50 + ((color_radius + 75) * i);
		float circle_y = palette_y + color_radius + 10;
		ofDrawCircle(circle_x, circle_y, color_radius);
	}
}

void Palette::add_color(int hex_color)
{
	//Adds the color of it's not already on the palette
	if (find(colors_on_palette.begin(), colors_on_palette.end(), hex_color) == colors_on_palette.end())
	{
		colors_on_palette.push_back(hex_color);
	}
}

void Palette::clear()
{
	colors_on_palette.clear();
}
