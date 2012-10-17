#pragma once

#include "Vector2f.h"

class Entity {
public:
	Entity* next;
	Entity* previous;
	Vector2f position;

	Entity();
	Entity(float x, float y);
	Entity(const Vector2f& position);
	~Entity();
	
	virtual void create() = 0;
	virtual void step() = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
	virtual void collide() = 0;
};

