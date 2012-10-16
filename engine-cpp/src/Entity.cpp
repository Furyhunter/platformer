#include "Entity.h"


Entity::Entity(void) {
	
}


Entity::~Entity(void) {
	// delink from linked list
	next->previous = previous;
	previous->next = next;
}
