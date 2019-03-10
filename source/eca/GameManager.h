/////////////////////////////////////////////////////////////////////
// Filename: GameManager.h
//
// (C) Copyright 2019 Madness Studio. All Rights Reserved
/////////////////////////////////////////////////////////////////////
#pragma once

#include <map>
#include <coretools/IHandler.h>

#include "ecaDefs.h"

//////////////////////////
// FORWARD DECLARATIONS //
//////////////////////////
class EulerAdventure;
namespace SCENES {
	class Tuna;
}
namespace ECA {
	class Euler;
}


namespace ECA
{
	class GameManager : public ::CORETOOLS::ITextHandler
	{
	public:
		GameManager(EulerAdventure* pAdv, SCENES::Tuna* pTuna);

		bool Handle(EEcstr text) override;
		void Init();

		void PrintCurrentState();

	private:
		EulerAdventure* m_pAdv;
		SCENES::Tuna*		m_pTuna;
		ECA::Euler*			m_pEuler; //< HÖ!


		std::map<LocationID, Location> m_locations; //set in Init()
	};
}