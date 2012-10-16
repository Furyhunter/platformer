#pragma once

class Entity {
public:
	Entity* next;
	Entity* previous;

	Entity(void);
	~Entity(void);
	
	virtual void create();
	virtual void step();
	virtual void draw();
	virtual void destroy();
};

