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

	protected:
		Location const* i_pCurLocation;
	};

}