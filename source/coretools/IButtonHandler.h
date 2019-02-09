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
		NONE = 0x00,
		HOVER = 0x01,
		CLICK = 0x02,
		RELEASE = 0x04,
	};
	
	class IButtonHandler : public IHandler<void, ButtonEvent, GFX::Button*> {
	public:
		IButtonHandler(/*sf::RenderWindow* rw = nullptr*/) : IHandler(/*rw*/) {}
		virtual void Handle(ButtonEvent, GFX::Button*) override = 0;
	};
}