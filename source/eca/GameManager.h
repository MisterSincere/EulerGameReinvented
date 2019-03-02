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


namespace ECA
{
	class GameManager : public ::CORETOOLS::ITextHandler
	{
	public:
		GameManager(EulerAdventure* pAdv);

		bool Handle(wchar_t const* text) override;
		void Init();

		void PrintCurrentState();

	private:
		EulerAdventure* m_pAdv;

		std::map<LocationEnum, Location*> m_locations; //set in Init()
	};
}