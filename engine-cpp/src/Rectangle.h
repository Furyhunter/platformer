#pragma once

#include "Vector2f.h"

class Rectangle {
public:
	Rectangle(float x, float y, float w, float h);
	Rectangle(const Vector2f& pos, const Vector2f& dim);

	// Top left corner
	Vector2f position;
	// Width and height (not halfs)
	Vector2f dimensions;

	float minX();
	float maxX();
	float minY();
	float maxY();
	bool Rectangle::overlapping(Rectangle& other);
	Vector2f collideWith(Rectangle& other);
};