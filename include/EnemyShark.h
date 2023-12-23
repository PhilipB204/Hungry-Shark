#pragma once
#include "Moveable.h"
#include"Player.h"

class EnemyShark :public Moveable {

public:

	EnemyShark(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void    updateMovement(float dt) override;
	void SetEnemyDirection();
	void setPlayer(Player* player);



private:

	Player* m_player;
};
