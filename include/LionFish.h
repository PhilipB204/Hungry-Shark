#pragma once
#include "Moveable.h"

class LionFish :public Moveable {

public:

    	LionFish(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	     virtual void    updateMovement(float dt) override;
		 virtual ~LionFish();



private:







};