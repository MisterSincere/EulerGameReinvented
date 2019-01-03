#pragma once

//////////////
// INCLUDES //
//////////////
//#include <SFML/System/Vector2.hpp>

//////////////////////////
// FORWARD DECLARATIONS //
//////////////////////////
//namespace sf {
//	class RenderWindow;
//	class Event;
//	class Drawable;
//}

namespace GFX
{

	//enum CenterFlags {
	//	HORIZONTAL = 0x01,
	//	VERTICAL = 0x02,
	//	COMPLETE = HORIZONTAL | VERTICAL,
	//};

	class IDrawable
	{
	public:
		IDrawable(/*sf::Vector2f const& size, sf::Vector2f const& position*/) /*: i_size(size), i_position(position)*/ {}

		virtual void Update(/*sf::Event const&*/) = 0;
		virtual void Draw(/*sf::RenderWindow& window*/) = 0;


		virtual void SetBounds(float x, float y, float w, float h) { SetPosition(x, y); SetSize(w, h); }
		virtual void SetPositionAligned(/*CenterFlags f, sf::Vector2u const& size*/) { /*SetPosition((f&HORIZONTAL)?(size.x- i_size.x)/2.0f:i_position.x,(f&VERTICAL)?(size.y-i_size.y)/2.0f:i_position.y);*/}
		virtual void SetPosition(/*sf::Vector2f const& pos*/) { /*SetPosition(pos.x, pos.y);*/ }
		virtual void SetPosition(float x, float y) { /*i_position = { x,y };*/ }
		virtual void SetSize(/*sf::Vector2f const& size*/) { /*SetSize(size.x, size.y);*/ }
		virtual void SetSize(float w, float h) { /*i_size = { w,h };*/ }

		/*virtual sf::Vector2f GetSize() const { return i_size; }
		virtual sf::Vector2f GetPosition() const { return i_position; }*/

	protected:
		/*sf::Vector2f i_size;
		sf::Vector2f i_position;*/
	};

}