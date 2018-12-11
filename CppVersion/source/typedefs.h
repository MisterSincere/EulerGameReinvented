#pragma once

namespace Utils
{

	enum WindowFlagBits
	{
		CENTERED_X = 0x01,
		CENTERED_Y = 0x02,
		CENTERED = CENTERED_X | CENTERED_Y
	};
	typedef unsigned int WindowFlags;


	enum ScreenMode
	{
		FULLSCREEN,
		WINDOWED
		/*FAKE_FULLSCREEN*/
	};

	struct Rect32U
	{
		unsigned int w;
		unsigned int h;
	};

	struct Point32F
	{
		float x;
		float y;
	};

	struct WindowCreateInfo
	{
		const char*	title				= "EulerCoffeeAdventure";
		Rect32U			size				= { 800u, 600u };
		Point32F		position	  = { 0.f, 0.f };
		ScreenMode	screenMode	= WINDOWED;
		WindowFlags flags				= CENTERED;
	};

}