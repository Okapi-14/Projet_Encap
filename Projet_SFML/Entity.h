#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape sprite;
    float vitesse;

public:
    Entity(float x = 0, float y = 0, float vitesse = 200.f);
    virtual ~Entity() = default;

    virtual void handleInput(float deltaTime) = 0;
    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    const sf::Vector2f& getPosition() const;
};

#endif // ENTITY_H
