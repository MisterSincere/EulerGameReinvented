#include "Options.h"

//////////////
// INCLUDES //
//////////////
#include <assert.h>
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "Box.h"

CORETOOLS::Options::Options() {
	m_pBackground = new GFX::Box({ 0u, 0u }, { 0.0f, 0.0f });
	m_pBackground->SetBackgroundColor(sf::Color(50, 50, 120));
}

CORETOOLS::Options::~Options() {
	if (m_pBackground) {
		delete m_pBackground;
		m_pBackground = nullptr;
	}
}

bool CORETOOLS::Options::Init(Settings* pSet) {
	// Store settings
	m_pSettings = pSet;

	m_pBackground->SetSize(float(pSet->clientSize.x), float(pSet->clientSize.y));

	return true;
}




void CORETOOLS::Options::Update(sf::Event const & evt, sf::RenderWindow* pWindow) {
	// Do nothing?
}

void CORETOOLS::Options::Draw(sf::RenderWindow & rw) {
	if(m_pBackground) m_pBackground->Draw(rw);
}
