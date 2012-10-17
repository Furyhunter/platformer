#include "Entity.h"

#include "Game.h"

Entity::Entity() : position(0, 0) {
	
}

Entity::Entity(float x, float y) : position(x, y) {

}

Entity::Entity(const Vector2f& pos) : position(pos) {

}

Entity::~Entity() {
	next->previous = previous;
	previous->next = next;
}
