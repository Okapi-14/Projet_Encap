#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <SFML/Graphics.hpp>

class Interactable {
protected:
    sf::RectangleShape sprite;

public:
    virtual ~Interactable() = default;

    virtual void draw(sf::RenderWindow& window) const {
        window.draw(sprite);
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    sf::Vector2f getPosition() const {
        return sprite.getPosition();
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }
};

#endif // INTERACTABLE_H
