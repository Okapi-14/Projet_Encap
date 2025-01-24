#ifndef INTERACTABLEMANAGER_H
#define INTERACTABLEMANAGER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Interactable.h"
#include "Player.h"

class InteractableManager {
private:
    std::vector<std::unique_ptr<Interactable>> interactables;

public:
    void addInteractable(std::unique_ptr<Interactable> interactable);
    void update(Player& player);
    void draw(sf::RenderWindow& window) const;
    size_t getCount() const;
    const std::vector<std::unique_ptr<Interactable>>& getInteractables() const;
};

#endif // INTERACTABLEMANAGER_H
