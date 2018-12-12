#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "command.h"

namespace CORETOOLS
{
	///////////////////////////
	// FOREWARD DECLARATIONS //
	///////////////////////////
	class AutoComplete;

	class TextInputHandler
	{
	public:
		TextInputHandler(sf::RenderWindow*);

		void Handle(char const* text);

		AutoComplete* AcquireAutoComplete();

	private:
		sf::RenderWindow* m_pWindow;
		CORETOOLS::CmdList m_commands;
	};
}