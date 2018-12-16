#pragma once

/////////////
// INCLUDE //
/////////////
#include "IHandler.h"


///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace GFX {
	class Button;
}

namespace CORETOOLS {

	enum ButtonEvent {
		HOVER = 0x01,
		CLICK = 0x02,
	};
	
	class IButtonHandler : public IHandler<void, ButtonEvent, GFX::Button*> {
	public:
		IButtonHandler(sf::RenderWindow* rw = nullptr) : IHandler(rw) {}
		virtual void Handle(ButtonEvent, GFX::Button*) override = 0;
	};
}