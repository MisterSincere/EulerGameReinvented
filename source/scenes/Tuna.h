#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/Font.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "InputBox.h"
#include "GameManager.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf {
	class RenderWindow;
	class Event;
}

namespace SCENES {

	class Tuna {
	public:
		Tuna(sf::RenderWindow* pWindow);
		Tuna(Tuna&) = delete;
		~Tuna();

		bool StartInit();

		void Update(sf::Event const& event);
		void Draw();

		void SetStyleRelative(sf::Vector2u const& newSize);


	private:
		sf::RenderWindow* m_pWindow; //< Initializer list

		sf::Font m_arialFont;
		sf::Font m_squareFont;

		ECA::GameManager* m_pGameManager{ new ECA::GameManager(m_pWindow) };

		GFX::TextBox*		m_pOutputBox{ nullptr };
		GFX::InputBox*	m_pInputBox{ nullptr };
	};

}