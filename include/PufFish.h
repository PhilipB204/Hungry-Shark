#pragma once
#include "Moveable.h"

class PufFish :public Moveable {

public:

	PufFish(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void   updateMovement(float dt) override;
	virtual ~PufFish();



private:








};