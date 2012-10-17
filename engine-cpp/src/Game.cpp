#include "Game.h"


Game::Game(void) {
	first = NULL;
	surface = NULL;
}

Game::~Game(void) {
	if (initialized) {
		
		//SDL_Quit();
	}
}

void Game::init() {
	if (initialized) {
		return;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return;
	}
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);

	surface = SDL_SetVideoMode(640, 400, 32, SDL_OPENGL);

	if (surface == NULL) {
		printf("Failed to set SDL video mode\n");
		return;
	}

	initialized = true;
}

void Game::run() {
	if (!initialized) {
		printf("Error: not initialized\n");
	}
	Entity* itr;

	running = true;

	while (running) {
		// logic step
		itr = first;
		while (itr != NULL) {
			itr->step();
			itr = itr->next;
		}
		
		// draw step
		itr = first;
		while (itr != NULL) {
			itr->draw();
			itr = itr->next;
		}
		// delay step (if needed)
	}
}
