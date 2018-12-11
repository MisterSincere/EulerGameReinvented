#include <SFML/Window.hpp>


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