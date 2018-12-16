#pragma once


///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class Box;
}
namespace sf {
	template<typename T>
	class Vector2;
	typedef Vector2<unsigned int> Vector2u;
}

namespace SCENES {

	class Menu {
	public:
		Menu(sf::Vector2u const& clientSize);
		Menu(Menu&) = delete;
		~Menu();

		void Update();
		void Draw();

	private:
		GFX::Box* m_pBackground;
	};
}