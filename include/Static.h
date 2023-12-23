#pragma once
#include "GameObj.h"
class Static : public GameObj {

public:
	Static(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual ~Static();
	virtual void update(float dt = 0) override;
	virtual void draw(sf::RenderWindow& window) override;
	
private:
	
};