#include "InputBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <limits.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "AutoComplete.h"


GFX::InputBox::InputBox()
{
	m_prefix = "> ";
	m_renderText.setString(m_prefix);
}

void GFX::InputBox::Update(sf::Event const& event)
{
	bool removeDone = false;

	switch (event.type)
	{
	case sf::Event::TextEntered:
		if (isValidText(event.text.unicode))
		{
			m_currentString += event.text.unicode;
		}
		else if (event.text.unicode == 0x08 && m_currentString.getSize()) //< Backspace pressed test
		{
			m_currentString.erase(m_currentString.getSize() - 1);
			removeDone = true;
		}
		else if (event.text.unicode == 0x000D) //< Return pressed signal handler
		{
			for (auto handle : m_handler) handle.Handle(m_currentString.toAnsiString().c_str());
			m_currentString.clear();
		}
		else if (event.text.unicode == 0x0009)	//< tabulator pressed
		{
			int minNumChanged{ INT_MAX }, currNumChanged{ 0 };
			sf::String currNewString;
			for (auto completion : m_autoCompleter)
			{
				if (!completion) continue;
				// Make completion call
				currNumChanged = completion->Complete(m_currentString, currNewString);
				// If we are nearer update everything
				if (minNumChanged >= currNumChanged && currNumChanged > 0) {
					m_currentString = currNewString;
					minNumChanged = currNumChanged;
				}
			}
		}
		break;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !removeDone)
	{
		m_currentString.clear();
	}

	// Set to the new string
	m_renderText.setString(m_prefix + m_currentString);
}

void GFX::InputBox::AddHandler(CORETOOLS::TextInputHandler& handler)
{
	m_handler.push_back(handler);
	m_autoCompleter.push_back(handler.AcquireAutoComplete());
}