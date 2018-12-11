#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>


/////////////////
// MY INCLUDES //
/////////////////
#include "IDrawable.h"


///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf
{
	typedef unsigned int Uint32;
	class Font;
	class Color;
}

namespace GFX
{
	class InputBox : public IDrawable
	{
	public:
		void Update(sf::Event const&) override;
		void Draw(sf::RenderWindow&) override;

		void setFont(sf::Font const&);
		void setCharacterSize(unsigned int);
		void setFillColor(sf::Color const&);

	private:
		bool isValidText(sf::Uint32);

	private:
		sf::String m_currentString;
		sf::Text m_renderText;
	};
}