#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "IHandler.h"
#include "command.h"

namespace CORETOOLS
{
	///////////////////////////
	// FOREWARD DECLARATIONS //
	///////////////////////////
	class AutoComplete;

	class TextInputHandler : public IHandler<char const*>
	{
	public:
		TextInputHandler(sf::RenderWindow*);

		void Handle(char const* text) override;

		AutoComplete* AcquireAutoComplete();

	private:
		CORETOOLS::CmdList m_commands;
	};
}