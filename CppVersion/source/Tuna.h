#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "InputBox.h"


class Tuna
{
public:
	bool Init() { return (m_isInitialized = InitSystems() | InitContent()); }

	int Run();

private:
	bool InitSystems();
	bool InitContent();

	void SetStyleRelative(unsigned int width, unsigned int height);

	void ProcessInput();

private:
	sf::RenderWindow m_window;
	sf::Font m_arialFont;

	GFX::InputBox m_inputBox;

	unsigned int m_width{ 800u };
	unsigned int m_height{ 600u };

	bool m_isInitialized{ false };
};