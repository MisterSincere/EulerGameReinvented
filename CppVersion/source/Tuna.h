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
#include "TextInputHandler.h"


class Tuna
{
public:
	bool Init() { return (m_isInitialized = InitSystems() & InitContent()); }

	int Run();

private:
	bool InitSystems();
	bool InitContent();

	void SetStyleRelative(unsigned int width, unsigned int height);

	void ProcessInput();

private:
	sf::RenderWindow m_window;

	sf::Font m_arialFont;
	sf::Font m_squareFont;

	ECA::TextInputHandler* m_pInputHandler{ new ECA::TextInputHandler(&m_window) };

	GFX::TextBox m_outputBox;
	GFX::InputBox m_inputBox;

	unsigned int m_width{ 1100u };
	unsigned int m_height{ 700u };

	bool m_isInitialized{ false };
};