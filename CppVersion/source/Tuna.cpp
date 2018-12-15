#include "Tuna.h"

#include <SFML/Graphics.hpp>
#include <iostream>


Tuna::Tuna() {
	m_settings.screenMode = CORETOOLS::WINDOWED;
	m_settings.frameLimit = 60u;
	m_settings.clientSize = { 1100u, 700u };

	m_pOptions = new CORETOOLS::Options;
	m_pOptions->Init(&m_settings);
}

bool Tuna::Init() {
	m_gameState = INITIALIZING;
	if (!InitSystems()) return false;
	if (!InitContent()) return false;

	m_gameState = INGAME;
	return true;
}

bool Tuna::InitSystems() {

	
	int style = sf::Style::Default;
	// Fullscreen or fake fullscreen will both have the window size
	if (m_settings.screenMode == CORETOOLS::FULLSCREEN || m_settings.screenMode == CORETOOLS::FAKE_FULLSCREEN) {
		style = m_settings.screenMode == CORETOOLS::FULLSCREEN ? sf::Style::Fullscreen : sf::Style::None;
		m_settings.clientSize = { sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };
	}

	m_window.create(sf::VideoMode(m_settings.clientSize.x, m_settings.clientSize.y), m_settings.title, style);
	m_window.setFramerateLimit(m_settings.frameLimit);

	// Load fonts
	if (!m_arialFont.loadFromFile("assets/fonts/arial.ttf")) return false;
	if (!m_squareFont.loadFromFile("assets/fonts/SquareFont.ttf")) return false;

	// Output box
	m_outputBox.SetFont(m_arialFont);
	m_outputBox.SetPadding(3.0f, 3.0f);
	m_outputBox.SetTextColor(sf::Color(255, 255, 255));
	m_outputBox.SetBackgroundColor(sf::Color(64, 64, 64));
	m_outputBox.SetCharacterSize(18);
	m_outputBox.SetString("Sehr geehrter Herr Euler,\nes ist 8 Uhr morgens und du stehst in deinem Büro der Universität(Lehrer Etage).In deinem Büro ist mittig ein überfüllter Schreibtisch[desk] an dem ein Scott Chefsessel aus original Kunstleder im Wert von 500€ steht[chair].Außerdem stehen zwei Schränke in jeweils einer Ecke des Raumes. Von hier aus kannst du in den Korridor[corridor] gehen.Generell gilt : Um woanders hinzugehen gibst du ein : go <Raum>.Für <Raum> setzt du den englischen Namen deines Ziels ein, because you need to learn English.");

	// Input box
	m_inputBox.SetFont(m_arialFont);
	m_inputBox.SetTextColor(sf::Color::Black);
	m_inputBox.SetCharacterSize(22u);
	m_inputBox.AddHandler(m_pInputHandler);
	m_inputBox.SetAutoCompleter(m_pInputHandler->AcquireAutoComplete());

	// Adjust positions and sizes
	SetStyleRelative(m_settings.clientSize);

	return true;
}

bool Tuna::InitContent()
{

	return true;
}

int Tuna::Run()
{
	while (m_window.isOpen() && m_gameState != EXIT) {

		Update();

		m_window.clear(sf::Color(250, 250, 250));
		Draw();
		m_window.display();
	}

	return 0;
}

void Tuna::Update() {
	static sf::Event event;

	while (m_window.pollEvent(event)) {

		// EXIT BUTTON
		if (event.type == sf::Event::Closed) {
			m_window.close();

		// ESCAPE
		} else if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) m_window.close();

			if (event.key.code == sf::Keyboard::F1) {
				m_gameState = (m_gameState == OPTIONS) ? INGAME : OPTIONS;
			}
		}

		switch (m_gameState) {
			case INGAME:
				m_outputBox.Update(event);
				m_inputBox.Update(event);
				break;

			case OPTIONS:
				m_pOptions->Update(event, &m_window);
				break;
		}

	}
}

void Tuna::Draw() {
	switch (m_gameState) {
		case INGAME:
			m_outputBox.Draw(m_window);
			m_inputBox.Draw(m_window);
			break;

		case OPTIONS:
			m_pOptions->Draw(m_window);
			break;
	}
}

void Tuna::SetStyleRelative(sf::Vector2u const& newSize) {
	m_settings.clientSize = newSize;

	m_outputBox.SetBounds(5.0f, 5.0f, newSize.x - 10.0f, newSize.y - 77.0f);
	m_inputBox.SetBounds(5.0f, newSize.y - 50.0f, 250, 22);
}
