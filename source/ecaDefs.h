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

enum ItemEnum {
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