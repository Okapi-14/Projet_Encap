#include "Map.h"
#include "Potion.h"
#include "Key.h"
#include <fstream>
#include <iostream>

Map::Map(float windowWidth, float windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), tileSize(0) {
    tile.setFillColor(sf::Color::White);
}

void Map::loadFromFile(const std::string& filename, InteractableManager& interactableManager) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible de charger la carte depuis " << filename << std::endl;
        return;
    }

    mapData.clear();
    std::string line;
    size_t expectedWidth = 0;

    size_t y = 0;
    while (std::getline(file, line)) {
        if (expectedWidth == 0) {
            expectedWidth = line.size();
        }
        else if (line.size() != expectedWidth) {
            std::cerr << "Erreur : Les lignes de la carte n'ont pas la même longueur !" << std::endl;
            return;
        }
        mapData.push_back(line);

        // Parcours chaque caractère de la ligne
        for (size_t x = 0; x < line.size(); ++x) {
            if (line[x] == 'P') {
                auto potion = std::make_unique<Potion>();
                potion->setPosition(x * tileSize, y * tileSize);
                interactableManager.addInteractable(std::move(potion));
            }
            if (line[x] == 'K') {
                auto key = std::make_unique<Key>();
                key->setPosition(x * tileSize, y * tileSize);
                interactableManager.addInteractable(std::move(key));
            }
        }
        ++y;
    }

    file.close();
    resizeTiles();
}

void Map::resizeTiles() {
    if (mapData.empty() || windowWidth <= 0 || windowHeight <= 0) return;

    size_t rows = mapData.size();
    size_t cols = mapData[0].size();

    float tileWidth = windowWidth / cols;
    float tileHeight = windowHeight / rows;

    tileSize = std::min(tileWidth, tileHeight);
    tile.setSize({ tileSize, tileSize });
}

void Map::draw(sf::RenderWindow& window) {
    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            if (mapData[y][x] == '#') {
                tile.setFillColor(sf::Color::Black);
            }
            else if (mapData[y][x] == '.') {
                tile.setFillColor(sf::Color::White);
            }

            tile.setPosition(x * tileSize, y * tileSize);
            window.draw(tile);
        }
    }
}

float Map::getTileSize() const {
    return tileSize;
}
