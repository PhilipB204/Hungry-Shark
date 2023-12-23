#include "Splash.h"



Splash::Splash(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Static(sprite,size,scale)
{
	setAnimState(SPLASHY);
	setFrameEnd(SPLASH_FRAME_END);
}
