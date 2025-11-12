#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <filesystem>

Player::Player() :  sprite(texture)
{
    std::string path = "assets/player.png";
    std::cout << "Chemin d’accès absolu : " << std::filesystem::absolute(path) << std::endl;

    if (!texture.loadFromFile(path)) {
        std::cerr << "Échec du chargement de : " << path << std::endl;
    }
    else {
        std::cout << "Texture du joueur chargée avec succès !" << std::endl;

        sprite.setTexture(texture);

        // --- Affiche uniquement la 1ère frame de la frise ---
        sprite.setTextureRect(sf::IntRect({ 0, 0 }, { frameSize.x, frameSize.y }));

        // --- Agrandir pour mieux voir ---
        float targetWidth = 96.f;
        float targetHeight = 144.f;
        sprite.setScale(sf::Vector2f(targetWidth / frameSize.x, targetHeight / frameSize.y));

        // --- Position visible ---
        sprite.setPosition({ 100.f, 400.f });
    }
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) // Haut
        sprite.move(sf::Vector2f(0.f, -speed / 60.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // Bas
        sprite.move(sf::Vector2f(0.f, speed / 60.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) // Gauche
        sprite.move(sf::Vector2f(-speed / 60.f, 0.f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Droite
        sprite.move(sf::Vector2f(speed / 60.f, 0.f));
}

void Player::update(float dt) {
    handleInput();
    // petit ajustement : évite les doublons avec handleInput
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

