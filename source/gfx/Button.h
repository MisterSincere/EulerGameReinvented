#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>

/////////////////
// MY INCLUDES //
/////////////////
#include "TextBox.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace CORETOOLS {
	class IButtonHandler;
	class Mouse;
}

namespace GFX {

	class Button : public TextBox {
	public:
		Button(char const* text, /*sf::Font const& font, */unsigned int charSize = 20u);
		~Button();

		void Update(/*sf::Event const&*/) override;

		void AddButtonHandler(CORETOOLS::IButtonHandler*);

		void SetPosition(float x, float y) override;
		void SetPadding(float left, float top, float right, float bottom, bool expand = false) override;

	private:
		std::vector<CORETOOLS::IButtonHandler*> m_handler;

		CORETOOLS::Mouse* m_pMouse;
		/*sf::FloatRect* m_pButtonBox;*/

		bool m_hovered{ false };
		bool m_hoveredPrev{ false };
	};
}