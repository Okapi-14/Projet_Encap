#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Player Movement");
    window.setFramerateLimit(60);

    Player player(100, 100, DEFAULT_SPEED);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        player.update(deltaTime);

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
