#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <memory>
#include "Player.h"
#include "ChaserEnemy.h"
#include "Entity.h"

class EntityManager {
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void addEntity(std::unique_ptr<Entity> entity);
    void updateAll(float deltaTime);
    void drawAll(sf::RenderWindow& window);
    const std::vector<std::unique_ptr<Entity>>& getEntities() const; // Accessible publiquement
    void updateEnemiesWithPlayer(float deltaTime, const Player& player);
};


#endif // ENTITY_MANAGER_H
