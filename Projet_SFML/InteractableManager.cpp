#include "InteractableManager.h"

void InteractableManager::addInteractable(std::unique_ptr<Interactable> interactable) {
    interactables.push_back(std::move(interactable));
}

void InteractableManager::update(Player& player) {
    interactables.erase(std::remove_if(interactables.begin(), interactables.end(),
        [&player](const std::unique_ptr<Interactable>& interactable) {
            if (checkCollision(player.getSprite(), interactable->getSprite())) {
                interactable->interact(player);
                return true; // Supprime l'interactable après interaction
            }
            return false;
        }), interactables.end());
}

void InteractableManager::draw(sf::RenderWindow& window) const {
    for (const auto& interactable : interactables) {
        std::cout << "Drawing interactable at: "
            << interactable->getSprite().getPosition().x << ", "
            << interactable->getSprite().getPosition().y << std::endl;
        window.draw(interactable->getSprite());
    }
}

size_t InteractableManager::getCount() const {
    return interactables.size();
}
