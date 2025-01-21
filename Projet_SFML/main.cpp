#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "ChaserEnemy.h"
#include "PatrollingEnemy.h"
#include "Potion.h"
#include "Key.h"
#include "Utils.h"
#include "EntityManager.h"
#include "config.h"
#include "Interactable.h"

enum class GameState {
    Playing,
    GameOver
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jeu");
    window.setFramerateLimit(60);

    // Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police." << std::endl;
        return -1;
    }

    // Initialisation du jeu
    GameState gameState = GameState::Playing;
    EntityManager entityManager;

    auto player = std::make_unique<Player>(100, 100);
    Player* playerPtr = player.get();

    entityManager.addEntity(std::move(player));
    entityManager.addEntity(std::make_unique<ChaserEnemy>(400, 300));
    entityManager.addEntity(std::make_unique<PatrollingEnemy>(200, 200, 400, 400));

    std::vector<std::unique_ptr<Interactable>> interactables;
    interactables.push_back(std::make_unique<Potion>(50.f));
    interactables.push_back(std::make_unique<Key>());

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        if (gameState == GameState::Playing) {
            // Mise à jour des entités
            playerPtr->update(deltaTime);
            entityManager.updateEnemiesWithPlayer(deltaTime, *playerPtr);
            entityManager.updateAll(deltaTime);

            // Vérification des collisions avec les objets interactables
            interactables.erase(std::remove_if(interactables.begin(), interactables.end(),
                [&playerPtr](const std::unique_ptr<Interactable>& interactable) {
                    if (checkCollision(playerPtr->getSprite(), interactable->getSprite())) {
                        interactable->interact(*playerPtr);
                        return true; // Supprime l'objet après interaction
                    }
                    return false;
                }),
                interactables.end());

            // Vérification des collisions avec les ennemis
            for (const auto& entity : entityManager.getEntities()) {
                auto* enemy = dynamic_cast<Enemy*>(entity.get());
                if (enemy && checkCollision(playerPtr->getSprite(), enemy->getSprite())) {
                    std::cout << "Game Over!" << std::endl;
                    gameState = GameState::GameOver;
                    break;
                }
            }
        }

        // Affichage
        window.clear();

        if (gameState == GameState::Playing) {
            playerPtr->draw(window);
            for (const auto& interactable : interactables) {
                window.draw(interactable->getSprite());
            }
            entityManager.drawAll(window);
        }
        else if (gameState == GameState::GameOver) {
            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("Game Over! Appuyez sur Echap pour quitter.");
            gameOverText.setCharacterSize(30);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(WINDOW_WIDTH / 2.f - 200.f, WINDOW_HEIGHT / 2.f - 50.f);

            window.draw(gameOverText);
        }

        window.display();

        if (gameState == GameState::GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }

    return 0;
}
