#include "Field.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


/////////////////
// MY INCLUDES //
/////////////////
#include "ecaDefs.h"


GFX::Field::Field(sf::Vector2f const& size, sf::Vector2f const& position)
	: IDrawable(size, position)
{
	m_pRect = new sf::RectangleShape({ float(i_size.x), float(i_size.y) });
	m_pRect->setPosition(i_position);
}

GFX::Field::~Field() {
	RELEASEP(m_pRect);
}

void GFX::Field::Update(sf::Event const& evt) {
	
}

void GFX::Field::Draw(sf::RenderWindow& rw) {
	rw.draw(*m_pRect);
}

void GFX::Field::SetSize(float w, float h) {
	IDrawable::SetSize(w, h);
	m_pRect->setSize({ float(i_size.x), float(i_size.y) });
}

void GFX::Field::SetPosition(float x, float y) {
	IDrawable::SetPosition(x, y);
	m_pRect->setPosition(i_position);
}

void GFX::Field::SetBackgroundColor(sf::Color const& color) {
	m_pRect->setFillColor(color);
}