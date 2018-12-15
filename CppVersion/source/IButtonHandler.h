#pragma once

/////////////
// INCLUDE //
/////////////
#include "IHandler.h"

namespace CORETOOLS {
	
	class IButtonHandler : public IHandler<void, void> {
	public:
		IButtonHandler(sf::RenderWindow* rw = nullptr) : IHandler(rw) {}
		virtual void Handle(void) override = 0;
	};
}