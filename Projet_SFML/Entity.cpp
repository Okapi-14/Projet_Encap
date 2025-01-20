#include "Entity.h"

Entity::Entity(float x, float y, float width, float height) {
    sprite.setSize({ width, height });
    sprite.setPosition(x, y);
}

const sf::Vector2f& Entity::getPosition() const {
    return sprite.getPosition();
}

const sf::RectangleShape& Entity::getSprite() const {
    return sprite;
}
