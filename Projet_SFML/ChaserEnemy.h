#ifndef CHASER_ENEMY_H
#define CHASER_ENEMY_H

#include "Enemy.h"
#include "Player.h"

class ChaserEnemy : public Enemy {
private:
    float speed;
    const Player* targetPlayer;

public:
    ChaserEnemy(float x, float y, float speed = 100.f);
    void update(float deltaTime) override; // Implémente la méthode virtuelle pure
    void updateWithPlayer(float deltaTime, const Player& player);
    void setTarget(const Player* player) {
        targetPlayer = player;
    }
};

#endif // CHASER_ENEMY_H
