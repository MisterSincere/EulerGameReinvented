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
#include "Button.h"
#include "ecaDefs.h"
#include "EulerAdventure.h"


SCENES::Menu::Menu(sf::Vector2u const& clientSize) {
	// Fonts
	m_pSquareFont = new sf::Font;
	m_pArialFont = new sf::Font;
	assert(m_pSquareFont->loadFromFile("assets/fonts/SquareFont.ttf"));
	assert(m_pArialFont->loadFromFile("assets/fonts/arial.ttf"));

	// Background
	m_pBackground = new GFX::Field;
	m_pBackground->SetBackgroundColor(sf::Color(70, 70, 90));
	m_pBackground->SetBounds(0.0f, 0.0f, float(clientSize.x), float(clientSize.y));

	// Title
	m_pTitle = new GFX::TextBox("Euler Coffee Adventure", *m_pSquareFont, 50);
	m_pTitle->SetPositionAligned(GFX::HORIZONTAL, clientSize);

	// EXIT
	m_pExitButton = new GFX::Button("Fck this shit, im out", *m_pArialFont, 29);
	m_pExitButton->SetPosition(0.0f, clientSize.y - 150.0f);
	m_pExitButton->SetPositionAligned(GFX::HORIZONTAL, clientSize);
	m_pExitButton->SetBackgroundColor(sf::Color(40, 40, 60));
	m_pExitButton->SetPadding(10.0f, 10.0f, 10.0f, 10.0f, true);
	m_pExitButton->AddButtonHandler(this);
}

SCENES::Menu::~Menu() {
	RELEASEP(m_pBackground);
	RELEASEP(m_pTitle);
	RELEASEP(m_pExitButton);
	RELEASEP(m_pSquareFont);
	RELEASEP(m_pArialFont);
}

void SCENES::Menu::Handle(CORETOOLS::ButtonEvent event, GFX::Button* button) {
	if (event == CORETOOLS::CLICK && button == m_pExitButton) {
		EulerAdventure::ChangeGameState(EXIT);
	}
}

void SCENES::Menu::Update(sf::Event const& event) {
	m_pBackground->Update(event);
	m_pTitle->Update(event);
	m_pExitButton->Update(event);
}

void SCENES::Menu::Draw(sf::RenderWindow& rw) {
	m_pBackground->Draw(rw);
	m_pTitle->Draw(rw);
	m_pExitButton->Draw(rw);
}
