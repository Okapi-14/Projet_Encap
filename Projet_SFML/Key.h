#ifndef KEY_H
#define KEY_H

#include "Interactable.h"
#include "Player.h"

class Key : public Interactable {
private:
    bool collected;

public:
    Key();

    void interact(Player& player) override; // Interaction avec le joueur
    void draw(sf::RenderWindow& window) const override; // Affichage
};

#endif // KEY_H
