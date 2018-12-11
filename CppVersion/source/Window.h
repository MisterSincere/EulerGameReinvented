#pragma once


//////////////
// INCLUDES //
//////////////
#include <SFML/Window.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "typedefs.h"

namespace GFX
{
	class Window
	{
	public:
		Window(Utils::WindowCreateInfo const& createInfo);
		~Window();

		bool pollEvent(sf::Event& event);
		void close();
		bool isOpen() const;
		Utils::Rect32U const& getSize() const;
		sf::Window const& getWindow() const;

	private:
		sf::Window m_window;

		Utils::Rect32U m_size;
	};
}