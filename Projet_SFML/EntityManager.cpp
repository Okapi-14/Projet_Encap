#include "EntityManager.h"
#include "ChaserEnemy.h"

const std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities() const {
    return entities;
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity) {
    entities.push_back(std::move(entity));
}

void EntityManager::updateAll(float deltaTime) {
    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
}

void EntityManager::drawAll(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->draw(window);
    }
}

void EntityManager::updateEnemiesWithPlayer(float deltaTime, const Player& player) {
    for (auto& entity : entities) {
        auto* enemy = dynamic_cast<ChaserEnemy*>(entity.get());
        if (enemy) {
            enemy->updateWithPlayer(deltaTime, player);
        }
    }
}


