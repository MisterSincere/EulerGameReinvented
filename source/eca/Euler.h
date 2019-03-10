/////////////////////////////////////////////////////////////////////
// Filename: Euler.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include "IEntity.h"

namespace SCENES {
	class Tuna;
}


namespace ECA {
	class Euler : public IEntity<void, Location const*>
	{
	public:
		Euler(SCENES::Tuna* pTuna, Location const* startLoc = nullptr);

		void move(Location const* pNewRoom) override;

		EnvironmentID getEnvironmentID() const { return ENVIRONMENT_ID(i_pCurLocation->id); }

	private:
		bool						m_isBeamable{ false };
		SCENES::Tuna*		m_pTuna;

		Location const*	m_pLastLocation{ nullptr };
	};
}