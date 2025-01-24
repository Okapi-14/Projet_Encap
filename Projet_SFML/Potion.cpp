#include "Potion.h"

Potion::Potion(float boost) : boost(boost), consumed(false) {
    sprite.setSize({ 32.f, 32.f });
    sprite.setFillColor(sf::Color::Blue); // Couleur bleue par défaut
}

void Potion::interact(Player& player) {
    if (!consumed) {
        player.increaseSpeed(boost); // Augmente la vitesse du joueur
        consumed = true;
        sprite.setFillColor(sf::Color::Transparent); // Rendre la potion invisible
    }
}

void Potion::draw(sf::RenderWindow& window) const {
    if (!consumed) {
        window.draw(sprite); // Affiche uniquement si elle n'est pas consommée
    }
}
