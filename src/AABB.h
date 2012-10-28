#pragma once

#include "Vector2f.h"

class AABB {
public:
    AABB(float x, float y, float w, float h);
    AABB(const Vector2f& pos, const Vector2f& dim);

    // Top left corner
    Vector2f position;
    // Width and height (not halfs)
    Vector2f dimensions;

    float minX();
    float maxX();
    float minY();
    float maxY();
    bool overlapping(AABB& other);
    Vector2f collideWith(AABB& other);
};
