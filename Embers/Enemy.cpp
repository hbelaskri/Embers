#include "Enemy.h"
#include <cmath>

Enemy::Enemy(const sf::Vector2f& startPos, float spd)
    : speed(spd)
{
    rect.setSize({ 50.f, 50.f });
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(startPos);
}

void Enemy::update(float dt, const sf::Vector2f& playerPos)
{
    // Calculer la direction vers le joueur
    sf::Vector2f dir = playerPos - rect.getPosition();
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);

    if (length > 0.f) {
        dir /= length; // normalisation
        rect.move(dir * speed * dt);
    }
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(rect);
}
