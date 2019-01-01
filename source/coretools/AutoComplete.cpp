#include "AutoComplete.h"

//////////////
// INCLUDES //
////////////////
//#include <SFML/System/String.hpp>

/////////////////
// MY INCLUDES //
/////////////////
#include "GameManager.h"


CORETOOLS::AutoComplete::AutoComplete(CmdList const& cmds)
	: m_availableCmds(cmds)
{
	// Do sth!
}

int CORETOOLS::AutoComplete::Complete(/*sf::String const& toBeCompleted, sf::String& completed*/) {
	// Variables to store the result after all iterations
	unsigned int maxAttachedEqual{ 0u };
	//sf::String completedString{ toBeCompleted };

	//unsigned int curAttachedEqual;
	//for (auto curCmd : m_availableCmds) {
	//	curAttachedEqual = GetEquals(curCmd.get(), toBeCompleted.toAnsiString().c_str());

	//	// Attached result check
	//	if (curAttachedEqual > maxAttachedEqual
	//		&& strcmp(curCmd.get(), toBeCompleted.toAnsiString().c_str())) {
	//		completedString = sf::String(curCmd.get());
	//		maxAttachedEqual = curAttachedEqual;
	//	}
	//}

	//// Change refernce to nearest string
	//completed = completedString;

	return maxAttachedEqual;
}

struct greater {
	template<class T>
	bool operator()(T const &a, T const &b) const { return a > b; }
};

std::vector<CORETOOLS::Cmd> CORETOOLS::AutoComplete::MultiComplete(/*sf::String const& toBeCompleted, */unsigned int minimum) {
	std::vector<Cmd> equalityMap;

	//for (CORETOOLS::Cmd curCmd : m_availableCmds) {
	//	curCmd.p_equals = GetEquals(curCmd.get(), toBeCompleted.toAnsiString().c_str());

	//	// At least one must be the same
	//	if (curCmd.p_equals >= minimum) equalityMap.push_back(curCmd);
	//}

	//// Sort the map in descending order
	//std::sort(equalityMap.begin(), equalityMap.end(), greater());

	return equalityMap;
}

unsigned int CORETOOLS::AutoComplete::GetEquals(char const* string1, char const* string2) {
	unsigned int equals{ 0u };
	for (size_t i = 0; i < strlen(string1) || i < strlen(string2); i++) {
		if (string1[i] == string2[i]) equals++;
		else break;
	}
	return equals;
}