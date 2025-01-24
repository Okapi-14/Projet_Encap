#include "Player.h"
#include "Config.h"
#include <iostream>
#include "Key.h"
#include "Potion.h"

Player::Player(float x, float y, float speed) : Entity(x, y), speed(speed) {
    sprite.setPosition(1900, 1000);
    sprite.setFillColor(sf::Color::Green);
}

void Player::handleInput(float deltaTime, const Map& map) {
    float moveSpeed = speed * deltaTime;
    sf::Vector2f oldPosition = sprite.getPosition(); // Sauvegarde la position actuelle

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        sprite.move(-moveSpeed, 0); // Déplace à gauche
        if (map.isWallCollision(sprite.getGlobalBounds())) {
            sprite.setPosition(oldPosition); // Restaure la position si collision
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(moveSpeed, 0); // Déplace à droite
        if (map.isWallCollision(sprite.getGlobalBounds())) {
            sprite.setPosition(oldPosition);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        sprite.move(0, -moveSpeed); // Déplace vers le haut
        if (map.isWallCollision(sprite.getGlobalBounds())) {
            sprite.setPosition(oldPosition);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, moveSpeed); // Déplace vers le bas
        if (map.isWallCollision(sprite.getGlobalBounds())) {
            sprite.setPosition(oldPosition);
        }
    }
}


void Player::update(float deltaTime) {
    handleInput(deltaTime);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::increaseSpeed(float boost) {
    speed += boost; 
    std::cout << "Vitesse augmentée à : " << speed << std::endl;
}

void Player::addKey() {
    keys++;
    std::cout << "Clé ajoutée ! Nombre de clés : " << keys << std::endl;
}
