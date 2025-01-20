#include "Enemy.h"

Enemy::Enemy(float x, float y) : Entity(x, y) {
    sprite.setFillColor(sf::Color::Red);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
