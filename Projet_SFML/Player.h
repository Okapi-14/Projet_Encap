#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
private:
    float speed;  
    int keys = 0; 

public:
    Player(float x = 0, float y = 0, float speed = 200.f);
    void handleInput(float deltaTime);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void increaseSpeed(float amount);
    void addKey();
    bool hasKey() const;

};

#endif // PLAYER_H
