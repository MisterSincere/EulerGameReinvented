#include "TextInputHandler.h"

//////////////
// INCLUDES //
//////////////
#include <cstring>

/////////////////
// MY INCLUDES //
/////////////////
#include "AutoComplete.h"

void CORETOOLS::TextInputHandler::Handle(char const* text)
{
	if (strcmp(text, "exit") == 0) {
		m_pWindow->close();
	}
}

CORETOOLS::AutoComplete* CORETOOLS::TextInputHandler::AcquireAutoComplete()
{

	return nullptr;
}