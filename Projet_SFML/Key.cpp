#include "Key.h"
#include <iostream>

Key::Key() : isCollected(false) {
    // Initialisation du sprite
    sprite.setSize({ 30.f, 30.f });                 // Taille visible
    sprite.setFillColor(sf::Color::Yellow);       // Couleur jaune pour les cl�s
    sprite.setPosition(400.f, 400.f);             // Position visible dans la fen�tre
}

void Key::interact(Player& player) {
    if (!isCollected) {
        player.addKey();                          // Ajoute une cl� � l'inventaire du joueur
        isCollected = true;
        sprite.setFillColor(sf::Color::Transparent); // Rend la cl� invisible
        std::cout << "Cl� ramass�e !" << std::endl;
    }
}
