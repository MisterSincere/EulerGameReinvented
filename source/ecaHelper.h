/////////////////////////////////////////////////////////////////////
// Filename: ecaHelper.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include "ecaDefs.h"

namespace ECA {
	/**
	 * @brief Converts the string to the corresponding room id
	 **/
	extern RoomID strToRoomID(EEcstr str);
	extern EEcstr roomIDToStr(RoomID id);
}