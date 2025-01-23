#ifndef KEY_H
#define KEY_H

#include <SFML/Graphics.hpp>
#include "Interactable.h"

class Key : public Entity, public Interactable {
private:
    bool collected;

public:
    Key();

    void interact(Player& player) override;
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    sf::RectangleShape& getSprite(); // M�thode non-constante pour permettre les modifications

    const sf::RectangleShape& getSprite() const; // M�thode constante pour les acc�s en lecture
};

#endif
