/* platformer
 * Copyright (c) 2012, Ronald Kinard
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  * Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 * 
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "Game.h"

#include <SDL_opengl.h>

#include "Entity.h"
#include "Texture.h"

Game::Game(unsigned int width, unsigned int height, unsigned int iWidth,
           unsigned int iHeight) {
    surface = NULL;
    initialized = false;
    running = false;
    this->width = width;
    this->height = height;
    internalWidth = iWidth;
    internalHeight = iHeight;
    fullscreen = false;
    caption = "";
    first = 0;
    last = 0;
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
    if (first == 0) {
        first = &ent;
        last = first;
    } else {
        last->next = &ent;
        ent.prev = last;
        last = &ent;
    }
}

bool Game::removeEntity(Entity& ent) {
    Entity* itr = first;

    if (first == 0) {
        return false;
    }

    while (itr != 0) {
        if (itr == &ent) {
            if (itr == first) {
                first = first->next;
            } else if (itr == last) {
                last = last->prev;
            } else {
                itr->prev->next = itr->next;
                itr->next->prev = itr->prev;
            }

            itr->prev = 0;
            itr->next = 0;
            return true;
        }
        itr = itr->next;
    }

    return false;

    // delete when done with it!
}

void Game::setCaption(const char* cap) {
    caption = cap;
    if (initialized) {
        SDL_WM_SetCaption(caption.c_str(), NULL);
    }
}

void Game::run() {
    int before, after, diff;
    SDL_Event evt;
    Entity* itr;

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
        while (itr != 0) {
            itr->step(*this, 1.f/60);
            itr = itr->next;
        }

        // draw step
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, internalWidth, internalHeight, 0, -1, 1);

        itr = first;
        while (itr != 0) {
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
