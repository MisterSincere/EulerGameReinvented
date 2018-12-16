#include "EulerAdventure.h"

//////////////
// INCLUDES //
//////////////
#include <iostream>
#include <SFML/Window/Event.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "Tuna.h"
#include "Menu.h"

GameState EulerAdventure::m_gameState = RUNNING;

EulerAdventure::EulerAdventure() {
	m_settings.screenMode = WINDOWED;
	m_settings.frameLimit = 60u;
	m_settings.clientSize = { 1100u, 700u };
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
		int style = sf::Style::Default;
		if (m_settings.screenMode == FAKE_FULLSCREEN) {
			style = sf::Style::None;
			m_settings.clientSize = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };
		} else if (m_settings.screenMode == FULLSCREEN) {
			style = sf::Style::Fullscreen;
		}

		sf::ContextSettings settings;
		settings.antialiasingLevel = m_settings.antialisingCount;

		// Create window and set its settings
		m_window.create(sf::VideoMode(m_settings.clientSize.x, m_settings.clientSize.y), m_settings.title, style, settings);
		m_window.setFramerateLimit(m_settings.frameLimit);
		m_window.setVerticalSyncEnabled(m_settings.vsyncEnabled);

		// In fullscreen acquire now the client size
		m_settings.clientSize = m_window.getSize();
	}

	return true;
}

bool EulerAdventure::InitContent() {

	m_pMenu = new SCENES::Menu(m_window.getSize());
	assert(m_pMenu);

	m_pTuna = new SCENES::Tuna(&m_window);
	m_pTuna->StartInit();
	assert(m_pTuna);

	return true;
}

int EulerAdventure::Run() {

	ChangeGameState(MENU);

	while (m_gameState != EXIT) {

		Update();

		m_window.clear(sf::Color(250, 250, 250));
		Draw();
		m_window.display();
	}

	m_window.close();

	return 0;
}

void EulerAdventure::Update() {
	static sf::Event event;

	while (m_window.pollEvent(event)) {

		// EXIT BUTTON
		if (event.type == sf::Event::Closed) {
			ChangeGameState(EXIT);

		// KEY PRESSED
		} else if (event.type == sf::Event::KeyPressed) {

			// ESCAPE
			if (event.key.code == sf::Keyboard::Escape) {
				if (m_gameState == MENU) {
					ChangeGameState(INGAME);
				} else {
					ChangeGameState(MENU);
				}
			}
		}

		switch (m_gameState) {
		case INGAME:
			m_pTuna->Update(event);
			break;

		case MENU:
			m_pMenu->Update(event);
			break;
		}

	}
}

void EulerAdventure::Draw() {
	switch (m_gameState) {
	case INGAME:
		m_pTuna->Draw();
		break;


	case MENU:
		m_pMenu->Draw(m_window);
		break;
	}
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