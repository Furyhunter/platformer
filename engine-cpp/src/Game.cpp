#include "Game.h"

#include <SDL_opengl.h>

#include "Entity.h"
#include "Texture.h"

Game::Game(void) {
	first = NULL;
	last = NULL;
	surface = NULL;
	initialized = false;
	running = false;
	internalWidth = 320;
	internalHeight = 200;
}

Game::~Game(void) {
	SDL_Quit();
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

void Game::addEntity(Entity& ent) {
	if (first == NULL) {
		first = &ent;
		last = &ent;
	}

	last->previous = last;
	last = &ent;
}

void Game::removeEntity(Entity& ent) {
	ent.next->previous = ent.previous;
	ent.previous->next = ent.next;

	ent.previous = NULL;
	ent.next = NULL;

	// Make sure to delete when you're done with it!
}

void Game::run() {
	Entity* itr;
	int before, after, diff;
	SDL_Event evt;

	Texture pic("pic.png");

	if (!initialized) {
		printf("Error: not initialized\n");
		return;
	}

	running = true;

	while (running) {
		before = SDL_GetTicks();

		// event handling
		while (SDL_PollEvent(&evt)) {
			switch (evt.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:

				break;
			}
		}
		// logic step
		itr = first;
		while (itr != NULL) {
			itr->step(*this, 1.f/60);
			itr = itr->next;
		}
		
		// draw step
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, internalWidth, internalHeight, 0, -1, 1);

		itr = first;
		while (itr != NULL) {
			itr->draw(*this, g);
			itr = itr->next;
		}

		SDL_GL_SwapBuffers();
		SDL_Flip(surface);

		// delay step (if needed)
		after = SDL_GetTicks();
		diff = after - before;

		if (diff < TPF) {
			SDL_Delay(TPF - diff);
		}
	}
}
