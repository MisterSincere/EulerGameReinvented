#include "TextBox.h"


//////////////
// INCLUDES //
//////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


GFX::TextBox::TextBox()
{
	i_renderText.setCharacterSize(i_characterSize);
	i_renderText.setPosition(i_position);
}

void GFX::TextBox::Update(sf::Event const& event)
{
	// Static text can be set with setText
}

void GFX::TextBox::Draw(sf::RenderWindow& window)
{
	window.draw(i_renderText);
}

bool GFX::TextBox::isValidText(sf::Uint32 character) const {
	bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;
	bool isSpace = character == 0x0020;

	return isNumber || isBigLetter || isSmallLetter || isSpace;
}

void GFX::TextBox::TextWrap() {
	if (!i_rawString) return;

	// Set back to raw string
	i_curStringWrapped = sf::String(i_rawString);
	i_renderText.setString(i_curStringWrapped);

	// Query through string till a character is out of bounds to insert a line break
	sf::Vector2f pos;
	for (size_t i = 0; i < i_curStringWrapped.getSize(); i++) {
		// Check width out of bounds
		pos = i_renderText.findCharacterPos(i);
		if (pos.x > (i_position.x + i_size.x)) {
			i -= InsertLineBreak(i);
			i_renderText.setString(i_curStringWrapped);
			pos = i_renderText.findCharacterPos(i);
		}
		// Break or erase the rest if out of bounds
		if (pos.y > (i_position.y + i_size.y)) {
			i_curStringWrapped.erase(i, i_curStringWrapped.getSize() - i);
			i_renderText.setString(i_curStringWrapped);
			break;
		}
	}
}

int GFX::TextBox::InsertLineBreak(size_t index) {
	size_t tempIndex{ index };
	while (index > 0 && i_curStringWrapped[index] != ' ') index--;
	i_curStringWrapped.replace(index, 1, "\n");
	return (tempIndex - index);
}

void GFX::TextBox::SetString(char const* text) {
	i_rawString = text;
	TextWrap();
}

void GFX::TextBox::SetBounds(float x, float y, float w, float h) {
	SetPosition(x, y);
	SetSize(w, h);
}

void GFX::TextBox::SetSize(float w, float h) {
	// Clamp charactersize to the maximum of the box size
	if (i_characterSize > h) {
		i_characterSize = static_cast<unsigned int>(h);
		i_renderText.setCharacterSize(i_characterSize);
	}

	i_size = { w,h };
	// TODO: Update possible background box

	// Wrap text to new size
	TextWrap();
}

void GFX::TextBox::SetPosition(float x, float y) {
	i_position = { x, y };
	i_renderText.setPosition(x, y);
}

void GFX::TextBox::SetFont(sf::Font const& font) {
	i_renderText.setFont(font);
}

void GFX::TextBox::SetCharacterSize(unsigned int size) {
	i_characterSize = size;
	i_renderText.setCharacterSize(i_characterSize);
	TextWrap();
}

void GFX::TextBox::SetFillColor(sf::Color const& color) {
	i_renderText.setFillColor(color);
}

void GFX::TextBox::SetOutlineColor(sf::Color const& color) {
	i_renderText.setOutlineColor(color);
}

template<>
char const* GFX::TextBox::GetString<char const*>() const {
	return i_rawString;
}

template<>
std::string GFX::TextBox::GetString<std::string>() const {
	return std::string(i_rawString);
}