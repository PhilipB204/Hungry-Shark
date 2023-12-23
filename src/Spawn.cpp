#include "..\include\Spawn.h"

Spawn::Spawn(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	setAnimState(SPAWNY);
	setFrameEnd(SPAWN_FRAME_END);
}
