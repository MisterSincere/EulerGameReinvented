#pragma once


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
}

namespace SCENES {

	class Menu {
	public:
		Menu(sf::Vector2u const& clientSize);
		Menu(Menu&) = delete;
		~Menu();

		void Update();
		void Draw(sf::RenderWindow& pWindow);

	private:
		GFX::Field* m_pBackground;
		GFX::TextBox* m_pTitle;

		sf::Font* m_pSquareFont;
	};
}