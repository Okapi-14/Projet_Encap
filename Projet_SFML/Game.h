#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "InteractableManager.h"
#include "Player.h"
#include "Map.h"
#include "config.h"

enum class GameState {
    Playing,
    GameOver
};

void handleEvents(sf::RenderWindow& window, GameState& gameState);
void update(float deltaTime, GameState& gameState, Player* playerPtr, EntityManager& entityManager, InteractableManager& interactableManager);
void render(sf::RenderWindow& window, GameState gameState, Map& gameMap, Player* playerPtr, EntityManager& entityManager, InteractableManager& interactableManager, sf::Font& font);

#endif // GAME_H
