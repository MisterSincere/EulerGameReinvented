#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "ITextHandler.h"
#include "command.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace CORETOOLS {
	class AutoComplete;
}

namespace ECA {

	class TextInputHandler : public CORETOOLS::ITextHandler {
	public:
		TextInputHandler(sf::RenderWindow*);

		void Handle(char const* text) override;

		CORETOOLS::AutoComplete* AcquireAutoComplete();

	private:
		CORETOOLS::CmdList m_commands;
	};
}