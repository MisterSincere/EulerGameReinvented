#pragma once

//////////////
// INCLUDES //
//////////////
#include <cstdio>
#include <string>

#include <eedefs.h>

#ifdef _DEBUG
# define MESSAGE(msg, ...) printf(msg, __VA_ARGS__);
#else
# define MESSAGE(msg, ...)
#endif

// std string wrap for the assets path
#define ECA_ASSETS_DIR(path) (std::string(ASSETS_PATH) + path)

#define RELEASEP(x) if(x) {delete x; x = nullptr;}


enum GameState {
	RUNNING,
	INITIALIZING,
	INGAME,
	MENU,
	EXIT,
};