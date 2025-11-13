#include "Level2Fail.h"
#include "Menu.h"
#include <iostream>

Level2Fail::Level2Fail(Game& game, int finalScore)
    : gameRef(game), failText(font), score(finalScore)
{
    if (!font.openFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Erreur chargement font Level2Fail\n";
    }


    failText.setString(
        "Vous n'avez pas reussi à sauver le monde.\n"
        "Lumieres collectees : " + std::to_string(score) + "\n\n"
        "Appuyez sur ENTREE pour revenir au menu et reessayer."
    );
    failText.setFont(font);
    failText.setCharacterSize(30);
    failText.setFillColor(sf::Color::Red);
    failText.setOutlineColor(sf::Color::Black);
    failText.setOutlineThickness(2.f);
    failText.setPosition({ 50.f, 200.f });

    

}

void Level2Fail::handleEvent(const sf::Event& ev) {
    if (ev.is<sf::Event::KeyPressed>()) {
        const auto* keyEv = ev.getIf<sf::Event::KeyPressed>();
        if (keyEv && keyEv->scancode == sf::Keyboard::Scancode::Enter) {
            gameRef.changeState(std::make_unique<Menu>(gameRef));
        }
    }
}

void Level2Fail::update(float) {
    // pas de logique
}

void Level2Fail::draw(sf::RenderWindow& window) {
    window.clear(sf::Color(20, 20, 80));
    window.draw(failText);
}
