#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "IButtonHandler.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class Field;
	class TextBox;
}
namespace sf {
	template<typename T>
	class Vector2;
	typedef Vector2<unsigned int> Vector2u;
	class RenderWindow;
	class Font;
	class Event;
}

namespace SCENES {

	class Menu : public CORETOOLS::IButtonHandler {
	public:
		Menu(sf::Vector2u const& clientSize);
		Menu(Menu&) = delete;
		~Menu();

		void Handle(CORETOOLS::ButtonEvent, GFX::Button*) override;

		void Update(sf::Event const&);
		void Draw(sf::RenderWindow& pWindow);

	private:
		GFX::Field* m_pBackground;
		GFX::TextBox* m_pTitle;
		GFX::Button* m_pExitButton;

		sf::Font* m_pSquareFont;
		sf::Font* m_pArialFont;
	};
}