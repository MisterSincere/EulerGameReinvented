#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/System/Vector2.hpp>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf {
	class RenderWindow;
	class Event;
	template<typename T>
	class Rect;
	typedef Rect<float> FloatRect;
}

namespace CORETOOLS {

	class Mouse {
	public:
		static bool Create(sf::RenderWindow*);
		static Mouse* GetInstance();

		void Update(sf::Event const&);

		bool LeftClicked() const { return m_leftClicked; }
		bool RightClicked() const { return m_rightClicked; }
		bool LeftReleased() const { return m_leftClickedPrev && !m_leftClicked; }
		bool RightReleased() const { return m_rightClickedPrev && !m_rightClicked; }

		bool Intersects(sf::FloatRect* otherBox);

	private:
		Mouse(sf::RenderWindow* rw);

	private:
		sf::RenderWindow* m_pWindow;

		sf::Vector2i m_position;
		bool m_leftClicked{ false };
		bool m_rightClicked{ false };
		bool m_leftClickedPrev{ false };
		bool m_rightClickedPrev{ false };

		static Mouse* m_pMouse;
	};
}