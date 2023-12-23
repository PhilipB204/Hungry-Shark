#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "macros.h"
class Player;
class PerrotFish;
class PufFish;
class LionFish ;
class Nemo;
class Orchid;
class Jelly;
class EnemyShark;
class Stone;
class Crab;
class Mine;
class Fire;

class GameObj {
public:
	GameObj(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual ~GameObj() = default;
	sf::Sprite& getSprite();
	const sf::Sprite& getSprite() const;
	sf::Vector2f getPosition() const;
	virtual void draw(sf::RenderWindow& window) = 0;
	sf::Vector2f getSize() const;
	void setPosition(sf::Vector2f pos);
	void setFrameEnd(sf::Vector2f frameEnd);
	void setNeed2BDelete();
	void UnDelete();
	void MakeBigger(sf::Vector2f);

	bool getNeed2BDelete() const;
	bool getFinishAnimation() const;
	ANIMATION_STATES getAnimationState();
	bool getBlood() const;
	void setBlood(bool);

	virtual void update(float dt = 0) = 0;
	void updateAnomations();
	void setAnimState(ANIMATION_STATES state);
	void setSpriteSize(sf::Vector2f size);

private:
	sf::Sprite m_sprite;
	Animation m_animation;
	bool m_need2BDelete;
};