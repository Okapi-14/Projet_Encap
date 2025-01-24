#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "InteractableManager.h"

class Map {
private:
    std::vector<std::string> mapData;
    sf::RectangleShape tile;
    float windowWidth, windowHeight;
    float tileSize;

public:
    Map(float windowWidth, float windowHeight);

    void loadFromFile(const std::string& filename, InteractableManager& interactableManager);
    void draw(sf::RenderWindow& window);
    void resizeTiles();
    float getTileSize() const;
};

#endif // MAP_H
