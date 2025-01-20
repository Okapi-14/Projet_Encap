#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "ChaserEnemy.h"
#include "Utils.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Game");
    window.setFramerateLimit(60);

    Player player(100, 100);
    std::vector<ChaserEnemy> enemies = {
        ChaserEnemy(400, 300),
        ChaserEnemy(200, 100),
    };

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Mise à jour du joueur
        player.update(deltaTime);

        // Mise à jour des ennemis
        for (auto& enemy : enemies) {
            enemy.update(deltaTime, player);
            if (checkCollision(player.getSprite(), enemy.getSprite())) {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }
        }

        // Rendu
        window.clear();
        player.draw(window);
        for (const auto& enemy : enemies) {
            enemy.draw(window);
        }
        window.display();
    }

    return 0;
}
