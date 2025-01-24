#ifndef POTION_H
#define POTION_H

#include "Interactable.h"
#include "Player.h"

class Potion : public Interactable {
private:
    float boost;
    bool consumed;

public:
    Potion(float boost = 10.0f);

    void interact(Player& player) override; // Interaction avec le joueur
    void draw(sf::RenderWindow& window) const override; // Affichage
};

#endif // POTION_H
