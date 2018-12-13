#pragma once

//////////////
// INCLUDES //
//////////////
#include <map>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf
{
	class String;
}

namespace CORETOOLS
{
	///////////////////////////
	// FOREWARD DECLARATIONS //
	///////////////////////////
	struct CmdList;

	class AutoComplete
	{
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
		 **/
		int Complete(sf::String const& toBeCompleted, sf::String& completioned);

		std::vector<Cmd> MultiComplete(sf::String const& toBeCompleted);

	private:
		void GetEquals(char const* string1, char const* string2, int& attachedEquals);

	private:
		CmdList const& m_availableCmds;
	};
}