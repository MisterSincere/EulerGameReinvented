#include "TextInputHandler.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "AutoComplete.h"


ECA::TextInputHandler::TextInputHandler(sf::RenderWindow* pWindow)
	: ITextHandler(pWindow)
{
	m_commands += "exit";
	m_commands += "explore";
	m_commands += "examine";
	m_commands += "examine inv";
	m_commands += "interact";
	m_commands += "interact inv";
	m_commands += "go";
	m_commands += "load";
	m_commands += "save";
	m_commands += "back";
}

void ECA::TextInputHandler::Handle(char const* text) {
	if (m_commands["exit"] == text) {
		i_pWindow->close();
	}
}

CORETOOLS::AutoComplete* ECA::TextInputHandler::AcquireAutoComplete() {
	return new CORETOOLS::AutoComplete(m_commands);
}