#include "Tuna.h"

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
	cinfo.text = "Sehr geehrter Herr Euler,\nes ist 8 Uhr morgens und du stehst in deinem Büro der Universität(Lehrer Etage).In deinem Büro ist mittig ein überfüllter Schreibtisch[desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500€ steht[chair].Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes. Von hier aus kannst du in den Korridor[corridor] gehen.Generell gilt : Um woanders hinzugehen gibst du ein : go <Raum>.Für <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English.";
	cinfo.characterSize = 18.f;
	cinfo.font = m_arial;
	cinfo.textColor = { 1.f, 1.f, 1.f,1.f };
	cinfo.padding = {3.0f, 3.0f, 3.0f, 3.0f};
	cinfo.adjustBoxSize = false;
	cinfo.boxInfo.position = { 5.0f, 5.0f };
	cinfo.boxInfo.size = {windowExtent.width - 10.0f, windowExtent.height - 77.0f};
	cinfo.boxInfo.backgroundColor = { 64 / 255.f, 64 / 255.f, 64 / 255.f, 1.f };
	cinfo.boxInfo.visibility = false;
	m_pTestBox = new GFX::EETextBox(m_pFontEngine, cinfo);
}

SCENES::Tuna::~Tuna() {

}

void SCENES::Tuna::Update(EulerAdventure* pAdv) {
	m_pTestBox->Update();
}

void SCENES::Tuna::Draw() {
	m_pApp->Draw({ .9f, .9f, .9f, 1.f });
}

void SCENES::Tuna::SetVisibility(bool isVisible)
{
	if (m_isVisible == isVisible) return;
	m_isVisible = isVisible;

	m_pTestBox->SetVisibility(m_isVisible);

	EE_PRINT("[Tuna] Visibility set to %d\n", m_isVisible);
}

bool SCENES::Tuna::IsVisible()
{
	return m_isVisible;
}
