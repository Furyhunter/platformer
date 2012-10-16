#pragma once

class Entity {
public:
	Entity* next;

	Entity(void);
	~Entity(void);
	
	virtual void create() = 0;
	virtual void step() = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
};

