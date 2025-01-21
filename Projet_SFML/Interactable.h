#include <SFML/Graphics.hpp>
#include "Player.h"

class Interactable {
protected:
    sf::RectangleShape sprite; // Sprite de l'objet interactable

public:
    virtual ~Interactable() = default;
    virtual void interact(Player& player) = 0;      // Méthode virtuelle pure
    const sf::RectangleShape& getSprite() const {  // Accès au sprite
        return sprite;
    }
};
