#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "IHandler.h"
#include "command.h"
#include "AutoComplete.h"


namespace CORETOOLS {

	/// ABSTRACT text handler class definition
	class ITextHandler : public IHandler<void, char const*>
	{
	public:
		ITextHandler(sf::RenderWindow* rw) : IHandler(rw) {}
		virtual void Handle(char const*) override = 0;

		CORETOOLS::AutoComplete* AcquireAutoComplete() { return new CORETOOLS::AutoComplete(i_commands); }

	protected:
		CORETOOLS::CmdList i_commands;
	};
}