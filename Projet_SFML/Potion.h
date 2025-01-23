#ifndef POTION_H
#define POTION_H

#include <SFML/Graphics.hpp>
#include "Interactable.h"

class Potion : public Entity, public Interactable {
private:
    float boost;
    bool consumed;

public:
    Potion(float boost);

    void interact(Player& player) override;
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getSprite(); // M�thode non-constante pour permettre les modifications

    const sf::RectangleShape& getSprite() const; // M�thode constante pour les acc�s en lecture
};

#endif
