#pragma once

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "ecaDefs.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace SCENES {
	class Tuna;
	class Menu;
}


class EulerAdventure {
public:
	EulerAdventure();
	~EulerAdventure();

	/**
	 * Starts the whole initializing process. First the system components then
	 * the contents of the euler game.
	 *
	 * @return Indicates wether the initialization was successfull and if run can be called
	 **/
	bool Init();

	/**
	 * Starts the game loop
	 *
	 * @return Error code for windows
	 **/
	int Run();

private:
	bool InitSystems();
	bool InitContent();

	void Update();
	void Draw();

private:
	sf::RenderWindow m_window;
	Settings m_settings;

	SCENES::Tuna* m_pTuna{ nullptr };
	SCENES::Menu* m_pMenu{ nullptr };

	GameState m_gameState{ RUNNING };
};