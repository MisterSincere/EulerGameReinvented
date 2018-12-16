#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>


/////////////////
// MY INCLUDES //
/////////////////
#include "Field.h"


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
		TextBox(char const* text, sf::Font const& font, unsigned int charSize = 20u);
		TextBox(bool haveBackground = true, sf::Vector2f const& size = { 200.0f, 200.0f }, sf::Vector2f const& position = { 0.0f,0.0f }, unsigned int charSize = 20.0f);
		TextBox(TextBox&) = delete;
		TextBox(TextBox&&) = delete;
		virtual ~TextBox();


		virtual void Update(sf::Event const&) override;
		virtual void Draw(sf::RenderWindow&) override;

		void SetSize(float w, float h) override;
		void SetPosition(float x, float y) override;

		void SetPadding(float leftRight, float topBottom, bool expand = false) { SetPadding(leftRight, topBottom, leftRight, topBottom, expand); }
		virtual void SetPadding(float left, float top, float right, float bottom, bool expand = false);
		void SetString(char const* text);
		void SetFont(sf::Font const&);
		void SetCharacterSize(unsigned int);
		void SetTextColor(sf::Color const&);
		void SetTextOutlineColor(sf::Color const&);
		void SetBackgroundColor(sf::Color const&);

		template<typename T>
		T GetString() const;

	protected:
		virtual bool isValidText(sf::Uint32) const;

	protected:
		char const* i_rawString{ nullptr };
		sf::String i_curStringWrapped;
		sf::Text i_renderText;
		float i_leftPadding{ 0.0f }, i_topPadding{ 0.0f }, i_rightPadding{ 0.0 }, i_bottomPadding{ 0.0f };

	private:
		void TextWrap();
		int InsertLineBreak(size_t index);

	private:
		Field* m_pBox{ nullptr };

		unsigned int m_characterSize; //< Initializer list
		bool m_bold{ false };
	};
}