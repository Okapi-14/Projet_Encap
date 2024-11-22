#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "FLAPPY BIRD");

    sf::CircleShape shape(40); 
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(500, 500);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}