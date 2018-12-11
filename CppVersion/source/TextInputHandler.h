#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace CORETOOLS
{
	class TextInputHandler
	{
	public:
		TextInputHandler(sf::RenderWindow* window) : m_pWindow(window) {}

		void Handle(char const* text);

	private:
		sf::RenderWindow* m_pWindow;
	};
}