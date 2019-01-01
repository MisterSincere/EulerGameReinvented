#include "Mouse.h"

//////////////
// INCLUDES //
//////////////
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics/Rect.hpp>
//#include <SFML/Window/Event.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "ecaDefs.h"


CORETOOLS::Mouse* CORETOOLS::Mouse::m_pMouse = nullptr;

CORETOOLS::Mouse::Mouse(sf::RenderWindow* rw)
	/*: m_pWindow(rw)*/
{
	/*m_position = sf::Mouse::getPosition(*m_pWindow);*/
}

bool CORETOOLS::Mouse::Create(sf::RenderWindow* rw) {
	RELEASEP(m_pMouse);
	m_pMouse = new Mouse(rw);
	return m_pMouse;
}

CORETOOLS::Mouse* CORETOOLS::Mouse::GetInstance() {
	return m_pMouse;
}

void CORETOOLS::Mouse::Update(sf::Event const& evt) {
	/*m_position = sf::Mouse::getPosition(*m_pWindow);*/

	//MESSAGE("> Mouse %d, %d\n", m_position.x, m_position.y);

	//m_leftClickedPrev = m_leftClicked;
	//m_rightClickedPrev = m_rightClicked;

	//// MOUSE PRESSED
	//if (evt.type == sf::Event::MouseButtonPressed) {
	//	m_leftClicked = evt.mouseButton.button == sf::Mouse::Left;
	//	m_rightClicked = evt.mouseButton.button == sf::Mouse::Right;

	//// MOUSE RELEASED
	//} else if (evt.type == sf::Event::MouseButtonReleased) {
	//	m_leftClicked = !(evt.mouseButton.button == sf::Mouse::Left);
	//	m_rightClicked = !(evt.mouseButton.button == sf::Mouse::Right);
	//}
}

bool CORETOOLS::Mouse::Intersects(sf::FloatRect* otherBox) {
	/*return otherBox->contains(sf::Vector2f(m_position));*/
	return true;
}
