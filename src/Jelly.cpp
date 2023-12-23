#include"Jelly.h"

Jelly::Jelly(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Moveable(sprite,size,scale),m_speed()
{
	setFrameEnd(JELLY_FRAME_END);
	this->setisfish(false);
}

void Jelly::updateMovement(float dt)
{
	if (this->GetAcceleration() != 0)
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

Jelly::~Jelly()
{
}
