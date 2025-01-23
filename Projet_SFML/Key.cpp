#include "Key.h"

Key::Key() : collected(false) {
    sprite.setFillColor(sf::Color::Yellow);
}

void Key::interact(Player& player) {
    if (!collected) {
        player.addKey();
        collected = true;
        sprite.setFillColor(sf::Color::Transparent);
    }
}

void Key::update(float deltaTime) {
    // Pas d'update spécifique pour l'instant
}
