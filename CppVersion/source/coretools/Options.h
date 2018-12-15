#pragma once

/////////////////
// MY INCLUDES //
/////////////////
#include "IDrawable.h"

///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf {
	class RenderWindow;
}
namespace GFX {
	class Box;
}

namespace CORETOOLS {

	enum ScreenMode { FULLSCREEN, FAKE_FULLSCREEN, WINDOWED };


	struct Settings {
		ScreenMode		screenMode					{ WINDOWED };
		sf::Vector2u	clientSize					{ 200u, 200u };
		unsigned int	antialisingCount		{ 1u };
		unsigned int	frameLimit					{ 60u };
		bool					vsyncEnabled				{ false };
		char const*		title								{ "Hallo" };
	};


	class Options {
	public:
		Options();
		~Options();

		bool Init(Settings* pSettings);

		void Update(sf::Event const& evt, sf::RenderWindow*);
		void Draw(sf::RenderWindow& rw);

	private:
		Settings* m_pSettings;	//< Constructor

		GFX::Box* m_pBackground{ nullptr };	//< Constructor
	};
}