#ifndef CHASER_ENEMY_H
#define CHASER_ENEMY_H

#include "Enemy.h"
#include "Player.h"

class ChaserEnemy : public Enemy {
private:
    float speed;

public:
    ChaserEnemy(float x, float y, float speed = 100.f);
    void update(float deltaTime, const Player& player) override;
};

#endif // CHASER_ENEMY_H
