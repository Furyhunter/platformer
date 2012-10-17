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
	unsigned int getInternalWidth() { return internalWidth; }
	unsigned int getInternalHeight() { return internalHeight; }

	void addEntity(Entity& ent);
	void removeEntity(Entity& ent);

protected:
	bool initialized;

private:
	SDL_Surface* surface;
	bool running;
	Entity* first;
	Entity* last;
	Graphics g;
	unsigned int internalWidth;
	unsigned int internalHeight;
	unsigned int fboName;
	unsigned int renderName;
};
