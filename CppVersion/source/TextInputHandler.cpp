#include "TextInputHandler.h"

/////////////////
// MY INCLUDES //
/////////////////
#include "AutoComplete.h"

CORETOOLS::TextInputHandler::TextInputHandler(sf::RenderWindow* pWindow)
	: m_pWindow(pWindow)
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

void CORETOOLS::TextInputHandler::Handle(char const* text)
{
	if (m_commands["exit"] == text) {
		m_pWindow->close();
	}
}

CORETOOLS::AutoComplete* CORETOOLS::TextInputHandler::AcquireAutoComplete()
{
	return new AutoComplete(m_commands);
}