#include "InteractableManager.h"
#include <iostream>

void InteractableManager::addInteractable(std::unique_ptr<Interactable> interactable) {
    interactables.push_back(std::move(interactable));
}

void InteractableManager::update(Player& player) {
    interactables.erase(std::remove_if(interactables.begin(), interactables.end(),
        [&player](const std::unique_ptr<Interactable>& interactable) {
            if (player.getSprite().getGlobalBounds().intersects(interactable->getSprite().getGlobalBounds())) {
                interactable->interact(player); // Applique l'effet d'interaction
                return true; // Supprime l'objet de la liste après interaction
            }
            return false;
        }), interactables.end());
}

void InteractableManager::draw(sf::RenderWindow& window) const {
    for (const auto& interactable : interactables) {
        interactable->draw(window); // Dessine chaque interactable
    }
}
