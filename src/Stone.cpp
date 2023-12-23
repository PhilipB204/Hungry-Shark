
#include"Stone.h"

Stone::Stone(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	setAnimState(STATIC);
}
