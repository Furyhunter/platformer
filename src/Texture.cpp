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

#include "Texture.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

Texture* currentlyBoundTexture = NULL;

Texture::Texture(const char* path) {
    bound = false;
    name = -1;
    source = path;

    surface = IMG_Load(path);
    width = surface->w;
    height = surface->h;
    _loadTexture(*surface);
}

Texture::Texture(SDL_Surface& surface) {
    bound = false;
    name = -1;
    source = "";

    this->surface = &surface;
    width = surface.w;
    height = surface.h;
    _loadTexture(surface);
}

Texture::~Texture() {
    glDeleteTextures(1, &name);
    SDL_FreeSurface(surface);
}

void Texture::bind() {
    if (name >= 0 && !bound) {
        glBindTexture(GL_TEXTURE_2D, name);
        if (currentlyBoundTexture != NULL) {
            currentlyBoundTexture->bound = false;
        }
        currentlyBoundTexture = this;
        bound = true;
    }
}

void Texture::_loadTexture(SDL_Surface& surface) {
    int internal_format;
    int pixel_format;
    Texture* lastBound = NULL;

    // gen texture
    glGenTextures(1, &name);
    if (currentlyBoundTexture != NULL) {
        lastBound = currentlyBoundTexture;
    }
    bind();

    // load texture
    switch (surface.format->BitsPerPixel) {
    case 24:
        internal_format = 3;
        pixel_format = GL_RGB;
        break;
    case 32:
        internal_format = 4;
        pixel_format = GL_RGBA;
        break;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, surface.w,
                 surface.h, 0, pixel_format, GL_UNSIGNED_BYTE, surface.pixels);

    // rebind last bound if exists
    if (lastBound != NULL) {
        lastBound->bind();
    }
}

void Texture::unbindTexture() {
    glBindTexture(GL_TEXTURE_2D, 0);
    if (currentlyBoundTexture != NULL) {
        currentlyBoundTexture->bound = false;
        currentlyBoundTexture = NULL;
    }
}
