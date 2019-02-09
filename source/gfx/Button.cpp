#include "Button.h"

//////////////
// INCLUDES //
//////////////
//#include <SFML/Window/Mouse.hpp>
//#include <SFML/Window/Event.hpp>
//#include <SFML/Graphics/Rect.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "IButtonHandler.h"
#include "Mouse.h"
#include "ecaDefs.h"


GFX::Button::Button(char const* text, /*sf::Font const& font, */unsigned int charSize)
	: TextBox(text, /*font, */charSize)
{
	/*m_pMouse = CORETOOLS::Mouse::GetInstance();
	if (!m_pMouse) {
		MESSAGE("> Mouse needs to be created once, otherwise button event handling won't work correctly!\n");
		return;
	}
	m_pButtonBox = new sf::FloatRect(0.0f, 0.0f, i_size.x + i_leftPadding + i_rightPadding, i_size.y + i_topPadding + i_bottomPadding);*/
}

GFX::Button::~Button() {
	//RELEASEP(m_pButtonBox);
}

void GFX::Button::Update(/*sf::Event const& event*/) {
	//CORETOOLS::ButtonEvent mouseEvt = CORETOOLS::NONE;

	//m_hoveredPrev = m_hovered;
	//m_hovered = m_pMouse->Intersects(m_pButtonBox);

	//// If still hovered ignore hoveredPrev and just check if a left click was made
	//if (m_hovered) {
	//	mouseEvt = (m_pMouse->LeftClicked()) ? CORETOOLS::CLICK : CORETOOLS::HOVER;

	//// Otherwise a release event is triggered if the previous frame this was hovered
	//} else if(m_hoveredPrev) {
	//	mouseEvt = CORETOOLS::RELEASE;
	//}

	//// If we got a mouse event pass it to the handler
	//if (mouseEvt != CORETOOLS::NONE) {
	//	for (auto curHandler : m_handler) curHandler->Handle(mouseEvt, this);
	//}
}

void GFX::Button::AddButtonHandler(CORETOOLS::IButtonHandler* handler) {
	/*if (!handler) return;
	m_handler.push_back(handler);*/
}

void GFX::Button::SetPosition(float x, float y) {
	/*TextBox::SetPosition(x, y);
	m_pButtonBox->left = x;
	m_pButtonBox->top = y;*/
}

void GFX::Button::SetPadding(float left, float top, float right, float bottom, bool expand) {
	/*TextBox::SetPadding(left, top, right, bottom, expand);
	m_pButtonBox->width = i_size.x;
	m_pButtonBox->height = i_size.y + top + bottom;
	m_pButtonBox->left = i_position.x;
	m_pButtonBox->top = i_position.y;*/
}
