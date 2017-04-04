#ifndef Game_h
#define Game_h

#include "ofMain.h"

class Game {

public:
	Game();
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};


#endif