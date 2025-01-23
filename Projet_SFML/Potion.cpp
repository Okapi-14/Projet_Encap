#include "Potion.h"

Potion::Potion(float boost) : boost(boost), consumed(false) {
    sprite.setFillColor(sf::Color::Blue);
}

void Potion::interact(Player& player) {
    if (!consumed) {
        player.increaseSpeed(boost);
        consumed = true;
        sprite.setFillColor(sf::Color::Transparent);
    }
}

void Potion::update(float deltaTime) {
    // Pas d'update spécifique pour l'instant
}
