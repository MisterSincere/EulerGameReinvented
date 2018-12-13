#include "TextBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


GFX::TextBox::TextBox()
{
	m_renderText.setCharacterSize(m_characterSize);
	m_renderText.setPosition(m_position);
}

void GFX::TextBox::Update(sf::Event const& event)
{
	// Static text can be set with setText
}

void GFX::TextBox::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_currentString.getSize(); i++) {
		sf::Vector2f pos = m_renderText.findCharacterPos(i);
		if (pos.x > (m_position.x + m_size.x)) {
			i -= InsertLineBreak(i);
		}
	}

	window.draw(m_renderText);
}

bool GFX::TextBox::isValidText(sf::Uint32 character)
{
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;
	bool isSpace = character == 0x0020;

	return isNumber || isBigLetter || isSmallLetter || isSpace;
}

int GFX::TextBox::InsertLineBreak(size_t index)
{
	size_t tempIndex = index;

	unsigned int maxBack = 10u;
	while (index && (m_currentString[index] != ' ' || maxBack--)) index--;

	m_currentString.insert(index, "\n");

	return tempIndex - index;
}

void GFX::TextBox::SetBounds(float x, float y, float w, float h)
{
	if (m_characterSize > h) {
		m_characterSize = static_cast<unsigned int>(h);
		m_renderText.setCharacterSize(m_characterSize);
	}
	m_renderText.setPosition(x, y);
	m_position = { x, y };
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