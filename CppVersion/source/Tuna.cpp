#include "Tuna.h"

#include <iostream>

bool Tuna::InitSystems()
{
	m_window.create(sf::VideoMode(800u, 600u), "EulerAdventure");

	if (!m_arialFont.loadFromFile("assets/fonts/arial.ttf")) return false;
	m_inputBox.setFont(m_arialFont);
	m_inputBox.setCharacterSize(24);
	m_inputBox.setFillColor(sf::Color::Red);

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

		m_window.draw(m_inputBox);

		m_window.display();
	}

	return 0;
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

		}

		m_inputBox.Update(event);

	}
}