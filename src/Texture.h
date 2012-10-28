#pragma once

#include <string>
#include <SDL.h>

using namespace std;

class Texture {
public:
    Texture(const char* path);
    Texture(SDL_Surface& surface);
    ~Texture();

    void bind();

    bool isBound() {
        return bound;
    }
    string getSource() {
        return source;
    }
    unsigned int getWidth() {
        return width;
    }
    unsigned int getHeight() {
        return height;
    }

    static void unbindTexture();

private:


    SDL_Surface* surface;
    bool bound;
    unsigned int name;
    string source;
    unsigned int width;
    unsigned int height;

    void _loadTexture(SDL_Surface& surface);
};
