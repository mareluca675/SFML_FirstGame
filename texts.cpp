#include "texts.h"
#include <iostream>

Texts::Texts() {
	endGameWonText.setString("You won!");
	endGameSpaceText.setString("Press SPACE to play again.");
}

void Texts::setUpText(sf::Text* text, sf::Vector2f position) {
	text->setFont(font);
	text->setCharacterSize(50);
	text->setFillColor(sf::Color::White);
	text->setStyle(sf::Text::Bold);
	text->setPosition(position);
}

bool Texts::perfromSetup() {
	if (!font.loadFromFile("sfml-assets/arial.TTF")) {
		std::cout << "ERROR: Could not load font.\n";
		return false;
	}

	setUpText(&energyText, sf::Vector2f(650, 800));
	setUpText(&timeText, sf::Vector2f(650, 900));
	setUpText(&endGameWonText, sf::Vector2f(400, 600));
	setUpText(&endGameTimeText, sf::Vector2f(400, 700));
	setUpText(&endGameSpaceText, sf::Vector2f(200, 800));

	return true;
}

void Texts::drawInGameTexts(sf::RenderWindow* window, sf::Time time, int energy) {
	energyText.setString("Energy: " + std::to_string(energy));
	timeText.setString("Time: " + std::to_string(static_cast<int>(time.asSeconds())) + 's');
	window->draw(energyText);
	window->draw(timeText);	
}

void Texts::drawEndGameTexts(sf::RenderWindow* window, sf::Time time) {
	endGameTimeText.setString("Time: " + std::to_string(static_cast<int>(time.asSeconds())) + 's');
	window->draw(endGameWonText);
	window->draw(endGameTimeText);
	window->draw(endGameSpaceText);
}