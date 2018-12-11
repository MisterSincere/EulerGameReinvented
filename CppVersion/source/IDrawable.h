#pragma once

#include <vector>

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
	};

}