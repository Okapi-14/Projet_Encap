#include "Entity.h"

Entity::Entity(float width, float height, sf::Color color) {
    sprite.setSize({ width, height });
    sprite.setFillColor(color);
}

void Entity::setSpriteSize(float width, float height) {
    sprite.setSize({ width, height });
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


