
#define SFML_STATIC
#include <SFML/Window.hpp>

#ifndef _DEBUG
	#pragma comment(lib, "sfml-graphics-s.lib")
	#pragma comment(lib, "sfml-window-s.lib")
	#pragma comment(lib, "sfml-audio-s.lib")
	#pragma comment(lib, "sfml-network-s.lib")
	#pragma comment(lib, "sfml-system-s.lib")
#else
	#pragma comment(lib, "sfml-graphics-s-d.lib")
	#pragma comment(lib, "sfml-window-s-d.lib")
	#pragma comment(lib, "sfml-audio-s-d.lib")
	#pragma comment(lib, "sfml-network-s-d.lib")
	#pragma comment(lib, "sfml-system-s-d.lib")
#endif
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "flac.lib")
#pragma comment(lib, "vorbisenc.lib")
#pragma comment(lib, "vorbisfile.lib")
#pragma comment(lib, "vorbis.lib")
#pragma comment(lib, "ogg.lib")
#pragma comment(lib, "ws2_32.lib")


int main(char** argv, int argc)
{
	sf::Window window;
	window.create(sf::VideoMode(800, 600), "SFML Works!");

	while (window.isOpen())
	{
		// Check windows event
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
	}



	return 0;
}