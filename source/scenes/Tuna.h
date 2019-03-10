#pragma once

#include <gfx/EEFontEngine.h>

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class EETextBox;
	class EEInputBox;
	class EERectangle;
}
namespace ECA {
	class GameManager;
}
class EulerAdventure;

namespace SCENES {

	class Tuna {
	public:
		Tuna(EulerAdventure* pAdv);
		Tuna(Tuna const&) = delete;
		Tuna(Tuna&&) = delete;
		~Tuna();

		void Update(EulerAdventure* pAdv);
		void Draw();

		void SetOutputText(EEstring text);
		void AddOutputText(EEstring text);

		void SetVisibility(bool isVisible);
		bool IsVisible();

	private:
		EulerAdventure* m_pAdv;
		EEApplication* m_pApp;
		GFX::EEFontEngine* m_pFontEngine;

		ECA::GameManager* m_pGameManager;

		GFX::EETextBox* m_pOutputBox;
		GFX::EEInputBox* m_pInputBox;

		GFX::EEFont m_square;
		GFX::EEFont m_arial;

		bool m_isVisible{ false };
	};
}