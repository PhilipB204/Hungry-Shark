#include"Explode.h"

Explode::Explode(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	
	this->setAnimState(EXPLODE);
	this->setFrameEnd(EXPLOSION_FRAME_END);

}
