#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>

/////////////////
// MY INCLUDES //
/////////////////
#include "TextBox.h"
#include "command.h"

//////////////////////////
// FOREWARD DECLARATION //
//////////////////////////
namespace CORETOOLS {
	class ITextHandler;
	class AutoComplete;
}


namespace GFX
{
	class InputBox : public TextBox
	{
	public:
		InputBox(bool haveBackground = false, sf::Vector2f const& size = { 0.0f, 0.0f }, sf::Vector2f const& position = { 0.0f,0.0f }, unsigned int charSize = 20.0f);

		void Update(sf::Event const&) override;

		void AddHandler(CORETOOLS::ITextHandler*);
		void SetAutoCompleter(CORETOOLS::AutoComplete*);

	private:
		std::vector<CORETOOLS::ITextHandler*> m_textHandler;
		CORETOOLS::AutoComplete* m_pAutoCompleter{ nullptr };

		sf::String m_prefix;

		std::vector<CORETOOLS::Cmd> m_autoCompleteCmds;
		unsigned int m_autoCompleteCmdIndex{ 0u };
	};
}