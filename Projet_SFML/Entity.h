#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::RectangleShape sprite; 

public:
    Entity(float width = 30.f, float height = 30.f, sf::Color color = sf::Color::White);
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window);

    void setSpriteSize(float width, float height);

    void setPosition(float x, float y) {
        sprite.setPosition(x, y); 
    }

    void setSpriteSize(float width, float height) {
        sprite.setSize({ width, height }); 
    }

    const sf::RectangleShape& getSprite() const {
        return sprite;
    }

    sf::Vector2f getPosition() const { return sprite.getPosition(); } 
    void setPosition(float x, float y) { sprite.setPosition(x, y); }  
};

#endif // ENTITY_H
