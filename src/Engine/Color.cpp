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

#include "Color.h"

#include <cmath>

#include "exmath.h"

Color::Color(float r, float g, float b, float a = 1.f) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

int Color::getRed() {
    return roundToInt(r * 255);
}

int Color::getGreen() {
    return roundToInt(g * 255);
}

int Color::getBlue() {
    return roundToInt(b * 255);
}

int Color::getAlpha() {
    return roundToInt(a * 255);
}

Color& Color::operator=(const Color& c) {
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
    return *this;
}

bool Color::operator==(const Color& c) {
    if (r == c.r && b == c.b && g == c.g && a == c.a) {
        return true;
    }

    return false;
}
