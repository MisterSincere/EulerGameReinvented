#include "Button.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Rect.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "IButtonHandler.h"
#include "ecaDefs.h"


GFX::Button::Button(char const* text, sf::Font const& font, unsigned int charSize)
	: TextBox(text, font, charSize)
{
	m_pMouseBox = new sf::FloatRect(0.0f, 0.0f, 5.0f, 8.0f);
	m_pButtonBox = new sf::FloatRect(0.0f, 0.0f, i_size.x, i_size.y);
}

GFX::Button::~Button() {
	RELEASEP(m_pMouseBox);
	RELEASEP(m_pButtonBox);
}

void GFX::Button::Update(sf::Event const& event) {
	bool rightClick = event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right;

	// If the mouse has moved update the mouse box position
	if (event.type == sf::Event::MouseMoved) {
		m_pMouseBox->left = float(event.mouseButton.x);
		m_pMouseBox->top = float(event.mouseButton.y);
	}

	// Check for intersection
	if (m_pMouseBox->intersects(*m_pButtonBox)) {
		CORETOOLS::ButtonEvent event = (rightClick) ? CORETOOLS::CLICK : CORETOOLS::HOVER;
		for (auto curHandler : m_handler) curHandler->Handle(event, this);
	}
}

void GFX::Button::AddButtonHandler(CORETOOLS::IButtonHandler* handler) {
	if (!handler) return;
	m_handler.push_back(handler);
}

void GFX::Button::SetPosition(float x, float y) {
	TextBox::SetPosition(x, y);
	m_pButtonBox->left = x;
	m_pButtonBox->top = y;
}
