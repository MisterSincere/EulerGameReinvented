#pragma once

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
		virtual void Update(sf::Event const&) = 0;
		virtual void Draw(sf::RenderWindow& window) = 0;

		virtual void SetBounds(float x, float y, float w, float h) = 0;
	};

}