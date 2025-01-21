#include "Key.h"
#include <iostream>

Key::Key() : isCollected(false) {
    sprite.setSize({ 30.f, 30.f });
    sprite.setFillColor(sf::Color::Yellow);
    sprite.setPosition(400.f, 400.f);
}

void Key::interact(Player& player) {
    if (!isCollected) {
        player.addKey();
        isCollected = true;
        sprite.setFillColor(sf::Color::Transparent);
        std::cout << "Clé ramassée !" << std::endl;
    }
}
