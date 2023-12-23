#pragma once
#include <SFML/Graphics.hpp>
#include "macros.h"


class Animation {
public:
	Animation(sf::Sprite& sprite, sf::Vector2f rectsize, sf::Vector2f scale);
	void updateAnimations();

	void setAnimState(ANIMATION_STATES state);
	void setSpriteSize(sf::Vector2f size);
	ANIMATION_STATES getAnimationState();
	void setFrameEnd(sf::Vector2f frameEnd);

	bool getFinishAnimation() const;
	bool getFinishBlood()const;
	void ChangeScale(sf::Vector2f);
	void SetBlood(bool );



private:
	sf::Clock m_timer;
	ANIMATION_STATES m_animState;
	ANIMATION_STATES m_facingTo;//to which direction the figure is facing
	sf::IntRect m_currentFrame;
	sf::IntRect m_currentBlood;
	

	sf::Vector2f m_rectSize;//the size of each part of the sprite sheet
	sf::Vector2f m_scale;
	sf::Vector2f m_frameEnd;//left & right
	sf::Vector2f m_spriteSize;//the size of the whole sprite sheet

	bool m_finishAnimation;
	bool m_finishblood;
	sf::Sprite& m_sprite;

};