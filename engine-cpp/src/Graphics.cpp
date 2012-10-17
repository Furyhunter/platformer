#include "Graphics.h"

#include <SDL_opengl.h>

void Graphics::setColor(const Color& c) {
	color = c;
	_setGlColor();
}

void Graphics::drawRect(float x, float y, float w, float h) {
	glPolygonMode(GL_FRONT, GL_LINE);
	fillRect(x, y, w, h);
	glPolygonMode(GL_FRONT, GL_FILL);
}

void Graphics::fillRect(float x, float y, float w, float h) {
	static float verts[8] = {0, 0, 0, 1, 1, 0, 1, 1};

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glScalef(w, h, 1);
	glDrawArrays(GL_QUADS, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
}

void Graphics::_setGlColor() {
	if (color.a < 1) {
		glEnable(GL_BLEND);
	} else {
		glDisable(GL_BLEND);
	}
	glColor4f(color.r, color.g, color.b, color.a);
}
