//#include "Level2.h"
//#include <iostream>
//#include <sstream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//Level2::Level2(sf::Vector2u windowSize)
//    : Level(windowSize), bossSprite(bossSprite), timerText(font), scoreText(font)
//{
//    srand(static_cast<unsigned int>(time(nullptr)));
//
//    // --- Boss ---
//    if (!bossTexture.loadFromFile("assets/Boss.png"))
//        std::cerr << "Erreur : Boss.png manquant\n";
//    bossSprite.setTexture(bossTexture);
//    bossSprite.setOrigin({ bossTexture.getSize().x / 2.f, bossTexture.getSize().y / 2.f });
//    bossSprite.setPosition({ windowSize.x / 2.f, 150.f });
//
//    // --- Police ---
//    if (!font.openFromFile("assets/fonts/arial.ttf"))
//        std::cerr << "Erreur : police introuvable\n";
//
//    timerText.setFont(font);
//    timerText.setCharacterSize(24);
//    timerText.setFillColor(sf::Color::White);
//    timerText.setPosition({ 20.f, 20.f });
//
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(24);
//    scoreText.setFillColor(sf::Color::Yellow);
//    scoreText.setPosition({ windowSize.x - 300.f, 20.f });
//}
//
//void Level2::spawnLight(sf::Vector2u windowSize) {
//    Light l;
//    l.shape.setRadius(10.f);
//    l.shape.setFillColor(sf::Color::Yellow);
//    float x = 20.f + rand() % (windowSize.x - 40);
//    float y = 60.f + rand() % (windowSize.y - 60);
//    l.shape.setPosition(sf::Vector2f(x, y));
//    l.lifetime = 0.f;
//    lights.push_back(l);
//}
//
//void Level2::handleEvent(const sf::Event&) {
//    float moveSpeed = 200.f;
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//        player.move({ 0.f, -moveSpeed / 60.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//        player.move({ 0.f, moveSpeed / 60.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//        player.move({ -moveSpeed / 60.f, 0.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//        player.move({ moveSpeed / 60.f, 0.f });
//}
//
//void Level2::update(float dt) {
//    elapsedTime += dt;
//    player.update(dt);
//
//    // --- Timer ---
//    float remaining = std::max(0.f, levelDuration - elapsedTime);
//    int minutes = static_cast<int>(remaining) / 60;
//    int seconds = static_cast<int>(remaining) % 60;
//    std::stringstream ss;
//    ss << "Temps restant : " << minutes << "m " << seconds << "s";
//    timerText.setString(ss.str());
//
//    // --- Générer des lumières ---
//    lightSpawnTimer += dt;
//    if (lightSpawnTimer >= lightSpawnInterval) {
//        spawnLight({ 800, 600 });
//        lightSpawnTimer = 0.f;
//    }
//
//    // --- Mettre à jour et supprimer les lumières ---
//    sf::FloatRect playerBounds = player.getGlobalBounds();
//    for (int i = static_cast<int>(lights.size()) - 1; i >= 0; --i) {
//        Light& l = lights[i];
//        l.lifetime += dt;
//
//        // Vérifier collision rectangle/cercle
//        sf::Vector2f lightPos = l.shape.getPosition();
//        float radius = l.shape.getRadius();
//
//        float rectLeft = playerBounds.position.x;
//        float rectTop = playerBounds.position.y;
//        float rectRight = rectLeft + playerBounds.size.x;
//        float rectBottom = rectTop + playerBounds.size.y;
//
//        float circleX = lightPos.x + radius;
//        float circleY = lightPos.y + radius;
//
//        float closestX = std::max(rectLeft, std::min(circleX, rectRight));
//        float closestY = std::max(rectTop, std::min(circleY, rectBottom));
//        float dx = circleX - closestX;
//        float dy = circleY - closestY;
//
//        if ((dx * dx + dy * dy) < (radius * radius) || l.lifetime >= 3.f) {
//            if ((dx * dx + dy * dy) < (radius * radius)) score++;
//            lights.erase(lights.begin() + i);
//        }
//    }
//
//    // --- Score ---
//    scoreText.setString("Lumières ramassées : " + std::to_string(score));
//
//    // --- Fin du niveau ---
//    if (elapsedTime >= levelDuration)
//        std::cout << "5 minutes écoulées ! Score final : " << score << " lumières ramassées.\n";
//}
//
//void Level2::draw(sf::RenderWindow& window) {
//    window.clear(sf::Color(10, 10, 30));
//    player.draw(window);
//    window.draw(bossSprite);
//
//    for (auto& l : lights) window.draw(l.shape);
//
//    window.draw(timerText);
//    window.draw(scoreText);
//}

//#include "Level2.h"
//#include <iostream>
//#include <sstream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//Level2::Level2(sf::Vector2u windowSize)
//    : Level(windowSize), bossSprite(bossSprite), timerText(font), scoreText(font)
//{
//    srand(static_cast<unsigned int>(time(nullptr)));
//
//    // --- Boss ---
//    if (!bossTexture.loadFromFile("assets/Boss.png"))
//        std::cerr << "Erreur : Boss.png manquant\n";
//    bossSprite.setTexture(bossTexture);
//    bossSprite.setOrigin({ bossTexture.getSize().x / 2.f, bossTexture.getSize().y / 2.f });
//    bossSprite.setPosition({ windowSize.x / 2.f, 150.f });
//
//    // --- Police ---
//    if (!font.openFromFile("assets/fonts/arial.ttf"))
//        std::cerr << "Erreur : police introuvable\n";
//
//    timerText.setFont(font);
//    timerText.setCharacterSize(24);
//    timerText.setFillColor(sf::Color::White);
//    timerText.setPosition({ 20.f, 20.f });
//
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(24);
//    scoreText.setFillColor(sf::Color::Yellow);
//    scoreText.setPosition({ windowSize.x - 300.f, 20.f });
//}
//
//void Level2::spawnLight(sf::Vector2u windowSize) {
//    Light l;
//    l.shape.setRadius(10.f);
//    l.shape.setFillColor(sf::Color::Yellow);
//    float x = 20.f + rand() % (windowSize.x - 40);
//    float y = 60.f + rand() % (windowSize.y - 60);
//    l.shape.setPosition(sf::Vector2f(x, y));
//    l.lifetime = 0.f;
//    lights.push_back(l);
//}
//
//void Level2::handleEvent(const sf::Event&) {
//    float moveSpeed = 200.f;
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//        player.move({ 0.f, -moveSpeed / 60.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//        player.move({ 0.f, moveSpeed / 60.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//        player.move({ -moveSpeed / 60.f, 0.f });
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//        player.move({ moveSpeed / 60.f, 0.f });
//}
//
//void Level2::update(float dt) {
//    elapsedTime += dt;
//    player.update(dt);
//
//    // --- Timer ---
//    float remaining = std::max(0.f, levelDuration - elapsedTime);
//    int minutes = static_cast<int>(remaining) / 60;
//    int seconds = static_cast<int>(remaining) % 60;
//    std::stringstream ss;
//    ss << "Temps restant : " << minutes << "m " << seconds << "s";
//    timerText.setString(ss.str());
//
//    // --- Générer des lumières ---
//    lightSpawnTimer += dt;
//    if (lightSpawnTimer >= lightSpawnInterval) {
//        spawnLight({ 800, 600 });
//        lightSpawnTimer = 0.f;
//    }
//
//    // --- Mettre à jour et supprimer les lumières ---
//    sf::FloatRect playerBounds = player.getGlobalBounds();
//    for (int i = static_cast<int>(lights.size()) - 1; i >= 0; --i) {
//        Light& l = lights[i];
//        l.lifetime += dt;
//
//        // Vérifier collision rectangle/cercle
//        sf::Vector2f lightPos = l.shape.getPosition();
//        float radius = l.shape.getRadius();
//
//        float rectLeft = playerBounds.position.x;
//        float rectTop = playerBounds.position.y;
//        float rectRight = rectLeft + playerBounds.size.x;
//        float rectBottom = rectTop + playerBounds.size.y;
//
//        float circleX = lightPos.x + radius;
//        float circleY = lightPos.y + radius;
//
//        float closestX = std::max(rectLeft, std::min(circleX, rectRight));
//        float closestY = std::max(rectTop, std::min(circleY, rectBottom));
//        float dx = circleX - closestX;
//        float dy = circleY - closestY;
//
//        if ((dx * dx + dy * dy) < (radius * radius) || l.lifetime >= 3.f) {
//            if ((dx * dx + dy * dy) < (radius * radius)) score++;
//            lights.erase(lights.begin() + i);
//        }
//    }
//
//    // --- Score ---
//    scoreText.setString("Lumières ramassées : " + std::to_string(score));
//
//    // --- Fin du niveau ---
//    if (elapsedTime >= levelDuration)
//        std::cout << "5 minutes écoulées ! Score final : " << score << " lumières ramassées.\n";
//}
//
//void Level2::draw(sf::RenderWindow& window) {
//    window.clear(sf::Color(10, 10, 30));
//    player.draw(window);
//    window.draw(bossSprite);
//
//    for (auto& l : lights) window.draw(l.shape);
//
//    window.draw(timerText);
//    window.draw(scoreText);
//}

#include "Level2.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

Level2::Level2(sf::Vector2u windowSize)
    : Level(windowSize), bossSprite(bossSprite), timerText(font), scoreText(font)
{
    srand(static_cast<unsigned int>(time(nullptr))); // init rand

    // --- Boss ---
    if (!bossTexture.loadFromFile("assets/Boss.png"))
        std::cerr << "Erreur : Boss.png manquant\n";
    bossSprite.setTexture(bossTexture);
    bossSprite.setOrigin(
        sf::Vector2f(
            static_cast<float>(bossTexture.getSize().x) / 2.f,
            static_cast<float>(bossTexture.getSize().y) / 2.f
        )
    );
    bossSprite.setPosition({ windowSize.x / 2.f, 150.f });

    // --- Timer ---
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur : police introuvable\n";
    }
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition({ 20.f, 20.f });

    // --- Score ---
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Yellow);
    scoreText.setPosition({ windowSize.x - 300.f, 20.f });
}

void Level2::spawnLight(sf::Vector2u windowSize) {
    sf::CircleShape light(10.f);
    light.setFillColor(sf::Color::Yellow);
    float x = 20.f + rand() % (windowSize.x - 40);
    float y = 60.f + rand() % (windowSize.y - 60);
    light.setPosition({ x, y });
    lights.push_back(light);
}

void Level2::handleEvent(const sf::Event&) {
    float moveSpeed = 200.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        player.getSprite().move({ 0.f, -moveSpeed / 60.f });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        player.getSprite().move({ 0.f, moveSpeed / 60.f });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        player.getSprite().move({ -moveSpeed / 60.f, 0.f });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        player.getSprite().move({ moveSpeed / 60.f, 0.f });
}

void Level2::update(float dt) {
    elapsedTime += dt;
    player.update(dt);

    // --- Timer ---
    float remaining = levelDuration - elapsedTime;
    if (remaining < 0.f) remaining = 0.f;
    int minutes = static_cast<int>(remaining) / 60;
    int seconds = static_cast<int>(remaining) % 60;
    std::stringstream ss;
    ss << "Temps restant : " << minutes << "m " << seconds << "s";
    timerText.setString(ss.str());

    // --- Générer des lumières ---
    lightSpawnTimer += dt;
    if (lightSpawnTimer >= lightSpawnInterval) {
        spawnLight({ 800, 600 }); // taille fenêtre par défaut
        lightSpawnTimer = 0.f;
    }

    // --- Vérifier collision avec lumières ---
    sf::FloatRect playerRect = player.getGlobalBounds();
    for (int i = static_cast<int>(lights.size()) - 1; i >= 0; --i) {
        sf::Vector2f pos = lights[i].getPosition();
        float radius = lights[i].getRadius();

        // collision rectangle/cercle
        float rectLeft = playerRect.position.x;
        float rectTop = playerRect.position.y;
        float rectRight = rectLeft + playerRect.size.x;
        float rectBottom = rectTop + playerRect.size.y;

        float circleX = pos.x + radius;
        float circleY = pos.y + radius;

        float closestX = std::max(rectLeft, std::min(circleX, rectRight));
        float closestY = std::max(rectTop, std::min(circleY, rectBottom));
        float dx = circleX - closestX;
        float dy = circleY - closestY;

        if ((dx * dx + dy * dy) < (radius * radius)) {
            lights.erase(lights.begin() + i);
            score++;
        }
    }

    // --- Score ---
    scoreText.setString("Lumières ramassées : " + std::to_string(score));

    // --- Fin du niveau ---
    if (elapsedTime >= levelDuration) {
        std::cout << "5 minutes écoulées ! Score final : " << score << " lumières ramassées.\n";
        // ici tu peux passer à un écran de score ou victoire
    }
}

void Level2::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(10, 10, 30)); // fond sombre
    player.draw(window);
    window.draw(bossSprite);

    // --- Dessiner les lumières ---
    for (auto& light : lights) {
        window.draw(light);
    }

    // --- Timer & score ---
    window.draw(timerText);
    window.draw(scoreText);
}
