#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "TextBox.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace CORETOOLS {
	class IButtonHandler;
}

namespace GFX {

	class Button : public TextBox {
	public:
		Button(char const* text, sf::Font const& font, unsigned int charSize = 20u);
		~Button();

		void Update(sf::Event const&) override;

		void AddButtonHandler(CORETOOLS::IButtonHandler*);

		void SetPosition(float x, float y) override;

	private:
		std::vector<CORETOOLS::IButtonHandler*> m_handler;

		sf::FloatRect* m_pMouseBox;
		sf::FloatRect* m_pButtonBox;
	};
}