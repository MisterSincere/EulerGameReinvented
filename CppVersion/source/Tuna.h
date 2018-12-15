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
#include "GameManager.h"
#include "Options.h"


enum GameState {
	RUNNING,
	INITIALIZING,
	INGAME,
	DEAD,
	OPTIONS,
	ESCAPE = OPTIONS,
	EXIT,
};

class Tuna
{
public:
	Tuna();

	bool Init();

	int Run();

private:
	bool InitSystems();
	bool InitContent();

	void Update();
	void Draw();

	void SetStyleRelative(sf::Vector2u const& newSize);

private:
	CORETOOLS::Settings m_settings; //< Constructor
	CORETOOLS::Options* m_pOptions; //< Constructor
	sf::RenderWindow m_window;

	sf::Font m_arialFont;
	sf::Font m_squareFont;

	ECA::GameManager* m_pInputHandler{ new ECA::GameManager(&m_window) };

	GFX::TextBox m_outputBox;
	GFX::InputBox m_inputBox;

	bool m_isInitialized{ false };
	GameState m_gameState{ RUNNING };
};