#include "Potion.h"
#include <iostream>

Potion::Potion(float boost) : speedBoost(boost), isConsumed(false) {
    sprite.setSize({ 30.f, 30.f });
    sprite.setFillColor(sf::Color::Blue);
    sprite.setPosition(200.f, 200.f);
}

void Potion::interact(Player& player) {
    if (!isConsumed) {
        player.increaseSpeed(speedBoost);
        isConsumed = true;
        sprite.setFillColor(sf::Color::Transparent);
        std::cout << "Potion consommée ! Vitesse augmentée de " << speedBoost << std::endl;
    }
}
