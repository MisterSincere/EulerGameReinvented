#pragma once

//////////////
// INCLUDES //
//////////////
#include <cstdio>

#ifdef _DEBUG
# define MESSAGE(msg, ___VA_ARGS___) printf(msg, ...);
#else
# define MESSAGE(msg, ___VA_ARGS___)
#endif


#define RELEASEP(x) if(x) {delete x; x = nullptr;}

enum ScreenMode {
	FULLSCREEN,
	FAKE_FULLSCREEN,
	WINDOWED
};

enum GameState {
	RUNNING,
	INITIALIZING,
	INGAME,
	MENU,
	EXIT,
};

struct Settings {
	ScreenMode		screenMode			{ WINDOWED };
	sf::Vector2u	clientSize			{ 200u, 200u };
	unsigned int	antialisingCount{ 1u };
	unsigned int	frameLimit			{ 60u };
	bool					vsyncEnabled		{ false };
	char const*		title						{ "Hallo" };
};