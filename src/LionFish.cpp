#include "..\include\LionFish.h"



LionFish::LionFish(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Moveable(sprite,size,scale)
{
	setFrameEnd(LIONFISH_FRAME_END);
}

void LionFish::updateMovement(float dt)
{

	if (this->GetAcceleration() != 0)
	{

		SetFishDirection();
		if (getDirection() == RIGHT)
			setAnimState(MOVING_RIGHT);
		else if (getDirection() == LEFT)
			setAnimState(MOVING_LEFT);
		else if (getDirection() == UP)
			setAnimState(MOVING_UP);
		else if (getDirection() == DOWN)
			setAnimState(MOVING_DOWN);
		if (getDirection() == RIGHTUP)
			setAnimState(RIGHT_UP);
		else if (getDirection() == LEFTUP)
			setAnimState(LEFT_UP);
		else if (getDirection() == RIGHTDOWN)
			setAnimState(RIGHT_DOWN);
		else if (getDirection() == LEFTDOWN)
			setAnimState(LEFT_DOWN);
		if (canMove(this->GetAcceleration(), this->getDirection()))
			move(dt);
	}
	else this->setAnimState(BLOOD);
}

LionFish::~LionFish()
{
}


