#ifndef PATROLLING_ENEMY_H
#define PATROLLING_ENEMY_H

#include "Enemy.h"

class PatrollingEnemy : public Enemy {
private:
    sf::Vector2f pointA;
    sf::Vector2f pointB;
    sf::Vector2f direction;
    float speed;

public:
    PatrollingEnemy(float x1, float y1, float x2, float y2, float speed = 100.f);
    void update(float deltaTime) override;
};

#endif // PATROLLING_ENEMY_H
