#include "InputBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <limits.h>
#include <algorithm>

/////////////////
// MY INCLUDES //
/////////////////
#include "AutoComplete.h"


GFX::InputBox::InputBox()
{
	m_prefix = "> ";
	i_renderText.setString(m_prefix);
}

void GFX::InputBox::Update(sf::Event const& event)
{
	bool removeDone = false; //< TODO: Needed?


	// TextEntered is also used for key hit events
	if (event.type == sf::Event::TextEntered) {

		// TEXT
		if (isValidText(event.text.unicode)) {
			i_curStringWrapped += event.text.unicode;
			m_autoCompleteCmds.clear(); //< New autocomplete needed

		// BACKSPACE
		} else if (event.text.unicode == 0x08 && i_curStringWrapped.getSize()) {
			i_curStringWrapped.erase(i_curStringWrapped.getSize() - 1);
			removeDone = true;
			m_autoCompleteCmds.clear(); //< New autocomplete needed

		// RETURN
		} else if (event.text.unicode == 0x000D) {
			for (auto handle : m_textHandler) handle->Handle(i_curStringWrapped.toAnsiString().c_str());
			i_curStringWrapped.clear();
			m_autoCompleteCmds.clear(); //< New autocomplete needed
		
		// TAB (autocomplete)
		} else if (event.text.unicode == 0x0009 && i_curStringWrapped.getSize() && m_pAutoCompleter) {

			// If we have no auto complete suggestions get some...
			if (m_autoCompleteCmds.empty()) {
				
				m_autoCompleteCmds = m_pAutoCompleter->MultiComplete(i_curStringWrapped);
				m_autoCompleteCmdIndex = 0u;
				if(!m_autoCompleteCmds.empty()) i_curStringWrapped = m_autoCompleteCmds[0].get();

			//... otherwise query through them
			} else {
				m_autoCompleteCmdIndex = ++m_autoCompleteCmdIndex % m_autoCompleteCmds.size();
				i_curStringWrapped = m_autoCompleteCmds[m_autoCompleteCmdIndex].get();
			}

		}

	}

	// Ctrl + BackSpace removes entire string
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !removeDone)
	{
		i_curStringWrapped.clear();
		m_autoCompleteCmds.clear();
	}

	// Update string to render
	i_renderText.setString(m_prefix + i_curStringWrapped);
}

void GFX::InputBox::AddHandler(CORETOOLS::TextInputHandler* handler)
{
	m_textHandler.push_back(handler);
}

void GFX::InputBox::SetAutoCompleter(CORETOOLS::AutoComplete* autoComplete)
{
	m_pAutoCompleter = autoComplete;
}