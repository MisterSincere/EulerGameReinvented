#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace GFX
{
	class InputBox : public sf::Text
	{
	public:
		void Update(sf::Event const&);

	private:
		bool isValidText(sf::Uint32);

	private:
		sf::String m_currentString;
	};
}