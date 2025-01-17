#include "Entity.h"

Entity::Entity(float x, float y, float vitesse) : vitesse(vitesse) {
    sprite.setSize({ 50.f, 50.f });
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(x, y);
}

void Entity::update(float deltaTime) {
    // Par défaut, rien n'est fait ici
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

const sf::Vector2f& Entity::getPosition() const {
    return sprite.getPosition();
}
