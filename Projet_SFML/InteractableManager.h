#ifndef INTERACTABLE_MANAGER_H
#define INTERACTABLE_MANAGER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Interactable.h"
#include "Utils.h"

class InteractableManager {
private:
    std::vector<std::unique_ptr<Interactable>> interactables;

public:
    // Ajoute un interactable au gestionnaire
    void addInteractable(std::unique_ptr<Interactable> interactable);

    // Met à jour les interactables et gère les collisions avec le joueur
    void update(Player& player);

    // Dessine tous les interactables dans la fenêtre
    void draw(sf::RenderWindow& window) const;

    // Retourne le nombre d'interactables (pour le débogage)
    size_t getCount() const;
};

#endif