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