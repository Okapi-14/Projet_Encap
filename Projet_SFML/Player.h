#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player(float x = 0, float y = 0, float vitesse = 200.f);
    void handleInput(float deltaTime) override;
    void update(float deltaTime) override;
};

#endif // PLAYER_H
