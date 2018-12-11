#include "Tuna.h"

#include <SFML/Graphics.hpp>
#include <iostream>

bool Tuna::InitSystems()
{
	m_window.create(sf::VideoMode(m_width, m_height), "EulerAdventure");

	if (!m_arialFont.loadFromFile("assets/fonts/arial.ttf")) return false;

	// Input box
	m_inputBox.SetFont(m_arialFont);
	m_inputBox.SetFillColor(sf::Color::White);
	m_inputBox.AddHandler(m_inputHandler);

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

		m_window.clear(sf::Color(3, 3, 3));

		m_inputBox.Draw(m_window);

		m_window.display();
	}

	return 0;
}

void Tuna::SetStyleRelative(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;

	m_inputBox.SetBounds(5.0f, m_height - 45.0f, 250, 22);
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