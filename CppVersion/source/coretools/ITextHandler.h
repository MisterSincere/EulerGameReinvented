#pragma once

//////////////
// INCLUDES //
//////////////
#include "IHandler.h"

namespace CORETOOLS {

	/// ABSTRACT text handler class definition
	class ITextHandler : public IHandler<char const*, void>
	{
	public:
		ITextHandler(sf::RenderWindow* rw) : IHandler(rw) {}
		virtual void Handle(char const*) override = 0;
	};
}