#include "Static.h"

Static::Static(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale)
	:GameObj(sprite, size, scale)
{//default animation is static = no movement at all

}
Static::~Static()
{
}
//end constructor 

void Static::update(float dt)
{
	updateAnomations();
}//end update

void Static::draw(sf::RenderWindow& window)
{
	if(!getNeed2BDelete() && !this->getFinishAnimation())
		window.draw(getSprite());
}//end draw


