#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Dimensions de la fenêtre
const int windowLargeur = 800;
const int windowHauteur = 600;

// Dimensions de la fenêtre de défaite
const int window2Largeur = 800;
const int window2Hauteur = 600;

// Paramètres de l'oiseau
const float birdRadius = 20.0f;
const float gravite = 0.00003f; 
const float jump = -0.06f; 
float birdY;
float verticalSpeed;
const int vie = 3;

// Paramètres des pipes
const float pipeLargeur = 80.0f;
const float espaceEntre = 150.0f;
const float pipeSpeed = 0.03f; 
std::vector<sf::RectangleShape> pipes;

void resetGame() {
    birdY = windowHauteur / 2;
    verticalSpeed = 0;
    pipes.clear();
}

void spawnPipe() {
    float pipeHeight = rand() % (windowHauteur - 200) + 100;
    sf::RectangleShape pipe(sf::Vector2f(pipeLargeur, pipeHeight));
    pipe.setFillColor(sf::Color::Green);
    pipe.setPosition(windowLargeur, 0);
    pipes.push_back(pipe);

    sf::RectangleShape pipe2(sf::Vector2f(pipeLargeur, windowHauteur - pipeHeight - espaceEntre));
    pipe2.setFillColor(sf::Color::Green);
    pipe2.setPosition(windowLargeur, pipeHeight + espaceEntre);
    pipes.push_back(pipe2);
}

void updatePipes() {
    for (auto& pipe : pipes) {
        pipe.move(-pipeSpeed, 0);
    }

    if (!pipes.empty() && pipes[0].getPosition().x + pipeLargeur < 0) {
        pipes.erase(pipes.begin());
        pipes.erase(pipes.begin());
    }

    if (!pipes.empty() && pipes.back().getPosition().x < windowLargeur - 300) {
        spawnPipe();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowLargeur, windowHauteur), "Flappy Bird");
    sf::CircleShape bird(birdRadius);
    bird.setFillColor(sf::Color::Yellow);

    resetGame();
    spawnPipe();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    verticalSpeed = jump;
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close(); 
            }
        }


        // Appliquer la gravité
        verticalSpeed += gravite;
        birdY += verticalSpeed;

        // Limiter la position de l'oiseau
        if (birdY < 0)
            birdY = 0;
        if (birdY + 2 * birdRadius > windowHauteur)
            birdY = windowHauteur - 2 * birdRadius;

        bird.setPosition(windowLargeur / 4, birdY);

        for (const auto& pipe : pipes) {
            if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds()))
                return 0;
        }


        updatePipes();

        window.clear();
        window.draw(bird);

        for (const auto& pipe : pipes) {
            window.draw(pipe);
        }

        window.display();
    }

    return 0;
}
