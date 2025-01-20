#include "PatrollingEnemy.h"
#include <cmath>

PatrollingEnemy::PatrollingEnemy(float x1, float y1, float x2, float y2, float speed)
    : Enemy(x1, y1), pointA(x1, y1), pointB(x2, y2), speed(speed) {
    direction = pointB - pointA;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length; // Normalise le vecteur
    }
}

void PatrollingEnemy::update(float deltaTime) {
    sprite.move(direction * speed * deltaTime);

    // Vérifie si l'ennemi a atteint le point A ou B, et inverse la direction
    sf::Vector2f position = sprite.getPosition();
    if ((direction.x > 0 && position.x >= pointB.x) || (direction.x < 0 && position.x <= pointA.x)) {
        direction = -direction; // Inverse la direction
    }
    if ((direction.y > 0 && position.y >= pointB.y) || (direction.y < 0 && position.y <= pointA.y)) {
        direction = -direction; // Inverse la direction
    }
}
