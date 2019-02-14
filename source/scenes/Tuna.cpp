#include "Tuna.h"

//////////////
// INCLUDES //
//////////////
#include <EEApplication.h>
#include <gfx/EEInputBox.h>
#include <assert.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "EulerAdventure.h"


SCENES::Tuna::Tuna(GFX::EEFontEngine* pFontEngine)
	: m_pFontEngine(pFontEngine)
{
	assert(m_pFontEngine);

	// Store application
	m_pApp = m_pFontEngine->GetApplication();

	// Fonts
	std::string squareFile = ECA_ASSETS_DIR("fonts/SquareFont.ttf");
	m_square = m_pFontEngine->CreateFont(squareFile.c_str());
	std::string arialFile = ECA_ASSETS_DIR("fonts/arial.ttf");
	m_arial = m_pFontEngine->CreateFont(arialFile.c_str());

	// Title
	EERect32U windowExtent = m_pApp->GetWindowExtent();
	GFX::EETextBoxCreateInfo cinfo;
	cinfo.text						= "Sehr geehrter Herr Euler,\nes ist 8 Uhr morgens und du stehst in deinem B�ro der Universit�t(Lehrer Etage).In deinem B�ro ist mittig ein �berf�llter Schreibtisch[desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500� steht[chair].Au�erdem stehen zwei Schr�nke in jeweils einer Ecke des Raumes. Von hier aus kannst du in den Korridor[corridor] gehen.Generell gilt : Um woanders hinzugehen gibst du ein : go <Raum>.F�r <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English.";
	cinfo.characterSize		= 18.f;
	cinfo.font						= m_arial;
	cinfo.textColor				= { 1.f, 1.f, 1.f, 1.f };
	cinfo.padding					= {3.f, 3.f, 3.f, 3.f};
	cinfo.adjustBoxSize		= false;
	cinfo.position				= { 5.f, 5.f };
	cinfo.size						= { windowExtent.width - 10.f, windowExtent.height - 77.f };
	cinfo.backgroundColor = { 64 / 255.f, 64 / 255.f, 64 / 255.f, 1.f };
	cinfo.visibility			= false;
	m_pOutputBox = new GFX::EETextBox(m_pFontEngine, cinfo);

	GFX::EEInputBoxCreateInfo inputCInfo;
	inputCInfo.prefix						= "> ";
	inputCInfo.text							= "";
	inputCInfo.characterSize		= 22.f;
	inputCInfo.font							= m_arial;
	inputCInfo.textColor				= { 0.f, 0.f, 0.f, 1.f };
	inputCInfo.adjustBoxSize		= false;
	inputCInfo.position					= { 5.f, windowExtent.height - 50.f };
	inputCInfo.size							= { 250.f, 22.f };
	inputCInfo.backgroundColor	= { 0.f, 0.f, 0.f, 0.f };
	inputCInfo.visibility				= false;
	m_pInputBox = new GFX::EEInputBox(m_pFontEngine, inputCInfo);

	::CORETOOLS::CmdList i_commands;
	i_commands += "exit";
	i_commands += "explore";
	i_commands += "examine";
	i_commands += "examine inv";
	i_commands += "interact";
	i_commands += "interact inv";
	i_commands += "go";
	i_commands += "load";
	i_commands += "save";
	i_commands += "back";
	i_commands += "inventar";
	m_pInputBox->SetCommandList(i_commands);
}

SCENES::Tuna::~Tuna() {

}

void SCENES::Tuna::Update(EulerAdventure* pAdv) {
	m_pOutputBox->Update();
	m_pInputBox->Update();
}

void SCENES::Tuna::Draw() {
	m_pApp->Draw({ .9f, .9f, .9f, 1.f });
}

void SCENES::Tuna::SetVisibility(bool isVisible)
{
	if (m_isVisible == isVisible) return;
	m_isVisible = isVisible;

	m_pOutputBox->SetVisibility(m_isVisible);
	m_pInputBox->SetVisibility(m_isVisible);

	EE_PRINT("[Tuna] Visibility set to %d\n", m_isVisible);
}

bool SCENES::Tuna::IsVisible()
{
	return m_isVisible;
}
