#include <SFML/Graphics.hpp>
#include "Player.h"

class Interactable {
protected:
    sf::RectangleShape sprite;

public:
    virtual ~Interactable() = default;
    virtual void interact(Player& player) = 0;
    const sf::RectangleShape& getSprite() const { return sprite; }
};
