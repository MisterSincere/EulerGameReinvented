#include "InputBox.h"


void GFX::InputBox::Update(sf::Event const& event)
{
	switch (event.type)
	{
	case sf::Event::TextEntered:
		if (isValidText(event.text.unicode))
		{
			m_currentString += event.text.unicode;
			setString(m_currentString);
		}
		else if (event.text.unicode == 0x08 && m_currentString.getSize())
		{
			m_currentString.erase(m_currentString.getSize() - 1);
			setString(m_currentString);
		}
		break;


	}
}

bool GFX::InputBox::isValidText(sf::Uint32 character)
{
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;

	return isNumber || isBigLetter || isSmallLetter;
}