/////////////////////////////////////////////////////////////////////
// Filename: ecaDefs.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
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

enum LocationEnum {
	LOCATION_OFFICE,
	LOCATION_CORRIDOR_UP,
	LOCATION_COFFEE_ROOM,
	LOCATION_CONFERENCE_ROOM,
	LOCATION_CHAMBER,
	LOCATION_VENTILATION_ROOM,
	LOCATION_LADIES_TOILET_UP,
	LOCATION_GENTLEMENS_TOILET_UP,
	LOCATION_PRINCIPALS_ROOM,
	LOCATION_ELEVATOR,
	LOCATION_STAIRWELL,
	LOCATION_CORRIDOR_DOWN,
	LOCATION_LECTURE_HALL_1,
	LOCATION_LECTURE_HALL_2,
	LOCATION_LECTURE_HALL_3,
	LOCATION_LECTURE_HALL_4,
	LOCATION_LADIES_TOILET_DOWN,
	LOCATION_GENTLEMENS_TOILET_DOWN,
	LOCATION_LOCKER_ROOM,
	LOCATION_STORE_ROOM,
	LOCATION_ELEVATOR_SHAFT,

	LOCATION_NONE
};

enum ItemEnum {
	ITEM_NOTE_1,
	ITEM_NOTE_2,
	ITEM_NOTE_3,
	ITEM_NOTE_4,
	ITEM_CHAIR,
	ITEM_FIRE_AXE,
	ITEM_SKILL_BOOK,
	ITEM_PAPER,
	ITEM_COFFEE_MACHINE,
	ITEM_COFFEE_EXTINGUISHER_BOX,
	ITEM_COFFEE_EXTINGUISHER,
	ITEM_CUP_COFFEE,
	ITEM_GULLY,
	ITEM_VENTILATION_SHAFT,
	ITEM_SPATULA,
	ITEM_WILHELM,
	ITEM_CUPBOARDS,
	ITEM_DESK,
	ITEM_LOCKER,
	ITEM_SHINY_LOCKER,
	ITEM_TIMETABLE,

	ITEM_NONE
};

struct Description {
	// all set in GameManager::Init()
	char const* default;
	char const* explore;
	char const* alreadyExplored;
};

struct Item {
	// all set in GameManager::Init()
	ItemEnum		id;
	char const* name;
	char const* description;
	char const* interactDescription;
	bool				visible;
	bool				collected{ false };
};

struct Student {
	// all set in GameManager::Init()
	char const* name;
	char const* question;
	char const* answer;
	char const* hint;
	bool				defeated{ false };
};

struct Location {
	//all set in GameManager::Init()
	LocationEnum							id					{ LocationEnum::LOCATION_NONE };
	std::vector<Item*>				items				{ nullptr };	// may still be nullptr after GameManager:Init()
	std::vector<LocationEnum> exits				{};						// may still be empty after GameManager::Init()
	std::vector<Student*>			students		{ nullptr };	// may still be nullptr after GameManager::Init()
	char const*								name				{ nullptr };
	Description*							description	{ nullptr };
	bool											visible			{ false };
	bool											explored		{ false };
};