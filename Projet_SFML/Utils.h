#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "Interactable.h"

bool checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b);

void handleCollisions(Player* playerPtr, std::vector<std::unique_ptr<Interactable>>& interactables);

#endif // UTILS_H