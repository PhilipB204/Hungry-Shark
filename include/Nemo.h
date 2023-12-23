#pragma once
#include "Moveable.h"

class Nemo :public Moveable {

public:

	Nemo(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void    updateMovement(float dt) override;



private:








};