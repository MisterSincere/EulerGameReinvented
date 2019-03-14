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
#include <vector>

#include <eedefs.h>

// std string wrap for the assets path
#define ECA_ASSETS_DIR(path) (std::string(ASSETS_PATH) + path)

#define RELEASEP(x) if(x) {delete x; x = nullptr;}

/* @brief Helper macros for the easy id management */
#define LOCATION_ID(room, env)	(LocationID)(env | room << 4)
#define ROOM_ID(id)							(RoomID)(id >> 4)
#define ENVIRONMENT_ID(id)			(EnvironmentID)(id & ENVIRONMENT_MAX)


enum GameState {
	RUNNING,
	INITIALIZING,
	INGAME,
	MENU,
	EXIT,
};

enum RoomID {
	ROOM_OFFICE,
	ROOM_CORRIDOR,
	ROOM_COFFEE_ROOM,
	ROOM_CONFERENCE_ROOM,
	ROOM_CHAMBER,
	ROOM_VENTILATION_ROOM,
	ROOM_LADIES_TOILET,
	ROOM_GENTLEMENS_TOILET,
	ROOM_PRINCIPALS_ROOM,
	ROOM_ELEVATOR,
	ROOM_STAIRWELL,
	ROOM_LECTURE_HALL_1,
	ROOM_LECTURE_HALL_2,
	ROOM_LECTURE_HALL_3,
	ROOM_LECTURE_HALL_4,
	ROOM_LOCKER_ROOM,
	ROOM_STORAGE_ROOM,
	ROOM_ELEVATOR_SHAFT,

	ROOM_NONE
};

enum EnvironmentID {
	ENVIRONMENT_UPPER_LEVEL = 0x01,
	ENVIRONMENT_LOWER_LEVEL = 0x02,
	ENVIRONMENT_BOTH_LEVEL  = ENVIRONMENT_LOWER_LEVEL | ENVIRONMENT_UPPER_LEVEL,

	ENVIRONMENT_MAX = 0x0F
};

enum LocationID {
	LOCATION_OFFICE									= LOCATION_ID(ROOM_OFFICE,							ENVIRONMENT_UPPER_LEVEL),
	LOCATION_CORRIDOR_UP						= LOCATION_ID(ROOM_CORRIDOR,						ENVIRONMENT_UPPER_LEVEL),
	LOCATION_COFFEE_ROOM						= LOCATION_ID(ROOM_COFFEE_ROOM,					ENVIRONMENT_UPPER_LEVEL),
	LOCATION_CONFERENCE_ROOM				= LOCATION_ID(ROOM_CONFERENCE_ROOM,			ENVIRONMENT_UPPER_LEVEL),
	LOCATION_CHAMBER								= LOCATION_ID(ROOM_CHAMBER,							ENVIRONMENT_UPPER_LEVEL),
	LOCATION_VENTILATION_ROOM				= LOCATION_ID(ROOM_VENTILATION_ROOM,		ENVIRONMENT_UPPER_LEVEL),
	LOCATION_LADIES_TOILET_UP				= LOCATION_ID(ROOM_LADIES_TOILET,				ENVIRONMENT_UPPER_LEVEL),
	LOCATION_GENTLEMENS_TOILET_UP		= LOCATION_ID(ROOM_GENTLEMENS_TOILET,		ENVIRONMENT_UPPER_LEVEL),
	LOCATION_PRINCIPALS_ROOM				= LOCATION_ID(ROOM_PRINCIPALS_ROOM,			ENVIRONMENT_UPPER_LEVEL),
	LOCATION_ELEVATOR								= LOCATION_ID(ROOM_ELEVATOR,						ENVIRONMENT_UPPER_LEVEL),
	LOCATION_STAIRWELL							= LOCATION_ID(ROOM_STAIRWELL,						ENVIRONMENT_UPPER_LEVEL),
	LOCATION_CORRIDOR_DOWN					= LOCATION_ID(ROOM_CORRIDOR,						ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LECTURE_HALL_1					= LOCATION_ID(ROOM_LECTURE_HALL_1,			ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LECTURE_HALL_2					= LOCATION_ID(ROOM_LECTURE_HALL_2,			ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LECTURE_HALL_3					= LOCATION_ID(ROOM_LECTURE_HALL_3,			ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LECTURE_HALL_4					= LOCATION_ID(ROOM_LECTURE_HALL_4,			ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LADIES_TOILET_DOWN			= LOCATION_ID(ROOM_LADIES_TOILET,				ENVIRONMENT_LOWER_LEVEL),
	LOCATION_GENTLEMENS_TOILET_DOWN	= LOCATION_ID(ROOM_GENTLEMENS_TOILET,		ENVIRONMENT_LOWER_LEVEL),
	LOCATION_LOCKER_ROOM						= LOCATION_ID(ROOM_LOCKER_ROOM,					ENVIRONMENT_LOWER_LEVEL),
	LOCATION_STORAGE_ROOM						= LOCATION_ID(ROOM_STORAGE_ROOM,				ENVIRONMENT_LOWER_LEVEL),
	LOCATION_ELEVATOR_SHAFT					= LOCATION_ID(ROOM_ELEVATOR_SHAFT,			ENVIRONMENT_UPPER_LEVEL),

	LOCATION_NONE										= LOCATION_ID(ROOM_NONE,								ENVIRONMENT_MAX),
	LOCATION_INVALID
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

struct Item {
	// all set in GameManager::Init()
	ItemEnum		id;
	EEcstr		  name;
	EEcstr		  description;
	EEcstr		  interactDescription;
	bool				visible;
	bool				collected{ false };
};

struct Student {
	// all set in GameManager::Init()
	EEcstr name;
	EEcstr question;
	EEcstr answer;
	EEcstr hint;
	bool	 defeated{ false };
};

struct LocationDescriptions {
	// all set in GameManager::Init()
	EEcstr default				{ nullptr };
	EEcstr explore				{ nullptr };
	EEcstr alreadyExplored{ nullptr };
	EEcstr enter					{ nullptr };
};

struct LocationCreateInfo {
	//all set in GameManager::Init()
	LocationID							id					{ LocationID::LOCATION_NONE };
	std::vector<Item>				items				{};	// may still be empty after GameManager::Init()
	std::vector<LocationID> exits				{};	// may still be empty after GameManager::Init()
	std::vector<Student>		students		{};	// may still be empty after GameManager::Init()
	EEcstr									name				{ nullptr };
	LocationDescriptions		description	{};
	bool										visible			{ false };
	bool										explored		{ false };
};


// Getter specifications for the descriptions of the locations
enum LocationDescriptionType {
	DESC_DEFAULT					= offsetof(LocationDescriptions, default),
	DESC_EXPLORE					= offsetof(LocationDescriptions, explore),
	DESC_ALREADY_EXPLORED	= offsetof(LocationDescriptions, alreadyExplored),
	DESC_ENTER						= offsetof(LocationDescriptions, enter),
};