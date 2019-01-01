#pragma once


/////////////////
// MY INCLUDES //
/////////////////
#include "IDrawable.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
//namespace sf
//{
//	class RectangleShape;
//	class Color;
//}

namespace GFX
{
	class Field : public IDrawable
	{
	public:
		Field(/*sf::Vector2f const& size = { 0.0f, 0.0f }, sf::Vector2f const& position = { 0.0f, 0.0f }*/);
		virtual ~Field();

		virtual void Update(/*sf::Event const&*/) override;
		virtual void Draw(/*sf::RenderWindow&*/) override;

		void SetSize(float w, float h) override;
		void SetPosition(float x, float y) override;


		void SetBackgroundColor(/*sf::Color const& bgColor*/);

	private:
		/*sf::RectangleShape* m_pRect;*/
	};
}