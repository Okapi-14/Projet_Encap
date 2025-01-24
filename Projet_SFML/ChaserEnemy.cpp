#include "ChaserEnemy.h"
#include <cmath>

ChaserEnemy::ChaserEnemy(float x, float y, float speed) : Enemy(x, y), speed(speed) {}

void ChaserEnemy::update(float deltaTime){
    if (targetPlayer) {
        updateWithPlayer(deltaTime, *targetPlayer); // Appelle updateWithPlayer avec la cible
    }
}

void ChaserEnemy::updateWithPlayer(float deltaTime, const Player& player) {
    sf::Vector2f direction = player.getPosition() - sprite.getPosition(); // Utilise getPosition de Player
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0) {
        direction /= length;
    }

    sprite.move(direction * speed * deltaTime);
}
