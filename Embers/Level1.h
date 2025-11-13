

#pragma once
#include "Level.h"
#include "Enemy.h"
#include "Game.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Level2; // forward declaration

class Level1 : public Level {
public:
    Level1(Game& game, sf::Vector2u windowSize);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool isFinished() const { return elapsedTime >= 300.f; }

private:
    bool playerLost = false;
    Game& gameRef;
    std::vector<Enemy> enemies;
    float timer = 0.f;
    float spawnInterval = 60.f;
    float elapsedTime = 0.f;
    sf::Font font;
    sf::Text timerText;
};
