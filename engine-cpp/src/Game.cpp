#include "Game.h"


Game::Game(void) {
	
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

	initialized = true;
}

void Game::run() {
	running = true;
	while (running) {
		// logic step

		// draw step

		// delay step (if needed)
	}
}
