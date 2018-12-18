#pragma once


///////////////////////////
// FOREWARD DECLARATIONS //
///////////////////////////
namespace sf {
	class RenderWindow;
}

namespace CORETOOLS {

	/// Abstract Handler definition withouth a virtual Handle method
	class __IHandler {
	public:
		__IHandler(sf::RenderWindow* pW) : i_pWindow(pW) {}

	protected:
		sf::RenderWindow* i_pWindow;
	};

	/// Abstract of a handler by adding the Handle method
	template<typename TReturn, typename ... TParams>
	class IHandler : public __IHandler {
	public:
		IHandler(sf::RenderWindow* pW) : __IHandler(pW) {}
		virtual TReturn Handle(TParams ...) = 0;
	};
}