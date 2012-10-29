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

#include "Vector2f.h"

#include <cmath>

Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f(const Vector2f& d) {
    this->x = d.x;
    this->y = d.y;
}

float Vector2f::length() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2f& Vector2f::operator=(const Vector2f& r) {
    x = r.x;
    y = r.y;
    return *this;
}

Vector2f Vector2f::operator+(const Vector2f& r) {
    Vector2f ret(x, y);
    ret.x += r.x;
    ret.y += r.y;
    return ret;
}

Vector2f Vector2f::operator-(const Vector2f& r) {
    Vector2f ret(x, y);
    ret.x -= r.x;
    ret.y -= r.y;
    return ret;
}

Vector2f Vector2f::operator*(float r) {
    Vector2f ret(x, y);
    ret.x *= r;
    ret.y *= r;
    return ret;
}

Vector2f Vector2f::operator/(float r) {
    Vector2f ret(x, y);
    ret.x /= r;
    ret.y /= r;
    return ret;
}

Vector2f& Vector2f::operator+=(const Vector2f& r) {
    x += r.x;
    y += r.y;
    return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& r) {
    x -= r.x;
    y -= r.y;
    return *this;
}

Vector2f& Vector2f::operator*=(float r) {
    x *= r;
    y *= r;
    return *this;
}

Vector2f& Vector2f::operator/=(float r) {
    x /= r;
    y /= r;
    return *this;
}

bool Vector2f::operator==(const Vector2f& r) {
    if (x == r.x && y == r.y) {
        return true;
    }
    return false;
}
