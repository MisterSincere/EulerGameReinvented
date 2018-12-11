#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "Window.h"

class MainLoop
{
public:
	MainLoop();
	~MainLoop();

	bool Init() { return (m_isInitialized = InitSystems() | InitContent()); }

	int Run();

private:
	bool InitSystems();
	bool InitContent();

private:
	GFX::Window* m_pWindow{ nullptr };

	bool m_isInitialized{ false };
};