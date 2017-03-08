#ifndef Palette_hpp
#define Palette_hpp

#include "ofApp.h"

class Palette
{
public:
    Palette();
    void draw();
    void add_color(int);
    void clear();
    
private:
    vector<int> colors_on_palette;
    float palette_width;
    float palette_height;
    int palette_color;
    int color_radius;
    int palette_x;
    int palette_y;
};

#endif
