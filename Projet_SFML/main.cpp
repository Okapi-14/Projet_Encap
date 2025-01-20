#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "ChaserEnemy.h"
#include "Utils.h"
#include "EntityManager.h"
#include "config.h"
#include "PatrollingEnemy.h"

enum class GameState {
    Playing,
    GameOver
};

GameState gameState = GameState::Playing;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "jeu");
    window.setFramerateLimit(60);

    EntityManager entityManager;
    auto player = std::make_unique<Player>(100, 100); // Crée le joueur séparément
    Player* playerPtr = player.get(); // Pointeur pour référence
    entityManager.addEntity(std::move(player));
    entityManager.addEntity(std::make_unique<ChaserEnemy>(400, 300));
    entityManager.addEntity(std::make_unique<PatrollingEnemy>(200, 200, 400, 400));



    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (gameState == GameState::Playing) {
            float deltaTime = clock.restart().asSeconds();

            // Mise à jour des ennemis avec le joueur
            entityManager.updateEnemiesWithPlayer(deltaTime, *playerPtr);

            // Mise à jour de toutes les entités
            entityManager.updateAll(deltaTime);

            // Vérification des collisions pour Game Over
            for (const auto& entity : entityManager.getEntities()) {
                auto* enemy = dynamic_cast<Enemy*>(entity.get()); // Vérifie si l'entité est un Enemy
                if (enemy && checkCollision(playerPtr->getSprite(), enemy->getSprite())) {
                    std::cout << "Game Over!" << std::endl;
                    gameState = GameState::GameOver;
                    break;
                }
            }

            // Dessin des entités
            entityManager.drawAll(window);
        }
        else if (gameState == GameState::GameOver) {
            // Afficher un message Game Over
            sf::Font font;
            if (!font.loadFromFile("assets/arial.ttf")) {
                std::cerr << "Erreur : Impossible de charger la police." << std::endl;
                return -1;
            }

            sf::Text gameOverText;
            gameOverText.setFont(font);
            gameOverText.setString("Game Over! Appuyez sur Echap pour quitter.");
            gameOverText.setCharacterSize(30);
            gameOverText.setFillColor(sf::Color::Red);
            gameOverText.setPosition(WINDOW_WIDTH / 2.f - 200.f, WINDOW_HEIGHT / 2.f - 50.f);

            window.draw(gameOverText);
        }

        window.display();

        // Quitter le jeu en appuyant sur Échap pendant Game Over
        if (gameState == GameState::GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }


    return 0;
}
