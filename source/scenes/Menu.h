#pragma once

#include <gfx/EEFontEngine.h>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class EETextBox;
}
class EulerAdventure;

namespace SCENES {

	class Menu {
	public:
		Menu(GFX::EEFontEngine* pFontEngine);
		Menu(Menu const&) = delete;
		Menu(Menu&&) = delete;
		~Menu();

		void Update(EulerAdventure* pAdv);
		void Draw();

		void SetVisibility(bool isVisible);
		bool IsVisible();

	private:
		EEApplication* m_pApp;
		GFX::EEFontEngine* m_pFontEngine;

		GFX::EETextBox* m_pTitle;
		GFX::EETextBox* m_pExitButton;
		GFX::EETextBox* m_pStartButton;

		GFX::EEFont m_font;

		bool m_isVisible{ false };
	};
}