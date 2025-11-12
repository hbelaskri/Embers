#include "Level1.h"
#include "Level2.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "Level1End.h"
#include "GameOver.h"

Level1::Level1(Game& game, sf::Vector2u windowSize)
    : Level(windowSize), gameRef(game), timerText(font)
{
    enemies.emplace_back(sf::Vector2f(100.f, 100.f), 120.f);
    std::cout << "Niveau 1 lancé avec 1 ennemi.\n";

    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Impossible de charger la police du timer !\n";
    }
    else {
        timerText.setFont(font);
        timerText.setCharacterSize(24);
        timerText.setFillColor(sf::Color::White);
        timerText.setPosition({ 10.f, 10.f });
    }
}

void Level1::update(float dt) {
    timer += dt;
    elapsedTime += dt;
    player.update(dt);

    sf::FloatRect playerRect = player.getGlobalBounds();

    for (auto& enemy : enemies) {
        enemy.update(dt, { playerRect.position.x + playerRect.size.x / 2.f, playerRect.position.y + playerRect.size.y / 2.f });
        sf::FloatRect enemyRect = enemy.getGlobalBounds();

        if (playerRect.position.x < enemyRect.position.x + enemyRect.size.x &&
            playerRect.position.x + playerRect.size.x > enemyRect.position.x &&
            playerRect.position.y < enemyRect.position.y + enemyRect.size.y &&
            playerRect.position.y + playerRect.size.y > enemyRect.position.y)
        {
            std::cout << "Le joueur a été touché ! Niveau terminé.\n";
            gameRef.changeState(std::make_unique<GameOver>(gameRef));
            return;
        }
    }

    // Spawn ennemis
    if (timer >= spawnInterval && enemies.size() < 10) {
        float spawnX, spawnY;
        do {
            spawnX = 50.f + rand() % 700;
            spawnY = 50.f + rand() % 500;
        } while (std::abs(spawnX - playerRect.position.x) < 100.f && std::abs(spawnY - playerRect.position.y) < 100.f);

        float newSpeed = 120.f * std::pow(0.9f, enemies.size());
        enemies.emplace_back(sf::Vector2f(spawnX, spawnY), newSpeed);
        timer = 0.f;
        std::cout << "Nouvel ennemi apparu ! Total : " << enemies.size() << "\n";
    }

    int remaining = static_cast<int>(300 - elapsedTime);
    int minutes = remaining / 60;
    int seconds = remaining % 60;
    std::stringstream ss;
    ss << "Temps restant : " << minutes << "m " << seconds << "s";
    timerText.setString(ss.str());

    if (elapsedTime >= 300.f) {
        std::cout << "5 minutes écoulées ! Niveau terminé.\n";
        completed = true;
        gameRef.changeState(std::make_unique<Level1End>(gameRef));
    }
}

void Level1::draw(sf::RenderWindow& window) {
    player.draw(window);
    for (auto& enemy : enemies) enemy.draw(window);
    window.draw(timerText);
}
