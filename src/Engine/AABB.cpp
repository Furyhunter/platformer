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

#include "AABB.h"

AABB::AABB(float x, float y, float w, float h) :
    position(x, y),
    dimensions(w, h) {

}

AABB::AABB(const Vector2f& pos, const Vector2f& dim) :
    position(pos),
    dimensions(dim) {

}

float AABB::minX() {
    return position.x;
}

float AABB::maxX() {
    return position.x + dimensions.x;
}

float AABB::minY() {
    return position.y;
}

float AABB::maxY() {
    return position.y + dimensions.y;
}

bool AABB::overlapping(AABB& other) {
    if (maxX() < other.minX() ||
            minX() > other.maxX() ||
            maxY() < other.minY() ||
            minY() > other.maxY()) {
        return false;
    }
    return true;
}

Vector2f AABB::collideWith(AABB& other) {
    Vector2f ret(0, 0);

    return ret;
}
