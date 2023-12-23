#include"EnemyShark.h"
#include "Enemy.h"
EnemyShark::EnemyShark(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):Moveable(sprite,size,scale)
{
	setFrameEnd(ESHARK_FRAME_END);
	this->setisfish(true);
}

void EnemyShark::updateMovement(float dt)
{

	if (this->GetAcceleration() != 0)
	{

		if (this->GetAcceleration() != 0)
		{
		
			if (abs(this->getPosition().x - m_player->getPosition().x) <= 500.f
				&& abs(this->getPosition().y - m_player->getPosition().y <= 500.f))
				SetEnemyDirection();
			else
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

	}
	else this->setAnimState(BLOOD);

}

void EnemyShark::SetEnemyDirection()
{
	auto path1 = abs(getPosition().x - m_player->getPosition().x);
	auto path2 = abs(getPosition().y - m_player->getPosition().y);

	if (getPosition().x > m_player->getPosition().x && path2 < path1)
		setDirection(sf::Vector2f(LEFT));//left

	else if (getPosition().x < m_player->getPosition().x && path2 < path1)
		setDirection(sf::Vector2f(RIGHT));//right

	else if (getPosition().y > m_player->getPosition().y && path2 > path1)
		setDirection(sf::Vector2f(UP));//up

	else  if (getPosition().y < m_player->getPosition().y && path2 > path1)
		setDirection(sf::Vector2f(DOWN));//down
}

void EnemyShark::setPlayer(Player* player)
{
	m_player = player;
}




