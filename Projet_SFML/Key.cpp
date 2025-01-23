#include "Key.h"

Key::Key() : collected(false) {
    sprite.setSize({ 30.f, 30.f });
    sprite.setFillColor(sf::Color::Yellow);
    sprite.setPosition(0.f, 0.f);
}

void Key::interact(Player& player) {
    if (!collected) {
        player.addKey();
        collected = true;
        sprite.setFillColor(sf::Color::Transparent); 
    }
}

void Key::update(float deltaTime) {
}

void Key::draw(sf::RenderWindow& window) {
    window.draw(spriteI);
}

sf::RectangleShape& Key::getSprite() {
    return spriteI;
}

const sf::RectangleShape& Key::getSprite() const {
    return spriteI;
}
