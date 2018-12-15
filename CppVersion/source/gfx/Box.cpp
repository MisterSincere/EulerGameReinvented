#include "Box.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GFX::Box::Box(sf::Vector2f const& size, sf::Vector2f const& position)
	: IDrawable(size, position)
{
	m_pRect = new sf::RectangleShape(i_size);
	m_pRect->setPosition(i_position);
}

GFX::Box::~Box() {
	if (m_pRect) {
		delete m_pRect;
		m_pRect = nullptr;
	}
}

void GFX::Box::Update(sf::Event const& evt) {
	
}

void GFX::Box::Draw(sf::RenderWindow& rw) {
	rw.draw(*m_pRect);
}

void GFX::Box::SetSize(float w, float h) {
	IDrawable::SetSize(w, h);
	m_pRect->setSize(i_size);
}

void GFX::Box::SetPosition(float x, float y) {
	IDrawable::SetPosition(x, y);
	m_pRect->setPosition(i_position);
}

void GFX::Box::SetBackgroundColor(sf::Color const& color) {
	m_pRect->setFillColor(color);
}