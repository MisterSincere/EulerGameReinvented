#include "AutoComplete.h"

//////////////
// INCLUDES //
//////////////
#include <SFML/System/String.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "TextInputHandler.h"


CORETOOLS::AutoComplete::AutoComplete(CmdList const& cmds)
	: m_availableCmds(cmds)
{
	// Do sth!
}

int CORETOOLS::AutoComplete::Complete(sf::String const& toBeCompleted, sf::String& completed)
{
	// Variables to store the result after all iterations
	int maxAttachedEqual{ 0 };
	sf::String completedString{ toBeCompleted };

	int curAttachedEqual;
	for (auto currCmd : m_availableCmds) {
		GetEquals(currCmd.get(), toBeCompleted.toAnsiString().c_str(), curAttachedEqual);

		// Attached result check
		if (curAttachedEqual > maxAttachedEqual
			&& strcmp(currCmd.get(), toBeCompleted.toAnsiString().c_str())) {
			completedString = sf::String(currCmd.get());
			maxAttachedEqual = curAttachedEqual;
		}
	}

	// Change refernce to nearest string
	completed = completedString;

	return maxAttachedEqual;
}

std::vector<CORETOOLS::Cmd> CORETOOLS::AutoComplete::MultiComplete(sf::String const& toBeCompleted)
{
	std::map<unsigned int, CORETOOLS::CmdList> cmdEqualityMap;

	for (auto currCmd : m_availableCmds)
	{

	}
}

void CORETOOLS::AutoComplete::GetEquals(char const* string1, char const* string2, int& attachedEquals)
{
	int equals{ 0 };
	for (size_t i = 0; i < strlen(string1) || i < strlen(string2); i++)
	{
		if (string1[i] == string2[i]) equals++;
		else break;
	}

	// Store in reference
	attachedEquals = equals;
}