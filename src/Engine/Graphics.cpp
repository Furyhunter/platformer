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

#include "Graphics.h"

#include <SDL_opengl.h>

#include "Texture.h"
#include "AABB.h"
#include "exmath.h"

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

    if (roundCoordinates) {
        x = roundToInt(x);
        y = roundToInt(y);
        w = roundToInt(w);
        h = roundToInt(h);
    }

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
    if (roundCoordinates) {
        glTranslatef(roundToInt(translation.x), roundToInt(translation.y), 0);
    } else {
        glTranslatef(translation.x, translation.y, 0);
    }
}
