#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
private:
    float speed;

public:
    Player(float x = 0, float y = 0, float speed = 200.f);
    void handleInput(float deltaTime);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // PLAYER_H
