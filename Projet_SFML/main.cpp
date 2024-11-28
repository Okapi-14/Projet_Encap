#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath> // Pour std::abs

// Dimensions de la fenêtre
const int windowLargeur = 800;
const int windowHauteur = 600;

// Dimensions de la fenêtre de début
const int window2Largeur = 800;
const int window2Hauteur = 600;

// Paramètres de l'oiseau
const float gravite = 0.00004f;
const float jump = -0.070f;
float birdY;
float verticalSpeed;

// Paramètres des pipes
const float pipeLargeur = 80.0f;
const float espaceEntre = 160.0f;
const float pipeSpeed = 0.02f;
std::vector<sf::Sprite> pipes;

// Score
int score;

// Fonction pour vérifier la collision entre l'oiseau et un pipe
bool checkCollision(const sf::Sprite& bird, const sf::Sprite& pipe) {
    // Obtenir les hitbox des sprites
    sf::FloatRect birdBounds = bird.getGlobalBounds();
    sf::FloatRect pipeBounds = pipe.getGlobalBounds();
    sf::FloatRect customPipeBounds(pipeBounds.left + 10, pipeBounds.top + 10, pipeBounds.width - 20, std::abs(pipeBounds.height) - 20);

    // Vérifier la collision avec les hitbox personnalisées
    return birdBounds.intersects(customPipeBounds);
}

sf::Texture pipeTexture;

// Fonction pour générer de nouveaux pipes
void spawnPipe() {
    float pipeHeight = rand() % (windowHauteur - 200) + 100;

    sf::Sprite pipe1;
    pipe1.setTexture(pipeTexture);
    pipe1.setScale(sf::Vector2f(pipeLargeur / pipeTexture.getSize().x, -pipeHeight / pipeTexture.getSize().y * 1.5f));
    pipe1.setPosition(windowLargeur, pipeHeight); // Avoir des pipes inversés
    pipes.push_back(pipe1);

    sf::Sprite pipe2;
    pipe2.setTexture(pipeTexture);
    pipe2.setScale(sf::Vector2f(pipeLargeur / pipeTexture.getSize().x, (windowHauteur - pipeHeight - espaceEntre) / pipeTexture.getSize().y * 1.5f));
    pipe2.setPosition(windowLargeur, pipeHeight + espaceEntre);
    pipes.push_back(pipe2);
}

// Fonction pour réinitialiser le jeu
void resetGame() {
    birdY = windowHauteur / 2;
    verticalSpeed = 0;
    pipes.clear();
    spawnPipe();
    score = 0;
}

// Fonction pour mettre à jour les pipes
void updatePipes() {
    for (auto& pipe : pipes) {
        pipe.move(-pipeSpeed, 0);
    }

    // Supprimer les pipes qui sortent de l'écran
    if (!pipes.empty() && pipes[0].getPosition().x + pipeLargeur < 0) {
        pipes.erase(pipes.begin());
        pipes.erase(pipes.begin());
        score++;
        std::cout << "Score  " << score << std::endl;
    }

    // Générer de nouveaux pipes
    if (!pipes.empty() && pipes.back().getPosition().x < windowLargeur - 300) {
        spawnPipe();
    }
}

int main() {
    // Création de la fenêtre principale du jeu
    sf::RenderWindow window(sf::VideoMode(windowLargeur, windowHauteur), "Flappy Bird");
    // Création de la fenêtre du menu de départ
    sf::RenderWindow window2(sf::VideoMode(window2Largeur, window2Hauteur), "Menu de depart");

    // Charger l'image de l'oiseau
    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("C:/Users/acossardeaux/Downloads/flappy-bird-sprite-11549936843rfq2kg39db-removebg-preview.png")) {
        std::cout << "Erreur de chargement de l'image!" << std::endl;
        return -1;
    }

    // Créer un sprite pour l'oiseau
    sf::Sprite bird(birdTexture);
    bird.setScale(0.1f, 0.1f); 

    // Charger l'image des pipes
    if (!pipeTexture.loadFromFile("C:/Users/acossardeaux/Downloads/pipe.png")) {
        std::cout << "Erreur de chargement de l'image!" << std::endl;
        return -1;
    }

    // Charger le fond d'écran
    sf::Texture fondTexture;
    if (!fondTexture.loadFromFile("C:/Users/acossardeaux/Pictures/fond_flappy.png")) {
        std::cout << "Erreur de chargement de l'image!" << std::endl;
        return -1;
    }
    sf::Sprite fond(fondTexture);

    // Charger la police d'écriture
    sf::Font font;
    if (!font.loadFromFile("C:/Users/acossardeaux/Downloads/flappybirdy/FlappyBirdy.ttf")) {
        std::cout << "Erreur de chargement de la police!" << std::endl;
        return -1;
    }

    // Charger et jouer le son du jeu
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("C:/Users/acossardeaux/Downloads/Angry_Birds_Theme.ogg")) {
        std::cout << "Erreur : Impossible de charger le fichier audio." << std::endl;
        return -1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true); // Boucle la musique
    sound.play();

    // Création du rectangle pour le menu
    sf::RectangleShape button(sf::Vector2f(300, 100));
    button.setFillColor(sf::Color::Blue);
    button.setPosition(window2Largeur / 2 - 150, window2Hauteur / 2 - 50);

    // Création du texte pour le menu
    sf::Text text;
    text.setFont(font);
    text.setString("Appuyer sur Entrer");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(button.getPosition().x + 27, button.getPosition().y + 15);

    // Création du texte du score
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(windowLargeur / 2 - 30, 20);

    resetGame();

    // Boucle du menu de départ
    while (window2.isOpen()) {
        sf::Event event2;
        while (window2.pollEvent(event2)) {
            if (event2.type == sf::Event::Closed)
                window2.close();

            if (event2.type == sf::Event::KeyPressed) {
                if (event2.key.code == sf::Keyboard::Enter) {
                    resetGame();
                    window2.close();
                }
            }
        }

        window2.clear();
        window2.draw(fond);
        window2.draw(button);
        window2.draw(text);
        window2.display();
    }

    // Boucle du jeu
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

        // Appliquer la gravité à l'oiseau
        verticalSpeed += gravite;
        birdY += verticalSpeed;

        // Limiter la position de l'oiseau
        if (birdY < 0)
            birdY = 0;
        if (birdY + bird.getGlobalBounds().height > windowHauteur)
            birdY = windowHauteur - bird.getGlobalBounds().height;

        bird.setPosition(windowLargeur / 4, birdY);

        // Vérifier les collisions avec les pipes
        for (const auto& pipe : pipes) {
            if (checkCollision(bird, pipe)) {
                window.close();
            }
        }

        updatePipes();

        // Mettre à jour le texte du score
        scoreText.setString("Score  " + std::to_string(score));

        window.clear();
        window.draw(fond);
        window.draw(bird);

        // Dessiner les pipes
        for (const auto& pipe : pipes) {
            window.draw(pipe);
        }

        window.draw(scoreText);
        window.display();
    }

    return 0;
}
