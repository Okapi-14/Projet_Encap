#include "Key.h"

Key::Key() : collected(false) {
    sprite.setSize({ 32.f, 32.f });
    sprite.setFillColor(sf::Color::Yellow); // Couleur jaune par d�faut
}

void Key::interact(Player& player) {
    if (!collected) {
        player.addKey(); // Ajoute une cl� dans l'inventaire du joueur
        collected = true;
        sprite.setFillColor(sf::Color::Transparent); // Rendre la cl� invisible
    }
}

void Key::draw(sf::RenderWindow& window) const {
    if (!collected) {
        window.draw(sprite); // Affiche uniquement si elle n'est pas collect�e
    }
}
