#include "Graphics.h"

#include <SDL_opengl.h>

#include "Texture.h"
#include "AABB.h"

Graphics::Graphics() : color(1, 1, 1, 1) {
	_setGlColor();
}

void Graphics::setColor(const Color& c) {
	color = c;
	_setGlColor();
}

void Graphics::drawRect(float x, float y, float w, float h) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	fillRect(x, y, w, h);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Graphics::drawRect(const AABB& r) {
	drawRect(r.position.x, r.position.y, r.dimensions.x, r.dimensions.y);
}

void Graphics::fillRect(float x, float y, float w, float h) {
	static float verts[8] = {0, 0, 0, 1, 1, 1, 1, 0};
	static float tex[8] = {0, 0, 0, 1, 1, 1, 1, 0};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	_translateVector();
	glTranslatef(x, y, 0);
	glScalef(w, h, 1);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Graphics::fillRect(const AABB& r) {
	fillRect(r.position.x, r.position.y, r.dimensions.x, r.dimensions.y);
}

void Graphics::drawTexture(float x, float y, Texture& texture) {
	glEnable(GL_TEXTURE_2D);
	texture.bind();
	fillRect(x, y, texture.getWidth(), texture.getHeight());
	glDisable(GL_TEXTURE_2D);
}

void Graphics::drawTexture(float x, float y, float w, float h, unsigned int glName) {
	glEnable(GL_TEXTURE_2D);
	Texture::unbindTexture();
	glBindTexture(GL_TEXTURE_2D, glName);
	fillRect(x, y, w, h);
	glDisable(GL_TEXTURE_2D);
}

void Graphics::_setGlColor() {
	if (color.a < 1) {
		glEnable(GL_BLEND);
	} else {
		glDisable(GL_BLEND);
	}
	glColor4f(color.r, color.g, color.b, color.a);
}

void Graphics::_translateVector() {
	glTranslatef(translation.x, translation.y, 0);
}