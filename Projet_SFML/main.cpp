#include <SFML/Graphics.hpp>
#include <iostream>
#include "PatrollingEnemy.h"
#include "Potion.h"
#include "Key.h"
#include "EntityManager.h"
#include "InteractableManager.h"
#include "config.h"
#include "map.h"
#include "Utils.h"

enum class GameState {
    Playing,
    GameOver
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jeu");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("assets/bones.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }

    GameState gameState = GameState::Playing;
    EntityManager entityManager;
    InteractableManager interactableManager;

    // Chargement de la carte
    Map gameMap(WINDOW_WIDTH, WINDOW_HEIGHT);
    gameMap.loadFromFile("assets/map.txt", interactableManager);

    // Initialiser le joueur
    auto player = std::make_unique<Player>(2 * gameMap.getTileSize(), 2 * gameMap.getTileSize());
    Player* playerPtr = player.get();
    entityManager.addEntity(std::move(player));

    // Ajouter des ennemis
    auto enemy1 = std::make_unique<ChaserEnemy>(5 * gameMap.getTileSize(), 5 * gameMap.getTileSize());
    auto enemy2 = std::make_unique<PatrollingEnemy>(7 * gameMap.getTileSize(), 3 * gameMap.getTileSize(), 10 * gameMap.getTileSize(), 5 * gameMap.getTileSize());
    entityManager.addEntity(std::move(enemy1));
    entityManager.addEntity(std::move(enemy2));

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (gameState == GameState::GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        if (gameState == GameState::Playing) {
            playerPtr->update(deltaTime);
            entityManager.updateAll(deltaTime);
            interactableManager.update(*playerPtr);

            window.clear();

            gameMap.draw(window);
            playerPtr->draw(window);
            entityManager.drawAll(window);
            interactableManager.draw(window); // Dessine les objets interactables

            window.display();
        }
        else if (gameState == GameState::GameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("Game Over! Appuyez sur Echap pour quitter");
            gameOverText.setCharacterSize(70);
            gameOverText.setFillColor(sf::Color::White);
            gameOverText.setPosition(WINDOW_WIDTH / 2.f - 200, WINDOW_HEIGHT / 2.f - 50);
            window.draw(gameOverText);
            window.display();
        }
    }

    return 0;
}
