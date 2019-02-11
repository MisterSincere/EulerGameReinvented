#include "EulerAdventure.h"

//////////////
// INCLUDES //
//////////////
#include <iostream>

/////////////////
// MY INCLUDES //
/////////////////
#include "Tuna.h"
#include "Menu.h"
#include "Mouse.h"

GameState EulerAdventure::m_gameState = RUNNING;

EulerAdventure::EulerAdventure() {
}

EulerAdventure::~EulerAdventure() {
	RELEASEP(m_pTuna);
	RELEASEP(m_pMenu);
}

bool EulerAdventure::Init() {
	ChangeGameState(INITIALIZING);

	if (!InitSystems()) return false;
	if (!InitContent()) return false;

	return true;
}

bool EulerAdventure::InitSystems() {
	//
	// WINDOW
	//
	{
		EEApplicationCreateInfo appCInfo;
		appCInfo.flags = EE_WINDOW_FLAGS_CENTER;
		appCInfo.clientSize = { 1100, 700u };
		appCInfo.position = { 0,0 };
		appCInfo.screenMode = EE_SCREEN_MODE_WINDOWED;
		appCInfo.title = "EulerAdventure";
		appCInfo.icon = nullptr;
		appCInfo.mouseDisabled = EE_FALSE;
		appCInfo.splitscreen = EE_SPLITSCREEN_MODE_NONE;
		appCInfo.rendererType = EE_RENDER_TYPE_BOTH;

		if (!m_application.Create(appCInfo)) return false;
	}

	m_pFontEngine = new GFX::EEFontEngine(&m_application);

	return true;
}

bool EulerAdventure::InitContent() {

	m_pMenu = new SCENES::Menu(m_pFontEngine);
	assert(m_pMenu);

	m_pTuna = new SCENES::Tuna(m_pFontEngine);
	assert(m_pTuna);

	return true;
}

int EulerAdventure::Run() {

	ChangeGameState(MENU);

	while (m_gameState != EXIT && !m_application.PollEvent()) {

		Update();

		Draw();
	}

	return 0;
}

void EulerAdventure::Update() {

	m_pFontEngine->Update();

	// ESCAPE
	if (m_application.KeyHit(EE_KEY_ESCAPE)) {
		if (m_gameState == MENU) {
			ChangeGameState(INGAME);
		} else if(m_gameState == INGAME) {
			ChangeGameState(MENU);
		}
	}
	

	switch (m_gameState) {
	case INGAME:
		m_pTuna->Update(this);
		break;

	case MENU:
		m_pMenu->Update(this);
		break;
	}
}

void EulerAdventure::Draw() {
	switch (m_gameState) {
	case INGAME:
		m_pTuna->Draw();
		break;

	case MENU:
		m_pMenu->Draw();
		break;
	}
}

void EulerAdventure::ChangeGameState(GameState gs) {
	if (gs == m_gameState) return;
#ifdef _DEBUG
	printf("> Changed game state from %d to %d\n", m_gameState, gs);
#endif
	if (m_gameState == MENU) m_pMenu->SetVisibility(false);
	else if (m_gameState == INGAME) m_pTuna->SetVisibility(false);
	m_gameState = gs;
	if (m_gameState == MENU) m_pMenu->SetVisibility(true);
	else if (m_gameState == INGAME) m_pTuna->SetVisibility(true);
}



/*** MAIN ENTRY POINT ***/
int main(char** argv, int argc) {
	EulerAdventure* ea = new EulerAdventure;
	assert(ea);

	// Let the game set itself up
	if (!ea->Init()) return -1;

	// Start main loop
	int retVal = ea->Run();
	if (retVal) system("PAUSE");

	// Free memory
	delete ea;

	return retVal;
}