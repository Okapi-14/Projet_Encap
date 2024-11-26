#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Dimensions de la fenêtre
const int windowLargeur = 800;
const int windowHauteur = 600;

// Dimensions de la fenêtre de début
const int window2Largeur = 800;
const int window2Hauteur = 600;

// Paramètres de l'oiseau
const float birdRadius = 20.0f;
const float gravite = 0.00004f;
const float jump = -0.075f;
float birdY;
float verticalSpeed;

// Paramètres des pipes
const float pipeLargeur = 80.0f;
const float espaceEntre = 150.0f;
const float pipeSpeed = 0.02f;
std::vector<sf::RectangleShape> pipes;

bool estMort;

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
    sf::RenderWindow window2(sf::VideoMode(window2Largeur, window2Hauteur), "Menu de depart");
    sf::CircleShape bird(birdRadius);
    bird.setFillColor(sf::Color::Yellow);

    estMort = false;

    // Chargement de la police
    sf::Font font;
    if (!font.loadFromFile("C:/Users/acossardeaux/Downloads/keep_on_truckin_fw/KeeponTruckin.ttf")) {
        std::cout << "Erreur de chargement de la police!" << std::endl;
        return -1;
    }

    // Création du rectangle
    sf::RectangleShape button(sf::Vector2f(300, 100));
    button.setFillColor(sf::Color::Red);
    button.setPosition(window2Largeur / 2 - 150, window2Hauteur / 2 - 50);

    // Création du texte
    sf::Text text;
    text.setFont(font);
    text.setString("Appuyer sur Entrer");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(button.getPosition().x + 30, button.getPosition().y + 30);

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
            if (bird.getGlobalBounds().intersects(pipe.getGlobalBounds())) {
                estMort = true;
                break;
            }
        }

        updatePipes();

        window.clear();
        window.draw(bird);

        for (const auto& pipe : pipes) {
            window.draw(pipe);
        }

        window.display();

        if (estMort) {
            while (window2.isOpen()) {
                sf::Event event2;
                while (window2.pollEvent(event2)) {
                    if (event2.type == sf::Event::Closed)
                        window2.close();

                    if (event2.type == sf::Event::KeyPressed) {
                        if (event2.key.code == sf::Keyboard::Enter) {
                            estMort = false;
                            resetGame();
                            window2.close();
                        }
                    }
                }

                window2.clear();
                window2.draw(button); // Dessiner le rectangle
                window2.draw(text);   // Dessiner le texte
                window2.display();
            }
        }
    }

    return 0;
}
