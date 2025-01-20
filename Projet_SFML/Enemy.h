#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
    Enemy(float x, float y);
    virtual void update(float deltaTime) override = 0;
    void draw(sf::RenderWindow& window) override;
};

#endif // ENEMY_H
