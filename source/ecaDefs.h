#pragma once

//////////////
// INCLUDES //
//////////////
#include <cstdio>
#include <string>

#ifdef _DEBUG
# define MESSAGE(msg, ...) printf(msg, __VA_ARGS__);
#else
# define MESSAGE(msg, ...)
#endif

// std string wrap for the assets path
#define ECA_ASSETS_DIR(path) (std::string(ASSETS_PATH) + path)

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
	/*sf::Vector2u	clientSize			{ 200u, 200u };*/
	unsigned int	antialisingCount{ 1u };
	unsigned int	frameLimit			{ 60u };
	bool					vsyncEnabled		{ false };
	char const*		title						{ "Hallo" };
};