#include "Entity.h"

#include "Game.h"
#include "Graphics.h"

Entity::Entity() : position(0, 0) {
	next = NULL;
	previous = NULL;
}

Entity::Entity(float x, float y) : position(x, y) {

}

Entity::Entity(const Vector2f& pos) : position(pos) {

}
