//#pragma once
//#include "Level.h"
//#include <SFML/Graphics.hpp>
//#include <vector>
//
//class Level2 : public Level {
//public:
//    Level2(sf::Vector2u windowSize);
//
//    void handleEvent(const sf::Event& event) override;
//    void update(float dt) override;
//    void draw(sf::RenderWindow& window) override;
//
//private:
//    sf::Texture bossTexture;
//    sf::Sprite bossSprite;
//    int bossHP = 10;
//
//    float elapsedTime = 0.f;
//    const float levelDuration = 300.f; // 5 minutes
//
//    sf::Font font;
//    sf::Text timerText;
//    sf::Text scoreText;
//
//    // Lumières
//    struct Light {
//        sf::CircleShape shape;
//        float lifetime = 0.f; // durée depuis apparition
//    };
//    std::vector<Light> lights;
//    float lightSpawnTimer = 0.f;
//    float lightSpawnInterval = 2.f; // spawn toutes les 2s
//    int score = 0;
//
//    void spawnLight(sf::Vector2u windowSize);
//};

//#pragma once
//#include "Level.h"
//#include <SFML/Graphics.hpp>
//#include <vector>
//
//class Level2 : public Level {
//public:
//    Level2(sf::Vector2u windowSize);
//
//    void handleEvent(const sf::Event& event) override;
//    void update(float dt) override;
//    void draw(sf::RenderWindow& window) override;
//
//private:
//    sf::Texture bossTexture;
//    sf::Sprite bossSprite;
//    int bossHP = 10;
//
//    float elapsedTime = 0.f;
//    const float levelDuration = 300.f; // 5 minutes
//
//    sf::Font font;
//    sf::Text timerText;
//    sf::Text scoreText;
//
//    // Lumières
//    struct Light {
//        sf::CircleShape shape;
//        float lifetime = 0.f; // durée depuis apparition
//    };
//    std::vector<Light> lights;
//    float lightSpawnTimer = 0.f;
//    float lightSpawnInterval = 2.f; // spawn toutes les 2s
//    int score = 0;
//
//    void spawnLight(sf::Vector2u windowSize);
//};

#pragma once
#include "Level.h"
#include <SFML/Graphics.hpp>

class Level2 : public Level {
public:
    Level2(sf::Vector2u windowSize);
    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::Texture bossTexture;
    sf::Sprite bossSprite;
    int bossHP = 10;
    float elapsedTime = 0.f;
    const float levelDuration = 300.f; // 5 minutes
    sf::Font font;
    sf::Text timerText;
    sf::Text scoreText;

    // Lumières
    std::vector<sf::CircleShape> lights;
    float lightSpawnTimer = 0.f;
    float lightSpawnInterval = 2.f; // nouvelle lumière toutes les 2s
    int score = 0;

    // Fonctions utilitaires
    void spawnLight(sf::Vector2u windowSize);

    // Ajout de la structure Light pour corriger l'erreur "identificateur 'Light' non défini"
    struct Light {
        sf::CircleShape shape;
        float lifetime = 0.f;
    };
};
