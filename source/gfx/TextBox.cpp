#include "TextBox.h"


//////////////
// INCLUDES //
//////////////
//#include <SFML/Window/Event.hpp>
//#include <SFML/Window/Keyboard.hpp>
//#include <SFML/Graphics/RenderWindow.hpp>
#include <assert.h>
#include <algorithm>
#include <string>

/////////////////
// MY INCLUDES //
/////////////////
#include "ecaDefs.h"


GFX::TextBox::TextBox(char const* text, /*sf::Font const& font, */unsigned int charSize)
	: IDrawable(/*{ 0.0f, 0.0f }, { 0.0f, 0.0f }*/)
	, m_characterSize(charSize)
	, i_rawString(text)
{
	/*i_renderText.setCharacterSize(m_characterSize);
	i_renderText.setFont(font);
	i_renderText.setString(i_rawString);
	
	i_size = { i_renderText.getLocalBounds().width, i_renderText.getLocalBounds().height };*/
}

GFX::TextBox::~TextBox() {
	/*RELEASEP(m_pBox);*/
}

GFX::TextBox::TextBox(bool haveBackground, /*sf::Vector2f const& size, sf::Vector2f const& position, */unsigned int charSize)
	: IDrawable(/*size, position*/)
	, m_characterSize(charSize)
{
	/*i_renderText.setCharacterSize(m_characterSize);
	i_renderText.setPosition({ i_position.x + i_leftPadding, i_position.y + i_topPadding });
	if(haveBackground) m_pBox = new Field(i_size, i_position);*/
}

void GFX::TextBox::Update(/*sf::Event const& event*/) {
	// Static text can be set with setText
}

void GFX::TextBox::Draw(/*sf::RenderWindow& window*/) {
	/*if(m_pBox) m_pBox->Draw(window);
	window.draw(i_renderText);*/
}

bool GFX::TextBox::isValidText(/*sf::Uint32 character*/) const {
	/*bool isNumber = character > 0x002F && character < 0x003A;
	bool isBigLetter = character > 0x0040 && character < 0x005B;
	bool isSmallLetter = character > 0x0060 && character < 0x007B;
	bool isSpace = character == 0x0020;

	return isNumber || isBigLetter || isSmallLetter || isSpace;*/
	return false;
}

void GFX::TextBox::TextWrap() {
	if (!i_rawString) return;

	// Set back to raw string
	//i_curStringWrapped = sf::String(i_rawString);
	//i_renderText.setString(i_curStringWrapped);

	//// Get current font
	//sf::Font const* font = i_renderText.getFont();
	//assert(font);

	//float xBound = i_position.x + i_size.x - i_rightPadding;
	//float yBound = i_position.y + i_size.y - i_bottomPadding;

	//// Query through string till a character is out of bounds to insert a line break
	//sf::Vector2f pos;
	//for (size_t i = 0; i < i_curStringWrapped.getSize(); i++) {
	//	// Check width out of bounds
	//	pos = i_renderText.findCharacterPos(i);
	//	if ((pos.x + font->getGlyph(i_curStringWrapped[i], m_characterSize, m_bold).advance) > xBound) {
	//		i -= InsertLineBreak(i);
	//		i_renderText.setString(i_curStringWrapped);
	//		pos = i_renderText.findCharacterPos(i);
	//	}
	//	// Break or erase the rest if out of bounds
	//	if ((pos.y + font->getGlyph(i_curStringWrapped[i], m_characterSize, m_bold).bounds.height) > yBound) {
	//		i_curStringWrapped.erase(i, i_curStringWrapped.getSize() - i);
	//		i_renderText.setString(i_curStringWrapped);
	//		break;
	//	}
	//}
}

int GFX::TextBox::InsertLineBreak(size_t index) {
	/*size_t tempIndex{ index };
	while (index > 1 && i_curStringWrapped[index] != ' ') index--;
	i_curStringWrapped.replace(index, 1, "\n");
	return int(tempIndex - index);*/
	return -1;
}

void GFX::TextBox::SetPadding(float left, float top, float right, float bottom, bool expand) {
	//if (!expand) {
	//	if (left + right + 10.0f >= i_size.x || top + bottom + 10.0f >= i_size.y) {
	//		printf("TextBox::Invalid padding! At least 10 pixels free space are required.\n");
	//		return;
	//	}

	//	i_leftPadding = left;
	//	i_topPadding = top;
	//	i_rightPadding = right;
	//	i_bottomPadding = bottom;
	//	i_renderText.setPosition({ i_position.x + i_leftPadding, i_position.y + i_topPadding });
	//	TextWrap();

	//// Expand the surrounding box so that the text has the same space
	//} else {
	//	i_size = { i_size.x + left + right, i_size.y + top + bottom };
	//	i_position = { i_position.x - left, i_position.y - top };
	//	// Update only box since the text and
	//	if (m_pBox) {
	//		m_pBox->SetSize(i_size.x, i_size.y);
	//		m_pBox->SetPosition(i_position.x, i_position.y);
	//	}
	//}

}

void GFX::TextBox::SetString(char const* text) {
	i_rawString = text;
	TextWrap();
}

void GFX::TextBox::SetSize(float w, float h) {
	// Clamp charactersize to the maximum of the box size
	//if (m_characterSize > h) {
	//	m_characterSize = static_cast<unsigned int>(h);
	//	i_renderText.setCharacterSize(m_characterSize);
	//}

	//i_size = { w,h };
	//if(m_pBox) m_pBox->SetSize(w, h);

	//// Wrap text to new size
	//TextWrap();
}

void GFX::TextBox::SetPosition(float x, float y) {
	/*i_position = { x, y };
	i_renderText.setPosition({ i_position.x + i_leftPadding, i_position.y + i_topPadding });
	if (m_pBox) m_pBox->SetPosition(x, y);*/
}

void GFX::TextBox::SetFont(/*sf::Font const& font*/) {
	/*i_renderText.setFont(font);*/
}

void GFX::TextBox::SetCharacterSize(unsigned int size) {
	/*m_characterSize = size;
	i_renderText.setCharacterSize(m_characterSize);
	TextWrap();*/
}

void GFX::TextBox::SetTextColor(/*sf::Color const& color*/) {
	/*i_renderText.setFillColor(color);*/
}

void GFX::TextBox::SetTextOutlineColor(/*sf::Color const& color*/) {
	/*i_renderText.setOutlineColor(color);*/
}

void GFX::TextBox::SetBackgroundColor(/*sf::Color const& bgColor*/) {
	/*if (!m_pBox) {
		m_pBox = new GFX::Field(i_size, i_position);
	}
	m_pBox->SetBackgroundColor(bgColor);*/
}

template<>
char const* GFX::TextBox::GetString<char const*>() const {
	return i_rawString;
}

template<>
std::string GFX::TextBox::GetString<std::string>() const {
	return std::string(i_rawString);
}