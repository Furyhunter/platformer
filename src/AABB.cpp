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