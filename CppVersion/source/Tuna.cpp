#include "Tuna.h"

#include <SFML/Graphics.hpp>
#include <iostream>

bool Tuna::InitSystems()
{
	m_window.create(sf::VideoMode(m_width, m_height), "EulerAdventure");
	m_window.setFramerateLimit(60);

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
	m_inputBox.SetCharacterSize(22.0f);
	m_inputBox.AddHandler(m_pInputHandler);
	m_inputBox.SetAutoCompleter(m_pInputHandler->AcquireAutoComplete());

	// Adjust positions and sizes
	SetStyleRelative(m_width, m_height);

	return true;
}

bool Tuna::InitContent()
{

	return true;
}

int Tuna::Run()
{
	while (m_window.isOpen())
	{
		ProcessInput();

		m_window.clear(sf::Color(250, 250, 250));

		m_outputBox.Draw(m_window);
		m_inputBox.Draw(m_window);

		m_window.display();
	}

	return 0;
}

void Tuna::SetStyleRelative(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;

	m_outputBox.SetBounds(5.0f, 5.0f, width - 10.0f, height - 77.0f);
	m_inputBox.SetBounds(5.0f, m_height - 50.0f, 250, 22);
}

void Tuna::ProcessInput()
{
	static sf::Event event;


	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) m_window.close();
		}

		m_inputBox.Update(event);

	}
}