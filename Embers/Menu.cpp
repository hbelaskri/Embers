#include "Menu.h"
#include "Game.h"
#include "Level1.h"
#include "Level1End.h"
#include <iostream>

Menu::Menu(Game& game)
    : gameRef(game), titleText(font), missionText(font), instrText(font),
    level2Text(font)
{
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // --- Titre principal ---
    titleText.setString("Embers : Les Dernières Lueurs");
    titleText.setCharacterSize(40); // taille réduite
    titleText.setFillColor(sf::Color::White);
    titleText.setOutlineColor(sf::Color(255, 100, 0)); // rouge-orangée
    titleText.setOutlineThickness(3.f);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition({ 50.f, 50.f });

    // --- Texte de mission / instructions ---
    missionText.setFont(font);
    missionText.setString(
        "Le monde est envahi par l'ombre et la lumière faiblit...\n\n"
        "Toi, porteur de la braise, tu es choisi pour protéger la dernière flamme.\n"
        "Affronte les créatures de l'ombre et préserve l'espoir.\n\n"
        "Appuie sur ENTREE pour commencer le niveau 1.\n"
        "Appuie sur 2 pour tester directement le niveau 2.\n"
        "Appuie sur ESPACE pour quitter le jeu."
    );
    missionText.setCharacterSize(22);
    missionText.setFillColor(sf::Color(220, 220, 255)); // bleu clair
    missionText.setStyle(sf::Text::Regular);
    missionText.setPosition({ 50.f, 180.f });

    // --- Instructions de déplacement ---
    instrText.setFont(font);
    instrText.setString("Utilise ZQSD pour te déplacer");
    instrText.setCharacterSize(20);
    instrText.setFillColor(sf::Color(180, 255, 180)); // vert doux
    instrText.setPosition({ 50.f, 500.f });
}

void Menu::handleEvent(const sf::Event& ev)
{
    if (ev.is<sf::Event::KeyPressed>()) {
        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (!keyEv) return;

        // ENTREE : niveau 1
        if (keyEv->code == sf::Keyboard::Key::Enter) {
            gameRef.changeState(std::make_unique<Level1>(gameRef, gameRef.getWindow().getSize()));
        }
        // Touche 2 : écran intermédiaire Level1End
        else if (keyEv->code == sf::Keyboard::Key::Num2 || keyEv->code == sf::Keyboard::Key::Numpad2) {
            gameRef.changeState(std::make_unique<Level1End>(gameRef));
        }
        // ESPACE : quitter
        else if (keyEv->code == sf::Keyboard::Key::Space) {
            gameRef.getWindow().close();
        }
    }
}

void Menu::update(float)
{
    // pas de logique particulière pour le menu
}

void Menu::draw(sf::RenderWindow& window)
{
    window.clear(sf::Color(15, 15, 30)); // fond sombre
    window.draw(titleText);
    window.draw(missionText);
    window.draw(instrText);
    // NE PAS appeler window.display() ici
}
