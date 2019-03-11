/////////////////////////////////////////////////////////////////////
// Filename: IEntity.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include "ecaDefs.h"

namespace ECA {

	template<typename TReturn, typename ... TParams>
	class IEntity {
	public:
		IEntity(Location const* loc = nullptr) : i_pCurLocation(loc) {}

		virtual TReturn move(TParams ...) = 0;

		void setCurLocation(Location const* loc) { i_pCurLocation = loc; }
		LocationID getCurLocation() const { return i_pCurLocation->id; }
		bool setAlive(bool isAlive) { i_isAlive = isAlive; }
		bool isAlive() const { return i_isAlive; }

	protected:
		Location const* i_pCurLocation;
		bool						i_isAlive{ true };
	};

}