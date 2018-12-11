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

	void ProcessInput();

private:
	sf::RenderWindow m_window;
	sf::Font m_arialFont;

	GFX::InputBox m_inputBox;

	bool m_isInitialized{ false };
};