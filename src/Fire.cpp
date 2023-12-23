#include "..\include\Fire.h"

Fire::Fire(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	setAnimState(ONPLACE);
	setFrameEnd(FIRE_FRAME_END);
}
