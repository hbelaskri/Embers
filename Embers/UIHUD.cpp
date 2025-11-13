#include "UIHUD.h"
#include <algorithm>

UIHUD::UIHUD()
{
    // Fond gris vertical
    barBackground.setSize({ 30.f, barMaxHeight });
    barBackground.setFillColor(sf::Color(50, 50, 50));
    barBackground.setPosition({ 750.f, 50.f });

    // Barre jaune (remplie de bas en haut)
    barForeground.setSize({ 30.f, 0.f });
    barForeground.setFillColor(sf::Color::Yellow);
    barForeground.setPosition({ 750.f, 50.f + barMaxHeight });
}

// Ajouter des points de lumière
void UIHUD::addLight(int amount)
{
    lightScore = std::clamp(lightScore + amount, 0, 100);
    float newHeight = barMaxHeight * lightScore / 100.f;
    barForeground.setSize({ 30.f, newHeight });
    barForeground.setPosition({ 750.f, 50.f + barMaxHeight - newHeight });
}

// Ajouter un message narratif
void UIHUD::addMessage(const std::string& msg)
{
    messages.push_back(msg);
}

// Mise à jour
void UIHUD::update(float dt)
{
    // Timer pour messages narratifs
    if (!messages.empty()) {
        messageTimer += dt;
        if (messageTimer >= displayInterval) {
            messageTimer = 0.f;
            currentIndex = (currentIndex + 1) % messages.size();
        }
    }
}

// Dessin
void UIHUD::draw(sf::RenderWindow& window)
{
    // Jauge lumière
    window.draw(barBackground);
    window.draw(barForeground);

    // Messages narratifs
    if (!messages.empty() && font.getInfo().family != "") {
        sf::Text text( font, "", 20);
        text.setFillColor(sf::Color::White);
        text.setString(messages[currentIndex]);
        text.setPosition({ 50.f, 50.f });
        window.draw(text);
    }
}
