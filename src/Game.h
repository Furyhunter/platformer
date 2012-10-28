#pragma once

#include <string>

#include <SDL.h>

#include "Graphics.h"

#define TPF 1000/60

using namespace std;

class Entity;

class Game {
public:
	Game(unsigned int width = 640, unsigned int height = 400, unsigned int iWidth = 320, unsigned int iHeight = 200);
	~Game(void);

	/**
		Initializes the game.
	*/
	virtual void init();

	virtual void run();
	void setCaption(const char* cap);

	int getTargetTPS();
	void setTargetTPS();
	unsigned int getInternalWidth() { return internalWidth; }
	unsigned int getInternalHeight() { return internalHeight; }
	bool getFullscreen() { return fullscreen; }
	void setFullscreen(bool fs) { fullscreen = fs; }
	string getCaption() { return caption; }

	void addEntity(Entity& ent);
	void removeEntity(Entity& ent);

protected:
	bool initialized;

private:
	SDL_Surface* surface;
	bool running;
	string caption;
	Entity* first;
	Entity* last;
	Graphics g;
	unsigned int width;
	unsigned int height;
	unsigned int internalWidth;
	unsigned int internalHeight;
	bool fullscreen;
};
