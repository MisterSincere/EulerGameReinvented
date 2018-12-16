#include "Tuna.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "ecaDefs.h"


SCENES::Tuna::Tuna(sf::RenderWindow* rw)
	: m_pWindow(rw)
{
}


SCENES::Tuna::~Tuna() {
	RELEASEP(m_pOutputBox);
	RELEASEP(m_pInputBox);
	RELEASEP(m_pGameManager);
}



bool SCENES::Tuna::StartInit()
{
	// Fonts
	if (!m_arialFont.loadFromFile("assets/fonts/arial.ttf")) return false;
	if (!m_squareFont.loadFromFile("assets/fonts/SquareFont.ttf")) return false;

	// Output box
	m_pOutputBox = new GFX::TextBox;
	m_pOutputBox->SetFont(m_arialFont);
	m_pOutputBox->SetPadding(3.0f, 3.0f);
	m_pOutputBox->SetTextColor(sf::Color(255, 255, 255));
	m_pOutputBox->SetBackgroundColor(sf::Color(64, 64, 64));
	m_pOutputBox->SetCharacterSize(18);
	m_pOutputBox->SetString("Sehr geehrter Herr Euler,\nes ist 8 Uhr morgens und du stehst in deinem Büro der Universität(Lehrer Etage).In deinem Büro ist mittig ein überfüllter Schreibtisch[desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500€ steht[chair].Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes. Von hier aus kannst du in den Korridor[corridor] gehen.Generell gilt : Um woanders hinzugehen gibst du ein : go <Raum>.Für <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English.");

	// Input box
	m_pInputBox = new GFX::InputBox;
	m_pInputBox->SetFont(m_arialFont);
	m_pInputBox->SetTextColor(sf::Color::Black);
	m_pInputBox->SetCharacterSize(22u);
	m_pInputBox->AddHandler(m_pGameManager);
	m_pInputBox->SetAutoCompleter(m_pGameManager->AcquireAutoComplete());

	// Adjust positions and sizes
	SetStyleRelative(m_pWindow->getSize());

	return true;
}

void SCENES::Tuna::Update(sf::Event const& event) {
	m_pOutputBox->Update(event);
	m_pInputBox->Update(event);
}

void SCENES::Tuna::Draw() {
	m_pOutputBox->Draw(*m_pWindow);
	m_pInputBox->Draw(*m_pWindow);
}

void SCENES::Tuna::SetStyleRelative(sf::Vector2u const& newSize) {
	m_pOutputBox->SetBounds(5.0f, 5.0f, newSize.x - 10.0f, newSize.y - 77.0f);
	m_pInputBox->SetBounds(5.0f, newSize.y - 50.0f, 250, 22);
}
