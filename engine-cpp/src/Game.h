#pragma once

#include <SDL.h>

class Game {
public:
	Game(void);
	~Game(void);

	/**
		Initializes the game.
	*/
	void init();

	void run();

protected:
	bool initialized;

private:
	SDL_Surface* surface;
	bool running;
};

