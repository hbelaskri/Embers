#include "Level1End.h"
#include "Level2.h"
#include <iostream>

Level1End::Level1End(Game& game) : gameRef(game), titleText(font), missionText(font)
{
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur chargement police Level1End\n";
    }

    // --- Titre ---
    titleText.setString(" Prépare-toi pour le Boss ");
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    titleText.setOutlineColor(sf::Color(255, 100, 0)); // rouge-orangée
    titleText.setOutlineThickness(3.f);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition({ 50.f, 50.f });

    // --- Texte de mission / transition ---
    missionText.setString(
        "Bravo ! Tu as survécu au premier niveau.\n\n"
        "Mais le danger n'est pas terminé...\n\n"
        "Shadow, le seigneur des ténèbres, t'attend.\n"
        "Prépare-toi à affronter le Boss et son armée !\n\n"
        "Appuie sur ENTREE pour entrer dans l'arène."
    );
    missionText.setCharacterSize(22);
    missionText.setFillColor(sf::Color(220, 220, 255)); // bleu clair
    missionText.setStyle(sf::Text::Regular);
    missionText.setPosition({ 50.f, 150.f });
}

void Level1End::handleEvent(const sf::Event& ev) {
    if (ev.is<sf::Event::KeyPressed>()) {
        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (!keyEv) return;
        if (keyEv->code == sf::Keyboard::Key::Enter) {
            gameRef.changeState(std::make_unique<Level2>(gameRef.getWindow().getSize()));
        }
    }
}

void Level1End::update(float) {
    // pas de logique particulière
}

void Level1End::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.draw(titleText);
    window.draw(missionText);
    // NE PAS appeler window.display() ici
}
