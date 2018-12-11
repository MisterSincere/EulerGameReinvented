#include "TextInputHandler.h"

#include <cstring>

void CORETOOLS::TextInputHandler::Handle(char const* text)
{
	if (strcmp(text, "exit") == 0) {
		printf("Hallossd");
		m_pWindow->close();
	}
}