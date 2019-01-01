#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "ITextHandler.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace CORETOOLS {
	class AutoComplete;
}

namespace ECA {

	enum LocationEnum {
		OFFICE,
		CORRIDOR_UP,
		COFFEE_ROOM,
		CONFERENCE_ROOM,
		CHAMBER,
		VENTILATION_ROOM,
		LADIES_TOILET_UP,
		GENTLEMENS_TOILET_UP,
		PRINCIPALS_ROOM,
		ELEVATOR,
		STAIRWELL,
		CORRIDOR_DOWN,
		LECTURE_HALL_1,
		LECTRUE_HALL_2,
		LECTRUE_HALL_3,
		LECTRUE_HALL_4,
		LADIES_TOILET_DOWN,
		GENTLEMENS_TOILET_DOWN,
		LOCKER_ROOM,
		STORE_ROOM,
		ELEVATOR_SHAFT
	};
	enum ItemEnum{
		NOTE1,
		NOTE2,
		NOTE3,
		NOTE4,
		CHAIR,
		FIRE_AXE,
		SKILL_BOOK,
		PAPER,
		COFFEE_MACHINE,
		COFFEE_EXTINGUISHER_BOX,
		COFFEE_EXTINGUISHER,
		CUP_COFFEE,
		GULLY,
		VENTILATION_SHAFT,
		SPATULA,
		WILHELM,
		CUPBOARDS,
		DESK,
		LOCKER,
		SHINY_LOCKER,
		TIMETABLE
	};

	class GameManager : public CORETOOLS::ITextHandler {
	public:
		GameManager(/*sf::RenderWindow**/);

		void Handle(char const* text) override;
		void init();

	private:
		
		struct Description {
			//all set in init()
			const char* default;
			const char* explore;
			const char* alreadyExplored;
		};

		struct Item {
			//all set in init()
			const char* name;
			ItemEnum id;
			const char* description;
			const char* interactDescription;
			bool visible;
			bool collected{ false };
		};

		struct Student {
			//all set in init()
			const char* name;
			bool defeated{ false };
			const char* question;
			const char* answer;
			const char* hint;
		};

		struct Location {
			//all set in init()
			const char* name; 
			LocationEnum id; 
			bool explored{ false };
			bool visible; 
			Description* description;
			std::vector<Item*> items{ nullptr }; //may still be nullptr after init()
			std::vector<LocationEnum> exits; //may still be empty after init()
			std::vector<Student*> students{ nullptr }; //may still be nullptr after init()
		};


		std::map<LocationEnum, Location*> locations; //set in init()
	};
}