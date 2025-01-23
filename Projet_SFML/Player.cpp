#include "Player.h"
#include "Config.h"
#include <iostream>
#include "Key.h"
#include "Potion.h"

Player::Player(float x, float y, float speed) : Entity(x, y), speed(speed) {
    sprite.setFillColor(sf::Color::Green);
}

void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sprite.getPosition().x > 0) {
        sprite.move(-speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x + sprite.getSize().x < WINDOW_WIDTH) {
        sprite.move(speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sprite.getPosition().y > 0) {
        sprite.move(0, -speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite.getPosition().y + sprite.getSize().y < WINDOW_HEIGHT) {
        sprite.move(0, speed * deltaTime);
    }
}

void Player::update(float deltaTime) {
    handleInput(deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Augmente la vitesse du joueur
void Player::increaseSpeed(float amount) {
    speed += amount;
    std::cout << "Nouvelle vitesse : " << speed << std::endl;
}

// Ajoute une clé à l'inventaire
void Player::addKey() {
    keys++;
    std::cout << "Clés : " << keys << std::endl;
}

// Vérifie si le joueur possède une clé
bool Player::hasKey() const {
    return keys > 0;
}