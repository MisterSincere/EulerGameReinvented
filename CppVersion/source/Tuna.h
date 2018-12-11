#pragma once

#include <SFML/Window.hpp>

class Tuna
{
public:
	bool Init() { return (m_isInitialized = InitSystems() | InitContent()); }

	int Run();

private:
	bool InitSystems();
	bool InitContent();

private:
	sf::Window m_window;

	bool m_isInitialized{ false };
};