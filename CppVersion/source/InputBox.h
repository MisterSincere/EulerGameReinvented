#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>

/////////////////
// MY INCLUDES //
/////////////////
#include "TextBox.h"
#include "TextInputHandler.h"


namespace GFX
{
	class InputBox : public TextBox
	{
	public:
		InputBox();

		void Update(sf::Event const&) override;

		void AddHandler(CORETOOLS::TextInputHandler&);

	private:
		std::vector<CORETOOLS::TextInputHandler> m_handler;

		sf::String m_prefix;
	};
}