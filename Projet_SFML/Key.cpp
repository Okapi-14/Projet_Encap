#include "Key.h"

Key::Key() : collected(false) {
    sprite.setSize({ 32.f, 32.f });
    sprite.setFillColor(sf::Color::Yellow); // Couleur jaune par défaut
}

void Key::interact(Player& player) {
    if (!collected) {
        player.addKey(); // Ajoute une clé dans l'inventaire du joueur
        collected = true;
        sprite.setFillColor(sf::Color::Transparent); // Rendre la clé invisible
    }
}

void Key::draw(sf::RenderWindow& window) const {
    if (!collected) {
        window.draw(sprite); // Affiche uniquement si elle n'est pas collectée
    }
}
