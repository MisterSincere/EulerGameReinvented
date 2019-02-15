/////////////////////////////////////////////////////////////////////
// Filename: GameManager.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include <map>
#include <coretools/IHandler.h>

#include "ecaDefs.h"

//////////////////////////
// FORWARD DECLARATIONS //
//////////////////////////
class EulerAdventure;


namespace ECA
{
	class GameManager : public ::CORETOOLS::ITextHandler
	{
	private:
		struct Description {
			//all set in Init()
			const char* default;
			const char* explore;
			const char* alreadyExplored;
		};

		struct Item {
			//all set in Init()
			const char* name;
			ItemEnum id;
			const char* description;
			const char* interactDescription;
			bool visible;
			bool collected{ false };
		};

		struct Student {
			//all set in Init()
			const char* name;
			bool defeated{ false };
			const char* question;
			const char* answer;
			const char* hint;
		};

		struct Location {
			//all set in Init()
			const char* name;
			LocationEnum id;
			bool explored{ false };
			bool visible;
			Description* description;
			std::vector<Item*> items{ nullptr }; //may still be nullptr after Init()
			std::vector<LocationEnum> exits; //may still be empty after Init()
			std::vector<Student*> students{ nullptr }; //may still be nullptr after Init()
		};

	public:
		GameManager(EulerAdventure* pAdv);

		bool Handle(wchar_t const* text) override;
		void Init();

	private:
		EulerAdventure* m_pAdv;

		std::map<LocationEnum, Location*> m_locations; //set in Init()
	};
}