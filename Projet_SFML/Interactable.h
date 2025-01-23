#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include <SFML/Graphics.hpp>
#include "Player.h"

class Interactable {
protected:
    sf::RectangleShape spriteI; 

public:
    virtual ~Interactable() = default;
    virtual void interact(Player& player) = 0;   
    const sf::RectangleShape& getSprite() const { 
        return spriteI;
    }
};

#endif
