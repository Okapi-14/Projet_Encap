#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape sprite;

public:
    Entity(float x = 0, float y = 0, float width = 50.f, float height = 50.f);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    const sf::Vector2f& getPosition() const;
    const sf::RectangleShape& getSprite() const;
};

#endif // ENTITY_H
