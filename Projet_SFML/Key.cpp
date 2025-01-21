#include "Key.h"
#include <iostream>

Key::Key() : isCollected(false) {
    // Initialisation du sprite
    sprite.setSize({ 30.f, 30.f });                 // Taille visible
    sprite.setFillColor(sf::Color::Yellow);       // Couleur jaune pour les clés
    sprite.setPosition(400.f, 400.f);             // Position visible dans la fenêtre
}

void Key::interact(Player& player) {
    if (!isCollected) {
        player.addKey();                          // Ajoute une clé à l'inventaire du joueur
        isCollected = true;
        sprite.setFillColor(sf::Color::Transparent); // Rend la clé invisible
        std::cout << "Clé ramassée !" << std::endl;
    }
}
