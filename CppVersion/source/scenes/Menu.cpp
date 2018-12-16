#include "Menu.h"

/////////////////
// MY INCLUDES //
/////////////////
#include "Field.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/System/Vector2.hpp>


SCENES::Menu::Menu(sf::Vector2u const& clientSize) {
	m_pBackground = new GFX::Field;
}

SCENES::Menu::~Menu() {
	if (m_pBackground) {
		delete m_pBackground;
		m_pBackground = nullptr;
	}
}

void SCENES::Menu::Update() {

}

void SCENES::Menu::Draw() {

}
