#include "GameManager.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/Graphics/RenderWindow.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "EulerAdventure.h"


ECA::GameManager::GameManager(sf::RenderWindow* pWindow)
	: ITextHandler(pWindow)
{
	i_commands += "exit";
	i_commands += "explore";
	i_commands += "examine";
	i_commands += "examine inv";
	i_commands += "interact";
	i_commands += "interact inv";
	i_commands += "go";
	i_commands += "load";
	i_commands += "save";
	i_commands += "back";
	i_commands += "inventar";
}

void ECA::GameManager::Handle(char const* text) {
	if (i_commands["exit"] == text) {
		EulerAdventure::ChangeGameState(EXIT);
	}
}