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
	class Euler : public IEntity<void, ::ECA::Location const*>
	{
	public:
		Euler(SCENES::Tuna* pTuna, ::ECA::Location const* startLoc = nullptr);

		void move(::ECA::Location const* pNewRoom) override;

		/* @brief returns false if the current location was already explored */
		bool explore();

		EnvironmentID getEnvironmentID() const;

	private:
		bool						m_isBeamable{ false };
		SCENES::Tuna*		m_pTuna;

		Location const*	m_pLastLocation{ nullptr };
	};
}