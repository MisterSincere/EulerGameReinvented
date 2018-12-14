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
		void Draw(sf::RenderWindow&) override;

		void AddHandler(CORETOOLS::TextInputHandler*);
		void SetAutoCompleter(CORETOOLS::AutoComplete*);

	private:
		std::vector<CORETOOLS::TextInputHandler*> m_textHandler;
		CORETOOLS::AutoComplete* m_pAutoCompleter{ nullptr };

		sf::String m_prefix;

		std::vector<CORETOOLS::Cmd> m_autoCompleteCmds;
		unsigned int m_autoCompleteCmdIndex{ 0u };
	};
}