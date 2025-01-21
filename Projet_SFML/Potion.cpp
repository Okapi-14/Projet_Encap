#include "Potion.h"
#include <iostream>

Potion::Potion(float boost) : speedBoost(boost), isConsumed(false) {
    // Initialisation du sprite
    sprite.setSize({ 30.f, 30.f });                 // Taille visible
    sprite.setFillColor(sf::Color::Blue);         // Couleur bleue pour les potions
    sprite.setPosition(200.f, 200.f);             // Position visible dans la fenêtre
}

void Potion::interact(Player& player) {
    if (!isConsumed) {
        player.increaseSpeed(speedBoost);         // Augmente la vitesse du joueur
        isConsumed = true;
        sprite.setFillColor(sf::Color::Transparent); // Rend la potion invisible
        std::cout << "Potion consommée ! Vitesse augmentée de " << speedBoost << std::endl;
    }
}
