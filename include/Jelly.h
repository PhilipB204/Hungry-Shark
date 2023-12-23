#pragma once
#include "Moveable.h"

class Jelly :public Moveable {


public:

	Jelly(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void    updateMovement(float dt) override;
	virtual ~Jelly();


private:
	sf::Vector2f m_speed;

};

