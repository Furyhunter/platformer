#pragma once

#include <SDL.h>

#include "Entity.h"

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
};
