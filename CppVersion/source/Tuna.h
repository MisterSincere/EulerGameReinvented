#pragma once

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
	GFX::InputBox m_inputBox;
	sf::Font m_arialFont;

	bool m_isInitialized{ false };
};