#include <SFML/Graphics.hpp>
#include "Player.h"

class Interactable {
protected:
    sf::RectangleShape sprite; // Sprite de l'objet interactable

public:
    virtual ~Interactable() = default;
    virtual void interact(Player& player) = 0;      // M�thode virtuelle pure
    const sf::RectangleShape& getSprite() const {  // Acc�s au sprite
        return sprite;
    }
};
