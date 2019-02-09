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
		m_pRect->EnableHover({ 0.0f, 0.5f, 0.0f, 1.0f });
		m_pRect->EnableActive({ 0.0f, 0.3f, 0.0f, 1.0f });

		m_pRect2 = new GFX::EERectangle(&m_application);
		m_pRect2->SetPosition({ 100.0f, 100.0f });
		m_pRect2->SetSize({ 200u, 200u });
		m_pRect2->SetBackgroundColor({ 1.0f, 0.0f, 0.0f, .5f });

		m_pFontEngine = new GFX::EEFontEngine(&m_application);
		std::string arialFile = ECA_ASSETS_DIR("fonts/SquareFont.ttf");
		m_font = m_pFontEngine->CreateFont(arialFile.c_str());

		m_text = m_pFontEngine->RenderText(m_font, "hallo again\nI am in a new line", { 80.0f, 70.0f }, 35.0f, { 0.0, 0.0f, 0.9f, .5f });
		m_text2 = m_pFontEngine->RenderText(m_font, "ich bin eine zweite test font", { 50.0f, 410.0f }, 30.0f, { 0.9f, .9f, .9f, 1.0f });
		
		m_pTextBox = new GFX::EETextBox(m_pFontEngine, "ich bin in einer box und wrapped!", m_font);
		m_pTextBox->SetPadding(10.0f, 10.0f, 10.0f, 10.0f);
		m_pTextBox->SetPosition({ 400.0f, 250.0f });
		m_pTextBox->SetSize({ 300u, 100u });
		m_pTextBox->SetBackgroundColor({ .1f, .1f, .1f, 1.f });
	}

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

		m_application.Draw({ 0.8f, 0.3f, 0.5f, 1.0f });
	}

	return 0;
}

void EulerAdventure::Update() {

	m_pRect->Update();
	m_pRect2->Update();
	m_pTextBox->Update();
	m_pFontEngine->Update();
	
	if (m_application.KeyHit(EE_KEY_ESCAPE)) {
		ChangeGameState(EXIT);
	}
	if (m_application.KeyHit(EE_KEY_F1)) {
		m_pFontEngine->ChangeText(m_text2, "hello!!");
	}
	if (m_application.KeyHit(EE_KEY_F2)) {
		m_pFontEngine->ChangeText(m_text2, "");
	}
	if (m_application.KeyHit(EE_KEY_F3)) {
		m_pFontEngine->ReleaseText(m_text);
	}

	static bool visible = false;
	if (m_application.KeyHit(EE_KEY_F4)) {
		m_pRect->SetVisibility(visible);
		visible = !visible;
	}

	if (m_application.KeyHit(EE_KEY_F5)) {
		m_pTextBox->SetText("ich bin der neue string in der box!");
	}
	if (m_application.KeyHit(EE_KEY_F6)) {
		m_pTextBox->SetText("");
	}


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