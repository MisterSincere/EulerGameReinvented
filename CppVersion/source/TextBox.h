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
		TextBox();

		virtual void Update(sf::Event const&) override;
		virtual void Draw(sf::RenderWindow&) override;


		void SetBounds(float x, float y, float w, float h) override;
		void SetString(char const* text);
		void SetSize(float w, float h);
		void SetPosition(float x, float y);
		void SetFont(sf::Font const&);
		void SetCharacterSize(unsigned int);
		void SetFillColor(sf::Color const&);
		void SetOutlineColor(sf::Color const&);

		template<typename T>
		T GetString() const;

	protected:
		virtual bool isValidText(sf::Uint32) const;

	private:
		void TextWrap();
		int InsertLineBreak(size_t index);

	protected:
		char const* m_rawString{ nullptr };
		sf::String m_curStringWrapped;
		sf::Text m_renderText;

		unsigned int m_characterSize{ 20u };
		sf::Vector2f m_position{ 0.0f, 0.0f };
		sf::Vector2f m_size{ 200.0f, 200.0f };
	};
}