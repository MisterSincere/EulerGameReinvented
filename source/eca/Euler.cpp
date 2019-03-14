/////////////////////////////////////////////////////////////////////
// Filename: Euler.cpp
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#include "Euler.h"

#include "Tuna.h"
#include "Location.h"

ECA::Euler::Euler(SCENES::Tuna* pTuna, Location const* startLoc)
	: IEntity(startLoc)
	, m_pTuna(pTuna)
{
	assert(m_pTuna);
}

void ECA::Euler::move(Location const* pNewLocation)
{
	if (!i_isAlive) {
		EE_PRINT("[EULER] Tried to move, but dead!\n");
		return;
	}

	// Check if we are already at the desired location... you dumbass
	if (i_pCurLocation == pNewLocation) {
		EE_PRINT("[EULER] New location is already the current location!\n");
		return;
	}

	// Check if we can move to the new position
	if ((i_pCurLocation->isAdjacent(pNewLocation->getID()) || m_isBeamable) && pNewLocation->isVisible()) {
		m_pLastLocation = i_pCurLocation;
		i_pCurLocation = pNewLocation;

		m_pTuna->SetOutputText(pNewLocation->getDescription(DESC_ENTER));
		if (pNewLocation->isExplored()) {
			m_pTuna->AddOutputText(pNewLocation->getDescription(DESC_ALREADY_EXPLORED));
		} else {
			m_pTuna->AddOutputText(pNewLocation->getDescription(DESC_DEFAULT));
		}
	} else if (!m_isBeamable && !i_pCurLocation->isAdjacent(pNewLocation->getID()) && pNewLocation->isVisible()) {
		EE_PRINT("[EULER] Not beamable yet!\n");
	}
	
#if defined(DEBUG) //< this shenanigans should never be released
	// A wild switch appeared  RRAAAWR!!!
	// ... and is not needed
	switch (pNewLocation->id) {
	case 0|1|2|3|4|5: goto nichtstun;
	nichtstun:
	default: return;
	}
#endif
}

bool ECA::Euler::explore()
{
	return true;
}

EnvironmentID ECA::Euler::getEnvironmentID() const
{
	return ENVIRONMENT_ID(i_pCurLocation->getID());
}
