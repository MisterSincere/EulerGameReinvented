/////////////////////////////////////////////////////////////////////
// Filename: ecaHelper.cpp
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#include "ecaHelper.h"

#include <algorithm>


#define ROOM_TO_ID_CORR \
	__TCASE("office", OFFICE) \
	else __TCASE("corridor", CORRIDOR) \
	else __TCASE("coffeeroom", COFFEE_ROOM) \
	else __TCASE("conferenceroom", CONFERENCE_ROOM) \
	else __TCASE("chamber", CHAMBER) \
	else __TCASE("ventroom", VENTILATION_ROOM) \
	else __TCASE("ladiestoilet", LADIES_TOILET) \
	else __TCASE("gentlemenstoilet", GENTLEMENS_TOILET) \
	else __TCASE("principalsroom", PRINCIPALS_ROOM) \
	else __TCASE("elevator", ELEVATOR) \
	else __TCASE("stairwell", STAIRWELL) \
	else __TCASE("lecturehall1", LECTURE_HALL_1) \
	else __TCASE("lecturehall2", LECTURE_HALL_2) \
	else __TCASE("lecturehall3", LECTURE_HALL_3) \
	else __TCASE("lecturehall4", LECTURE_HALL_4) \
	else __TCASE("lockerroom", LOCKER_ROOM) \
	else __TCASE("storageroom", STORAGE_ROOM) \
	else __TCASE("elevatorshaft", ELEVATOR_SHAFT)



RoomID ECA::strToRoomID(EEcstr str)
{
#define __TCASE(val, id) if(EE_STRCMP(str, STR(val)) == 0) return ROOM_##id;
	ROOM_TO_ID_CORR
#undef __TCASE
	return ROOM_NONE;
}

EEcstr ECA::roomIDToStr(RoomID idToCompare)
{
#define __TCASE(val, id) if(ROOM_##id == idToCompare) return STR(val);
	ROOM_TO_ID_CORR
#undef __TCASE
	return STR("");
}

bool ECA::isExitOf(LocationID id, Location const* loc)
{
	return std::find(loc->exits.begin(), loc->exits.end(), id) != loc->exits.end();
}