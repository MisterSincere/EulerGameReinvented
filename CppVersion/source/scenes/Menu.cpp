#include "Menu.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <assert.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "TextBox.h"
#include "ecaDefs.h"


SCENES::Menu::Menu(sf::Vector2u const& clientSize) {
	// Fonts
	m_pSquareFont = new sf::Font;
	assert(m_pSquareFont->loadFromFile("assets/fonts/SquareFont.ttf"));

	// Background
	m_pBackground = new GFX::Field;
	m_pBackground->SetBackgroundColor(sf::Color(70, 70, 90));
	m_pBackground->SetBounds(0.0f, 0.0f, float(clientSize.x), float(clientSize.y));

	// Title
	m_pTitle = new GFX::TextBox("Euler Coffee Adventure", *m_pSquareFont, 50);
	m_pTitle->SetPositionAligned(GFX::HORIZONTAL, clientSize);
}

SCENES::Menu::~Menu() {
	RELEASEP(m_pBackground);
	RELEASEP(m_pTitle);
	RELEASEP(m_pSquareFont);
}

void SCENES::Menu::Update() {

}

void SCENES::Menu::Draw(sf::RenderWindow& rw) {
	m_pBackground->Draw(rw);
	m_pTitle->Draw(rw);
}
