#include "Window.h"

//////////////
// INCLUDES //
//////////////
#include <assert.h>

GFX::Window::Window(Utils::WindowCreateInfo const& cinfo)
{
	m_window.create(sf::VideoMode(cinfo.size.w, cinfo.size.h), cinfo.title);

}

GFX::Window::~Window()
{

}

bool GFX::Window::pollEvent(sf::Event& event) {
	return m_window.pollEvent(event);
}

void GFX::Window::close() {
	m_window.close();
}

bool GFX::Window::isOpen() const {
	return m_window.isOpen();
}

Utils::Rect32U const& GFX::Window::getSize() const {
	return m_size;
}

sf::Window const& GFX::Window::getWindow() const {
	return m_window;
}