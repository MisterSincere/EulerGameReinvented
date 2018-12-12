#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace CORETOOLS
{
	///////////////////////////
	// FOREWARD DECLARATIONS //
	///////////////////////////
	class AutoComplete;

	class TextInputHandler
	{
	public:
		TextInputHandler(sf::RenderWindow* window) : m_pWindow(window) {}

		void Handle(char const* text);

		AutoComplete* AcquireAutoComplete();

	private:
		sf::RenderWindow* m_pWindow;
	};
}