#pragma once

//////////////
// INCLUDES //
//////////////
#include <vector>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf
{
	class String;
}

namespace CORETOOLS
{
	class AutoComplete
	{
	public:
		AutoComplete(/*Character*/) {}

		/**
		 * First string will be changed to the nearest identical string that was set
		 * during creation of this instance
		 *
		 * @param toBeCompleted		The string that the check will be against
		 * @param completioned		Nearest identical string found
		 *
		 * @return An integer indicating the amount of character changes between toBeCompleted and completioned
		 **/
		int Completion(sf::String const& toBeCompleted, sf::String& completioned);

	private:
		std::vector<const char*> m_availableCmds;
	};
}