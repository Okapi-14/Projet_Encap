#include "Player.h"
#include "Config.h"

Player::Player(float x, float y, float vitesse) : Entity(x, y, vitesse) {
    sprite.setFillColor(sf::Color::Green); // Couleur spécifique au joueur
}

void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sprite.getPosition().x > 0) {
        sprite.move(-vitesse * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x + sprite.getSize().x < WINDOW_WIDTH) {
        sprite.move(vitesse * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sprite.getPosition().y > 0) {
        sprite.move(0, -vitesse * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite.getPosition().y + sprite.getSize().y < WINDOW_HEIGHT) {
        sprite.move(0, vitesse * deltaTime);
    }
}

void Player::update(float deltaTime) {
    handleInput(deltaTime);
}
