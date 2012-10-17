#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h) :
	position(x, y),
	dimensions(w, h) {
	
}

Rectangle::Rectangle(const Vector2f& pos, const Vector2f& dim) :
	position(pos),
	dimensions(dim) {
	
}

float Rectangle::minX() {
	return position.x;
}

float Rectangle::maxX() {
	return position.x + dimensions.x;
}

float Rectangle::minY() {
	return position.y;
}

float Rectangle::maxY() {
	return position.y + dimensions.y;
}

bool Rectangle::overlapping(Rectangle& other) {
	if (maxX() < other.minX() ||
		minX() > other.maxX() ||
		maxY() < other.minY() ||
		minY() > other.maxY()) {
			return false;
	}
	return true;
}

Vector2f Rectangle::collideWith(Rectangle& other) {
	Vector2f ret(0, 0);

	return ret;
}