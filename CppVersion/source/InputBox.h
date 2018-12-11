#pragma once

#include "TextBox.h"

namespace GFX
{
	class InputBox : public TextBox
	{
	public:
		InputBox();

		void Update(sf::Event const&) override;

	private:
		sf::String m_prefix;
	};
}