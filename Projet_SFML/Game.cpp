// Game.cpp
#include "Game.h"
#include <iostream>
#include "Utils.h"

void handleEvents(sf::RenderWindow& window, GameState& gameState) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (gameState == GameState::GameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }
}

void update(float deltaTime, GameState& gameState, Player* playerPtr, EntityManager& entityManager, InteractableManager& interactableManager) {
    if (gameState == GameState::Playing) {
        playerPtr->update(deltaTime);
        entityManager.updateEnemiesWithPlayer(deltaTime, *playerPtr);
        entityManager.updateAll(deltaTime);
        interactableManager.update(*playerPtr);

        for (const auto& entity : entityManager.getEntities()) {
            auto* enemy = dynamic_cast<Enemy*>(entity.get());
            if (enemy && checkCollision(playerPtr->getSprite(), enemy->getSprite())) {
                std::cout << "Game Over!" << std::endl;
                gameState = GameState::GameOver;
                break;
            }
        }
    }
}

void render(sf::RenderWindow& window, GameState gameState, Map& gameMap, Player* playerPtr, EntityManager& entityManager, InteractableManager& interactableManager, sf::Font& font) {
    window.clear();

    if (gameState == GameState::Playing) {
        gameMap.draw(window);
        playerPtr->draw(window);
        entityManager.drawAll(window);
        interactableManager.draw(window);
    }
    else if (gameState == GameState::GameOver) {
        sf::Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setString("Game Over! Appuyez sur Echap pour quitter.");
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(sf::Color::Red);

        sf::FloatRect textBounds = gameOverText.getLocalBounds();
        gameOverText.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
        gameOverText.setPosition(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);

        window.draw(gameOverText);
    }

    window.display();
}
