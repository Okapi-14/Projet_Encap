#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape sprite; // Centralise le sprite

public:
    Entity(float width = 30.f, float height = 30.f, sf::Color color = sf::Color::White);

    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window);

    sf::RectangleShape& getSprite();
    const sf::RectangleShape& getSprite() const;

    void setPosition(float x, float y);
};

#endif
