#pragma once

#include "Vector2f.h"

class Game;
class Graphics;

class Entity {
public:
    friend class Game;
    Vector2f position;

    Entity();
    Entity(float x, float y);
    Entity(const Vector2f& position);
    ~Entity();

    virtual void create(Game& game) = 0;
    virtual void step(Game& game, float delta) = 0;
    virtual void draw(Game& game, Graphics& graphics) = 0;
    virtual void destroy(Game& game) = 0;
    virtual void collide() = 0;
private:
    Entity* next;
    Entity* previous;
};

