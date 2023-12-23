#include"Enemy.h"

Enemy::Enemy(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale):EnemyShark(sprite,size,scale),m_player()
{
	
}



void Enemy::SetEnemySpeed()
{
	this->setAcceleration(ACCELERATION1);
}

void Enemy::SetEnemyDirection()
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
