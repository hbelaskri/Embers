//#include "Level2End.h"
//#include "Menu.h"
//#include <iostream>
//
//Level2End::Level2End(Game& game, int finalScore)
//    : gameRef(game), score(finalScore), endText(font)
//{
//    if (!font.openFromFile("assets/fonts/arial.ttf")) {
//        std::cerr << "Erreur chargement font Level2End\n";
//    }
//
//    endText.setFont(font);
//    endText.setCharacterSize(24);
//    endText.setFillColor(sf::Color::White);
//    endText.setOutlineColor(sf::Color(255, 100, 0)); // lueur orangée
//    endText.setOutlineThickness(2.f);
//    endText.setPosition({ 50.f, 200.f });
//
//    endText.setString(
//        "Bravo ! Tu as ramené la lumière sur le monde.\n"
//        "Ton courage et ta rapidité ont permis de protéger la flamme.\n\n"
//        "Lumières collectées : " + std::to_string(score) + "\n\n"
//        "Merci d'avoir sauvé le monde !\n"
//        "Appuie sur ENTREE pour revenir au menu."
//    );
//}
//
//void Level2End::handleEvent(const sf::Event& ev) {
//    if (ev.is<sf::Event::KeyPressed>()) {
//        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
//        if (keyEv && keyEv->scancode == sf::Keyboard::Scancode::Enter) {
//            // Retour au menu
//            gameRef.changeState(std::make_unique<class Menu>(gameRef));
//        }
//    }
//}
//
//void Level2End::update(float) {
//    // pas besoin de logique
//}
//
//void Level2End::draw(sf::RenderWindow& window) {
//    window.clear(sf::Color(30, 60, 120)); // fond bleu pas trop clair/pas trop foncé
//    window.draw(endText);
//}

#include "Level2End.h"
#include <iostream>

Level2End::Level2End(int finalScore)
    : score(finalScore), missionText(font)
{
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur chargement font Level2End\n";
    }

    missionText.setFont(font);
    missionText.setCharacterSize(24);
    missionText.setFillColor(sf::Color::White);
    missionText.setStyle(sf::Text::Regular);
    missionText.setPosition({ 50.f, 150.f });

    if (score >= 100) {
        missionText.setString(
            "Bravo ! Tu as assez collecté de lumières pour sauver le monde !\n\n"
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

void Level2End::handleEvent(const sf::Event& ev) {
    // Utilise la nouvelle API SFML 3 pour détecter l'appui sur ENTREE
    if (ev.is<sf::Event::KeyPressed>()) {
        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (keyEv && keyEv->scancode == sf::Keyboard::Scancode::Enter) {
            // TODO: gérer le retour au menu depuis le main ou la Game class
            std::cout << "Retour au menu (implémentation à faire dans Game)\n";
        }
    }
}

void Level2End::update(float) {
    // Pas de logique
}

void Level2End::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black); // fond noir
    window.draw(missionText);
}
