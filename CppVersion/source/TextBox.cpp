#include "TextBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


void GFX::TextBox::Update(sf::Event const& event)
{
	// Static text can be set with setText
}

void GFX::TextBox::Draw(sf::RenderWindow& window)
{
	window.draw(m_renderText);
}

bool GFX::TextBox::isValidText(sf::Uint32 character)
{
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;

	return isNumber || isBigLetter || isSmallLetter;
}

void GFX::TextBox::SetBounds(float x, float y, float w, float h)
{
	m_renderText.setCharacterSize(h);
	m_renderText.setPosition(x, y);
}

void GFX::TextBox::SetString(char const* text)
{
	m_renderText.setString(sf::String(text));
}

void GFX::TextBox::SetPosition(float x, float y)
{
	m_renderText.setPosition(x, y);
}

void GFX::TextBox::SetFont(sf::Font const& font)
{
	m_renderText.setFont(font);
}

void GFX::TextBox::SetCharacterSize(unsigned int size)
{
	m_renderText.setCharacterSize(size);
}

void GFX::TextBox::SetFillColor(sf::Color const& color)
{
	m_renderText.setFillColor(color);
}

void GFX::TextBox::SetOutlineColor(sf::Color const& color)
{
	m_renderText.setOutlineColor(color);
}