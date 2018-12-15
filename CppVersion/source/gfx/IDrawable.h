#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/System/Vector2.hpp>

//////////////////////////
// FORWARD DECLARATIONS //
//////////////////////////
namespace sf {
	class RenderWindow;
	class Event;
	class Drawable;
}

namespace GFX
{

	class IDrawable
	{
	public:
		IDrawable(sf::Vector2f const& size, sf::Vector2f const& position) : i_size(size), i_position(position) {}

		virtual void Update(sf::Event const&) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

		virtual void SetBounds(float x, float y, float w, float h) { SetPosition(x, y); SetSize(w, h); }
		virtual void SetPosition(float x, float y) { i_position = { x,y }; }
		virtual void SetSize(float w, float h) { i_size = { w,h }; }

		virtual sf::Vector2f GetSize() const { return i_size; }
		virtual sf::Vector2f GetPosition() const { return i_position; }

	protected:
		sf::Vector2f i_size;
		sf::Vector2f i_position;
	};

}