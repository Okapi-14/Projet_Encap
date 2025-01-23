#include "Utils.h"

bool checkCollision(sf::RectangleShape& a, sf::RectangleShape& b) {
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

void handleCollisions(Player* playerPtr, std::vector<std::unique_ptr<Interactable>>& interactables) {
    interactables.erase(std::remove_if(interactables.begin(), interactables.end(),
        [&playerPtr](const std::unique_ptr<Interactable>& interactable) {
            if (checkCollision(playerPtr->getSprite(), interactable->getSprite())) {
                interactable->interact(*playerPtr);
                return true; // Supprime cet objet
            }
            return false;
        }),
        interactables.end());
}
