#pragma once

#include <SDL.h>

#include "Graphics.h"

#define TPF 1000/60

class Entity;

class Game {
public:
	Game(void);
	~Game(void);

	/**
		Initializes the game.
	*/
	virtual void init();

	virtual void run();

	int getTargetTPS();
	void setTargetTPS();
protected:
	bool initialized;

private:
	SDL_Surface* surface;
	bool running;
	Entity* first;
	Graphics g;
};
