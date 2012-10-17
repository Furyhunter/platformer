#pragma once

#include <string>

using namespace std;

class Texture {
public:
	Texture(const char* path);
	Texture::Texture(SDL_Surface& surface);
	~Texture();

	void bind();

	bool isBound() { return bound; }
	string getSource() { return source; }
private:
	SDL_Surface* surface;
	bool bound;
	unsigned int name;
	string source;

	void _loadTexture(SDL_Surface& surface);

	static Texture* currentlyBound;
};