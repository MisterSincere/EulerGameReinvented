#include "MainLoop.h"

/////////////////
// MY INCLUDES //
/////////////////
#include "Window.h"

MainLoop::MainLoop()
{
	// Do nothing?
}

MainLoop::~MainLoop()
{
	if (m_pWindow) {
		delete m_pWindow;
		m_pWindow = nullptr;
	}
}

bool MainLoop::InitSystems()
{
	Utils::WindowCreateInfo cinfo;

	m_pWindow = new GFX::Window(cinfo);

	return true;
}

bool MainLoop::InitContent()
{

	return true;
}

int MainLoop::Run()
{
	sf::Event event;

	while (m_pWindow->isOpen())
	{
		while (m_pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_pWindow->close();
		}
	}

	return 0;
}