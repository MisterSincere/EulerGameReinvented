#include "TextBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


GFX::TextBox::TextBox()
{
	m_renderText.setCharacterSize(m_characterSize);
	m_renderText.setPosition(m_position);
}

void GFX::TextBox::Update(sf::Event const& event)
{
	// Static text can be set with setText
}

void GFX::TextBox::Draw(sf::RenderWindow& window)
{
	window.draw(m_renderText);
}

bool GFX::TextBox::isValidText(sf::Uint32 character) const {
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;
	bool isSpace = character == 0x0020;

	return isNumber || isBigLetter || isSmallLetter || isSpace;
}

void GFX::TextBox::TextWrap() {
	if (!m_rawString) return;

	// Set back to raw string
	m_curStringWrapped = sf::String(m_rawString);
	m_renderText.setString(m_curStringWrapped);

	// Query through string till a character is out of bounds to insert a line break
	sf::Vector2f pos;
	for (size_t i = 0; i < m_curStringWrapped.getSize(); i++) {
		// Check width out of bounds
		pos = m_renderText.findCharacterPos(i);
		if (pos.x > (m_position.x + m_size.x)) {
			i -= InsertLineBreak(i);
			m_renderText.setString(m_curStringWrapped);
			pos = m_renderText.findCharacterPos(i);
		}
		// Break or erase the rest if out of bounds
		if (pos.y > (m_position.y + m_size.y)) {
			m_curStringWrapped.erase(i, m_curStringWrapped.getSize() - i);
			m_renderText.setString(m_curStringWrapped);
			break;
		}
	}
}

int GFX::TextBox::InsertLineBreak(size_t index) {
	size_t tempIndex{ index };
	while (index > 0 && m_curStringWrapped[index] != ' ') index--;
	m_curStringWrapped.replace(index, 1, "\n");
	return (tempIndex - index);
}

void GFX::TextBox::SetString(char const* text) {
	m_rawString = text;
	TextWrap();
}

void GFX::TextBox::SetBounds(float x, float y, float w, float h) {
	SetPosition(x, y);
	SetSize(w, h);
}

void GFX::TextBox::SetSize(float w, float h) {
	// Clamp charactersize to the maximum of the box size
	if (m_characterSize > h) {
		m_characterSize = static_cast<unsigned int>(h);
		m_renderText.setCharacterSize(m_characterSize);
	}

	m_size = { w,h };
	// TODO: Update possible background box

	// Wrap text to new size
	TextWrap();
}

void GFX::TextBox::SetPosition(float x, float y) {
	m_position = { x, y };
	m_renderText.setPosition(x, y);
}

void GFX::TextBox::SetFont(sf::Font const& font) {
	m_renderText.setFont(font);
}

void GFX::TextBox::SetCharacterSize(unsigned int size) {
	m_renderText.setCharacterSize(size);
	TextWrap();
}

void GFX::TextBox::SetFillColor(sf::Color const& color) {
	m_renderText.setFillColor(color);
}

void GFX::TextBox::SetOutlineColor(sf::Color const& color) {
	m_renderText.setOutlineColor(color);
}

template<>
char const* GFX::TextBox::GetString<char const*>() const {
	return m_rawString;
}

template<>
std::string GFX::TextBox::GetString<std::string>() const {
	return std::string(m_rawString);
}