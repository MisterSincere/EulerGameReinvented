#include "Tuna.h"

//////////////
// INCLUDES //
//////////////
#include <EEApplication.h>
#include <gfx/EEInputBox.h>
#include <vkcore/vulkanTools.h>
#include <assert.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "EulerAdventure.h"
#include "GameManager.h"


SCENES::Tuna::Tuna(EulerAdventure* pAdv)
	: m_pAdv(pAdv)
{
	m_pFontEngine = pAdv->GetFontEngine();
	m_pApp = pAdv->GetApplication();
	assert(m_pFontEngine && m_pApp);

	// Create the game manager
	m_pGameManager = new ECA::GameManager(m_pAdv);
	m_pGameManager->Init();

	// Fonts
	std::string squareFile = ECA_ASSETS_DIR("fonts/SquareFont.ttf");
	m_square = m_pFontEngine->CreateFont(squareFile.c_str());
	std::string arialFile = ECA_ASSETS_DIR("fonts/arial.ttf");
	m_arial = m_pFontEngine->CreateFont(arialFile.c_str());

	// Title
	EERect32U windowExtent = m_pApp->GetWindowExtent();
	GFX::EETextBoxCreateInfo cinfo;
	cinfo.text						= L"Sehr geehrter Herr Euler,\nes ist 8 Uhr morgens und du stehst in deinem Büro der Universität(Lehrer Etage).In deinem Büro ist mittig ein überfüllter Schreibtisch[desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500€ steht[chair].Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes. Von hier aus kannst du in den Korridor[corridor] gehen.Generell gilt : Um woanders hinzugehen gibst du ein : go <Raum>.Für <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English.";
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
	inputCInfo.cmdList					= m_pGameManager->GetCommands();
	inputCInfo.prefix						= L"> ";
	inputCInfo.text							= L"";
	inputCInfo.characterSize		= 22.f;
	inputCInfo.font							= m_arial;
	inputCInfo.textColor				= { 0.f, 0.f, 0.f, 1.f };
	inputCInfo.adjustBoxSize		= false;
	inputCInfo.position					= { 5.f, windowExtent.height - 50.f };
	inputCInfo.size							= { 250.f, 22.f };
	inputCInfo.backgroundColor	= { 0.f, 0.f, 0.f, 0.f };
	inputCInfo.visibility				= false;
	m_pInputBox = new GFX::EEInputBox(m_pFontEngine, inputCInfo);

	m_pInputBox->AddHandler(m_pGameManager);
}

SCENES::Tuna::~Tuna() {
	RELEASE_S(m_pInputBox);
	RELEASE_S(m_pOutputBox);
	RELEASE_S(m_pGameManager);
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

	EE_INFO("[Tuna] Visibility set to %d\n", m_isVisible);
}

bool SCENES::Tuna::IsVisible()
{
	return m_isVisible;
}
