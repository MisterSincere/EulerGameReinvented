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
	class TextBox : public IDrawable
	{
	public:
		virtual void Update(sf::Event const&) override;
		virtual void Draw(sf::RenderWindow&) override;


		virtual void SetBounds(float x, float y, float w, float h) override;
		void SetString(char const* text);
		void SetPosition(float x, float y);
		void SetFont(sf::Font const&);
		void SetCharacterSize(unsigned int);
		void SetFillColor(sf::Color const&);
		void SetOutlineColor(sf::Color const&);

	protected:
		virtual bool isValidText(sf::Uint32);

	protected:
		sf::String m_currentString;
		sf::Text m_renderText;
	};
}