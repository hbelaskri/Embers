#include "Level.h"

Level::Level(sf::Vector2u windowSize) {
    // initialisation simple
}

void Level::handleEvent(const sf::Event&) {}

void Level::update(float dt) {
    player.update(dt);
}

void Level::draw(sf::RenderWindow& window) {
    player.draw(window);
    // hud.draw(window); // à ajouter plus tard si nécessaire
}
