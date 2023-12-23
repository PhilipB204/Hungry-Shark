#pragma once
#include "Moveable.h"

class Crab :public Moveable {

public:

	Crab(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void    updateMovement(float dt) override;
	virtual ~Crab();



private:


};

