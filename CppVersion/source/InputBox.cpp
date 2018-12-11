#include "InputBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


void GFX::InputBox::Update(sf::Event const& event)
{
	switch (event.type)
	{
	case sf::Event::TextEntered:
		if (isValidText(event.text.unicode))
		{
			m_currentString += event.text.unicode;
			m_renderText.setString(m_currentString);
		}
		else if (event.text.unicode == 0x08 && m_currentString.getSize())
		{
			m_currentString.erase(m_currentString.getSize() - 1);
			m_renderText.setString(m_currentString);
		}
		break;


	}
}

void GFX::InputBox::Draw(sf::RenderWindow& window)
{
	window.draw(m_renderText);
}

bool GFX::InputBox::isValidText(sf::Uint32 character)
{
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;

	return isNumber || isBigLetter || isSmallLetter;
}

void GFX::InputBox::setFont(sf::Font const& font)
{
	m_renderText.setFont(font);
}

void GFX::InputBox::setCharacterSize(unsigned int size)
{
	m_renderText.setCharacterSize(size);
}

void GFX::InputBox::setFillColor(sf::Color const& color)
{
	m_renderText.setFillColor(color);
}