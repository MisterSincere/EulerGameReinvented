#include "Menu.h"

//////////////
// INCLUDES //
//////////////
#include <EEApplication.h>
#include <gfx/EETextBox.h>
#include <assert.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "EulerAdventure.h"


SCENES::Menu::Menu(GFX::EEFontEngine* pFontEngine)
	: m_pFontEngine(pFontEngine)
{
	assert(m_pFontEngine);

	// Store application
	m_pApp = m_pFontEngine->GetApplication();

	// Fonts
	std::string fontFile = ECA_ASSETS_DIR("fonts/SquareFont.ttf");
	m_font = m_pFontEngine->CreateFont(fontFile.c_str());

	EERect32U windowExtent = m_pApp->GetWindowExtent();

	// Title
	GFX::EETextBoxCreateInfo cinfo;
	cinfo.font						= m_font;
	cinfo.text						= "Euler Coffee Adventure";
	cinfo.characterSize		= 50.f;
	cinfo.position				= { 0.f, 30.f };
	cinfo.positionFlags		= GFX::HORIZONTAL;
	cinfo.visibility			= false;
	cinfo.backgroundColor = { 0.f, 0.f, 0.f, 0.f };
	m_pTitle = new GFX::EETextBox(m_pFontEngine, cinfo);

	// Start
	cinfo.text						= "Lets get so cool xoxo";
	cinfo.characterSize		= 29.f;
	cinfo.padding					= { 10.f, 10.f, 10.f, 10.f };
	cinfo.position				= { 0.f, 200.f };
	cinfo.positionFlags		= GFX::HORIZONTAL;
	cinfo.visibility			= false;
	cinfo.backgroundColor = { 40/255.f, 40/255.0f, 60/255.0f, 1.f };
	cinfo.enableHover			= true;
	cinfo.hoverColor			= { 0.f, 0.f, 0.f, 1.f };
	m_pStartButton = new GFX::EETextBox(m_pFontEngine, cinfo);

	// EXIT
	cinfo.text						= "Fck this shit, im out";
	cinfo.characterSize		= 29.f;
	cinfo.padding					= { 10.f, 10.f, 10.f, 10.f };
	cinfo.position				= { 0.f, windowExtent.height - 150.0f };
	cinfo.positionFlags		= GFX::HORIZONTAL;
	cinfo.visibility			= false;
	cinfo.backgroundColor = { 40 / 255.f, 40 / 255.0f, 60 / 255.0f, 1.f };
	cinfo.enableHover			= true;
	cinfo.hoverColor			= { 0.f, 0.f, 0.f, 1.f };
	m_pExitButton = new GFX::EETextBox(m_pFontEngine, cinfo);
}

SCENES::Menu::~Menu() {
	
}

void SCENES::Menu::Update(EulerAdventure* pAdv) {
	if (m_pExitButton->Clicked(EE_MOUSE_BUTTON_LEFT)) {
		pAdv->ChangeGameState(EXIT);

	} else if (m_pStartButton->Clicked(EE_MOUSE_BUTTON_LEFT)) {
		pAdv->ChangeGameState(INGAME);
	}

	m_pTitle->Update();
	m_pExitButton->Update();
	m_pStartButton->Update();
}

void SCENES::Menu::Draw() {
	m_pApp->Draw({ 70/255.f, 70/255.f, 90/255.f, 1.f });
}

void SCENES::Menu::SetVisibility(bool isVisible)
{
	if (m_isVisible == isVisible) return;
	m_isVisible = isVisible;

	m_pTitle->SetVisibility(m_isVisible);
	m_pExitButton->SetVisibility(m_isVisible);
	m_pStartButton->SetVisibility(m_isVisible);

	EE_PRINT("[MENU] Visibility set to %d\n", m_isVisible);
}

bool SCENES::Menu::IsVisible()
{
	return m_isVisible;
}
