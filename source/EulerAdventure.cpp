#include "EulerAdventure.h"

//////////////
// INCLUDES //
//////////////
#include <iostream>
//#include <SFML/Window/Event.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "Tuna.h"
#include "Menu.h"
#include "Mouse.h"

GameState EulerAdventure::m_gameState = RUNNING;

EulerAdventure::EulerAdventure() {
	m_settings.screenMode = WINDOWED;
	m_settings.frameLimit = 60u;
	/*m_settings.clientSize = { 1100u, 700u };*/
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
		//int style = sf::Style::Default;
		//if (m_settings.screenMode == FAKE_FULLSCREEN) {
		//	style = sf::Style::None;
		//	m_settings.clientSize = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };
		//} else if (m_settings.screenMode == FULLSCREEN) {
		//	style = sf::Style::Fullscreen;
		//}

		//sf::ContextSettings settings;
		//settings.antialiasingLevel = m_settings.antialisingCount;

		//// Create window and set its settings
		//m_window.create(sf::VideoMode(m_settings.clientSize.x, m_settings.clientSize.y), m_settings.title, style, settings);
		//m_window.setFramerateLimit(m_settings.frameLimit);
		//m_window.setVerticalSyncEnabled(m_settings.vsyncEnabled);

		//// In fullscreen acquire now the client size
		//m_settings.clientSize = m_window.getSize();
	}
	{
		EEApplicationCreateInfo appCInfo;
		appCInfo.flags = EE_WINDOW_FLAGS_CENTER;
		appCInfo.clientSize = { 800u, 600u };
		appCInfo.position = { 0,0 };
		appCInfo.screenMode = EE_SCREEN_MODE_WINDOWED;
		appCInfo.title = "EulerAdventure";
		appCInfo.icon = nullptr;
		appCInfo.mouseDisabled = EE_FALSE;
		appCInfo.splitscreen = EE_SPLITSCREEN_MODE_NONE;
		appCInfo.rendererType = EE_RENDER_TYPE_BOTH;
		m_application.Create(appCInfo);

		m_pRect = new GFX::EERectangle(&m_application);
		m_pRect->SetPosition({ 0.0f, 0.0f });
		m_pRect->SetSize({200u, 200u});
		m_pRect->SetBackgroundColor({ 0.0f, 1.0f, 0.0f, 1.0f });

		m_pRect2 = new GFX::EERectangle(&m_application);
		m_pRect2->SetPosition({ 100.0f, 100.0f });
		m_pRect2->SetSize({ 200u, 200u });
		m_pRect2->SetBackgroundColor({ 1.0f, 0.0f, 0.0f, .5f });
	}

	//
	// MOUSE REPRESENTATION
	//
	/*if (!CORETOOLS::Mouse::Create(&m_window)) {
		MESSAGE("> Mouse Creation failed!\n");
		return false;
	}
	m_pMouse = CORETOOLS::Mouse::GetInstance();*/

	return true;
}

bool EulerAdventure::InitContent() {

	m_pMenu = new SCENES::Menu(/*m_window.getSize()*/);
	assert(m_pMenu);

	m_pTuna = new SCENES::Tuna(/*&m_window*/);
	m_pTuna->StartInit();
	assert(m_pTuna);

	return true;
}

int EulerAdventure::Run() {

	ChangeGameState(MENU);

	while (m_gameState != EXIT && !m_application.PollEvent()) {

		Update();

		m_application.Draw();

		/*m_window.clear(sf::Color(250, 250, 250));
		Draw();
		m_window.display();*/
	}

	/*m_window.close();*/

	return 0;
}

void EulerAdventure::Update() {

	m_pRect->Update();
	m_pRect2->Update();
	/*static sf::Event event;*/

	//while (m_window.pollEvent(event)) {

	//	m_pMouse->Update(event);

	//	// EXIT BUTTON
	//	if (event.type == sf::Event::Closed) {
	//		ChangeGameState(EXIT);

	//	// KEY PRESSED
	//	} else if (event.type == sf::Event::KeyPressed) {

	//		// ESCAPE
	//		if (event.key.code == sf::Keyboard::Escape) {
	//			if (m_gameState == MENU) {
	//				ChangeGameState(INGAME);
	//			} else {
	//				ChangeGameState(MENU);
	//			}
	//		}
	//	}

	//	switch (m_gameState) {
	//	case INGAME:
	//		m_pTuna->Update(event);
	//		break;

	//	case MENU:
	//		m_pMenu->Update(event);
	//		break;
	//	}

	//}
}

void EulerAdventure::Draw() {
	/*switch (m_gameState) {
	case INGAME:
		m_pTuna->Draw();
		break;


	case MENU:
		m_pMenu->Draw(m_window);
		break;
	}*/
}

void EulerAdventure::ChangeGameState(GameState gs) {
	if (gs == m_gameState) return;
#ifdef _DEBUG
	printf("> Changed game state from %d to %d\n", m_gameState, gs);
#endif
	m_gameState = gs;
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