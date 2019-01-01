#pragma once

//////////////
// INCLUDES //
//////////////
#include <map>
#include <vector>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
//namespace sf {
//	class String;
//}

namespace CORETOOLS {
	///////////////////////////
	// FOREWARD DECLARATIONS //
	///////////////////////////
	struct CmdList;
	struct Cmd;

	class AutoComplete {
	public:
		AutoComplete(CmdList const&);

		/**
		 * First string will be changed to the nearest identical string that was set
		 * during creation of this instance
		 *
		 * @param toBeCompleted		The string that the check will be against
		 * @param completioned		Nearest identical string found
		 *
		 * @return An integer indicating the amount of equal characters
		 *
		 * @Deprectated Use MultiComplete
		 **/
		int Complete(/*sf::String const& toBeCompleted, sf::String& completioned*/);

		/**
		 * Returns a list of commands that equal at least like desired the toBeCompleted string
		 * First elements have most same chars and the last elements the least
		 *
		 * @param toBeCompleted		The string that is to be compared
		 * @param minimum					Number indicating the amount of characters that need to be at least the same
		 *
		 * @return Vector of commands that are fullfilling the above criteria sorted by amount most characters
		 **/
		std::vector<Cmd> MultiComplete(/*sf::String const& toBeCompleted, */unsigned int minimum = 1u);

	private:
		/**
		 * Returns the amount of same character until the first different character
		 **/
		unsigned int GetEquals(char const* string1, char const* string2);

	private:
		CmdList const& m_availableCmds;
	};
}