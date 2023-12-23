#include "..\include\Crab.h"

Crab::Crab(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Moveable(sprite,size,scale)
{
	setFrameEnd(CRAB_FRAME_END);
	this->setisfish(false);
}

void Crab::updateMovement(float dt)
{
	

	if (this->GetAcceleration() != zero)
	{

		SetCrastationDirection();
		if (getDirection() == RIGHT)
			setAnimState(MOVING_RIGHT);
		else if (getDirection() == LEFT)
			setAnimState(MOVING_LEFT);
		else if (getDirection() == UP)
			setAnimState(MOVING_UP);
		else if (getDirection() == DOWN)
			setAnimState(MOVING_DOWN);
		if (canMove(this->GetAcceleration(), this->getDirection()))
			move(dt);
	}
	else this->setAnimState(BLOOD);
}

Crab::~Crab()
{
}
