#include "Entity.h"

Entity::Entity(float width, float height, sf::Color color) {
    sprite.setSize({ width, height });
    sprite.setFillColor(color);
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::RectangleShape& Entity::getSprite() {
    return sprite;
}

const sf::RectangleShape& Entity::getSprite() const {
    return sprite;
}

void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
