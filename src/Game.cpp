#include "Game.h"

#include <SDL_opengl.h>

#include "Entity.h"
#include "Texture.h"

Game::Game(unsigned int width, unsigned int height, unsigned int iWidth,
		   unsigned int iHeight) {
	first = NULL;
	last = NULL;
	surface = NULL;
	initialized = false;
	running = false;
	this->width = width;
	this->height = height;
	internalWidth = iWidth;
	internalHeight = iHeight;
	fullscreen = false;
	caption = "";
}

Game::~Game(void) {
	SDL_Quit();
}

void Game::init() {
	int flags = SDL_OPENGL;
	if (initialized) {
		return;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Failed to initialize SDL: %s\n", SDL_GetError());
		return;
	}
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_SWAP_CONTROL, 1);

	SDL_putenv("SDL_VIDEO_CENTERED=center");

	if (fullscreen) {
		flags |= SDL_FULLSCREEN;
	}

	surface = SDL_SetVideoMode(width, height, 32, flags);
	SDL_WM_SetCaption(caption.c_str(), NULL);

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
	} else {
		last->previous = last;
		last = &ent;
	}
}

void Game::removeEntity(Entity& ent) {
	if (&ent == first) {
		first = ent.next;
		ent.next->previous = NULL;
	} else if (&ent == last) {
		last = ent.previous;
		ent.previous->next = NULL;
	} else {
		ent.next->previous = ent.previous;
		ent.previous->next = ent.next;
	}

	ent.previous = NULL;
	ent.next = NULL;
	// Make sure to delete when you're done with it!
}

void Game::setCaption(const char* cap) {
	caption = cap;
	if (initialized) {
		SDL_WM_SetCaption(caption.c_str(), NULL);
	}
}

void Game::run() {
	Entity* itr;
	int before, after, diff;
	SDL_Event evt;

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
