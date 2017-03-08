#ifndef Bubble_hpp
#define Bubble_hpp

#include "ofApp.h"

class Bubble {
    
public:
    Bubble();
    void update(int);
    void draw();
    void reset();
    void pop();
    float get_x();
    float get_y();
    float get_radius();
    int get_color();
    const int colors[5] = {0x00B2EE, 0x7dca5c, 0x65428a, 0xad804e, 0x191919};
    
private:
    float radius, x, y;
    bool popped;
    int speed;
    int color;
};

#endif
