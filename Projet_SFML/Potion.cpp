#include "Potion.h"

Potion::Potion(float boost) : boost(boost), consumed(false) {
    sprite.setSize({ 30.f, 30.f });
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(0.f, 0.f);
}

void Potion::interact(Player& player) {
    if (!consumed) {
        player.increaseSpeed(boost);
        consumed = true;
        sprite.setFillColor(sf::Color::Transparent); // Rendre la potion invisible
    }
}

void Potion::drawAll(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::RectangleShape& Potion::getSprite() {
    return sprite;
}

const sf::RectangleShape& Potion::getSprite() const {
    return sprite;
}
