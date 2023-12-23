#pragma once
#include "macros.h"
//#include "Sounds.h"
#include <iostream>
#include"Moveable.h"
#include"Player.h"
#include"EnemyShark.h"
class Enemy :public EnemyShark
{
public:

	Enemy(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	void SetEnemySpeed();
	void SetEnemyDirection();

private:

Player* m_player;


};