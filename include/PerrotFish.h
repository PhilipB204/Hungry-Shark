#pragma once
#include "Moveable.h"

class PerrotFish :public Moveable {

public:

	PerrotFish(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void    updateMovement(float dt) override;




private:





};