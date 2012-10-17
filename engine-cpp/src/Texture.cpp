#include "Texture.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

Texture::Texture(const char* path) {
	bound = false;
	name = -1;
	source = path;

	surface = IMG_Load(path);
	_loadTexture(*surface);
}

Texture::Texture(SDL_Surface& surface) {
	bound = false;
	name = -1;
	source = "";

	this->surface = &surface;
	_loadTexture(surface);
}

Texture::~Texture() {
	glDeleteTextures(1, &name);
	SDL_FreeSurface(surface);
}

void Texture::bind() {
	if (name >= 0 && !bound) {
		glBindTexture(GL_TEXTURE_2D, name);
		currentlyBound->bound = false;
		currentlyBound = this;
		bound = true;
	}
}

void Texture::_loadTexture(SDL_Surface& surface) {
	int internal_format;
	int pixel_format;
	Texture* lastBound;

	// gen texture
	glGenTextures(1, &name);
	if (currentlyBound != NULL) {
		lastBound = currentlyBound;
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