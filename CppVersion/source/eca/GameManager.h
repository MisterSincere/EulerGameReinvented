#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "ITextHandler.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace CORETOOLS {
	class AutoComplete;
}

namespace ECA {

	class GameManager : public CORETOOLS::ITextHandler {
	public:
		GameManager(sf::RenderWindow*);

		void Handle(char const* text) override;
	};
}