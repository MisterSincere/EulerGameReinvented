#pragma once

//////////////
// INCLUDES //
//////////////
#include <EEApplication.h>
#include <gfx/EERectangle.h>

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
namespace CORETOOLS {
	class Mouse;
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

	static void ChangeGameState(GameState gs);

private:
	bool InitSystems();
	bool InitContent();

	void Update();
	void Draw();

private:
	EEApplication m_application;
	GFX::EERectangle* m_pRect;
	Settings m_settings;

	CORETOOLS::Mouse* m_pMouse{ nullptr };

	SCENES::Tuna* m_pTuna{ nullptr };
	SCENES::Menu* m_pMenu{ nullptr };

	static GameState m_gameState;
};