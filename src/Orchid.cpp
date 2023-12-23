#include "..\include\Orchid.h"


Orchid::Orchid(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	setAnimState(ONPLACE);
	setFrameEnd(ORCHID_FRAME_END);
}


