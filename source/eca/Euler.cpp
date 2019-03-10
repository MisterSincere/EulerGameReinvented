/////////////////////////////////////////////////////////////////////
// Filename: Euler.cpp
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#include "Euler.h"

#include "ecaHelper.h"
#include "Tuna.h"

ECA::Euler::Euler(SCENES::Tuna* pTuna, Location const* startLoc)
	: IEntity(startLoc)
	, m_pTuna(pTuna)
{
	assert(m_pTuna);
}

void ECA::Euler::move(Location const* pNewLocation)
{
	// Check if we are already at the desired location... you dumbass
	if (i_pCurLocation->id == pNewLocation->id) {
		EE_PRINT("[EULER] New location is already the current location!\n");
		return;
	}

	// Check if we can move to the new position
	if ((isExitOf(pNewLocation->id, i_pCurLocation) || m_isBeamable) && pNewLocation->visible) {
		m_pLastLocation = i_pCurLocation;
		i_pCurLocation = pNewLocation;

		m_pTuna->SetOutputText(pNewLocation->description.enter);
		if (pNewLocation->explored) {
			m_pTuna->AddOutputText(pNewLocation->description.alreadyExplored);
		} else {
			m_pTuna->AddOutputText(pNewLocation->description.default);
		}
	}

	// A wild switch appeared  RRAAAWR!!!
	// ... and is not needed
	switch (pNewLocation->id) {
	case 0|1|2|3|4|5: goto nichtstun;
	nichtstun:
	default: return;
	}
}