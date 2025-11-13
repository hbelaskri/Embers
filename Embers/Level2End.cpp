#include "Level2End.h"
#include "Menu.h"
#include <iostream>

Level2End::Level2End(Game& game, int finalScore)
    : gameRef(game), score(finalScore), missionText(font)
{
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur chargement font Level2End\n";
    }

    missionText.setFont(font);
    missionText.setCharacterSize(28);
    missionText.setFillColor(sf::Color::White);

    // --- Reflet orangé ---
    missionText.setOutlineColor(sf::Color(255, 150, 0));
    missionText.setOutlineThickness(2.f);

    missionText.setStyle(sf::Text::Bold);

    // position centrée approximativement pour fenêtre 800x600
    missionText.setPosition({ 400.f, 300.f });

    if (score >= 100) {
        missionText.setString(
            "Bravo ! Tu as récupéré assez de lumière pour sauver le monde !\n\n"
            "Ton courage et ta rapidité ont permis de protéger la flamme.\n\n"
            "Appuie sur ENTREE pour revenir au menu."
        );
    }
    else {
        missionText.setString(
            "Tu n'as pas réussi à sauver le monde.\n\n"
            "Lumières collectées : " + std::to_string(score) + "\n\n"
            "Réessaie et protège la flamme !\n\n"
            "Appuie sur ENTREE pour revenir au menu."
        );
    }
}

void Level2End::handleEvent(const sf::Event& ev)
{
    if (ev.is<sf::Event::KeyPressed>()) {
        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (keyEv && keyEv->scancode == sf::Keyboard::Scancode::Enter) {
            // Revenir au menu
            gameRef.changeState(std::make_unique<Menu>(gameRef));
        }
    }
}

void Level2End::update(float)
{
    // Écran statique
}

void Level2End::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color(10, 10, 50)); // fond bleu/noir
    window.draw(missionText);
    window.display();
}

