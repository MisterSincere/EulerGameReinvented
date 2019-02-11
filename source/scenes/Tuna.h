#pragma once

#include <gfx/EEFontEngine.h>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class EETextBox;
	class EERectangle;
}
class EulerAdventure;

namespace SCENES {

	class Tuna {
	public:
		Tuna(GFX::EEFontEngine* pFontEngine);
		Tuna(Tuna const&) = delete;
		Tuna(Tuna&&) = delete;
		~Tuna();

		void Update(EulerAdventure* pAdv);
		void Draw();

		void SetVisibility(bool isVisible);
		bool IsVisible();

	private:
		EEApplication* m_pApp;
		GFX::EEFontEngine* m_pFontEngine;

		GFX::EETextBox* m_pTestBox;

		GFX::EEFont m_square;
		GFX::EEFont m_arial;

		bool m_isVisible{ false };
	};
}