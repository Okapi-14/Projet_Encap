#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath> 

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), ("Mini projet SFML"));
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(100, 200);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
				circle.move(10, 0);
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				window.close();
			}
		}
		window.clear();
		window.draw(circle);
		window.display();
	}
}