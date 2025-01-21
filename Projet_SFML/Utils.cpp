#include "Utils.h"
#include "Interactable.h"

bool checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) {
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

interactables.erase(std::remove_if(interactables.begin(), interactables.end(),
    [&playerPtr](const std::unique_ptr<Interactable>& interactable) {
        if (checkCollision(playerPtr->getSprite(), interactable->getSprite())) {
            interactable->interact(*playerPtr);
            return true; // Supprime cet objet
        }
        return false;
    }),
    interactables.end());
