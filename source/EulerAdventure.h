/////////////////////////////////////////////////////////////////////
// Filename: EulerAdventure.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

//////////////
// INCLUDES //
//////////////
#include <EEApplication.h>
#include <gfx/EERectangle.h>
#include <gfx/EEFontEngine.h>
#include <gfx/EETextBox.h>

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

	void ChangeGameState(GameState gs);

private:
	bool InitSystems();
	bool InitContent();

	void Update();
	void Draw();

private:
	EEApplication m_application;
	GFX::EEFontEngine* m_pFontEngine;

	SCENES::Tuna* m_pTuna{ nullptr };
	SCENES::Menu* m_pMenu{ nullptr };

	static GameState m_gameState;
};