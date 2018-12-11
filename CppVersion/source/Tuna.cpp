#include "Tuna.h"


bool Tuna::InitSystems()
{
	m_window.create(sf::VideoMode(800u, 600u), "EulerAdventure");

	return true;
}

bool Tuna::InitContent()
{

	return true;
}

int Tuna::Run()
{
	sf::Event event;

	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_window.close();
		}
	}

	return 0;
}