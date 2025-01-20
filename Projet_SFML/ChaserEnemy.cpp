#include "ChaserEnemy.h"
#include <cmath>

ChaserEnemy::ChaserEnemy(float x, float y, float speed) : Enemy(x, y), speed(speed) {}

void ChaserEnemy::update(float deltaTime) {
}

void ChaserEnemy::updateWithPlayer(float deltaTime, const Player& player) {
    sf::Vector2f direction = player.getPosition() - sprite.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0) {
        direction /= length;
    }

    sprite.move(direction * speed * deltaTime);
}
