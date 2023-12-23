#include "Animation.h"
#include<iostream>
Animation::Animation(sf::Sprite& sprite, sf::Vector2f rectsize, sf::Vector2f scale)
	: m_sprite(sprite), m_rectSize(rectsize), m_scale(scale), m_finishAnimation(false),m_finishblood(false)
{//Animation constructor - load the first rect to the sprite
	m_timer.restart();
	m_currentFrame = sf::IntRect(zero, zero, m_rectSize.x, m_rectSize.y);
	m_sprite.setTextureRect(m_currentFrame);
	m_sprite.setScale(m_scale.x, m_scale.y);

	m_currentBlood = sf::IntRect(zero, zero, BLOOD_SIZE.x, BLOOD_SIZE.y);
	

}//end Animation constructor

void Animation::setAnimState(ANIMATION_STATES state)
{
	m_facingTo = state;
	m_animState = state;
}//end setAnimState

void Animation::updateAnimations()
{//update the rect of the sprite according to the clock
	m_sprite.setOrigin(m_currentFrame.width/2.f, m_currentFrame.height/2.f);
	bool bloodfin = false;
	if (m_animState == STATIC)//still sprite
		return;

	else if (m_animState == SPAWNY && !m_finishAnimation)
	{

		if (m_timer.getElapsedTime().asSeconds() >= 0.9f)
		{
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left > BLOOD_FRAME_END.x)//reached to the end of the sprite(width)
				m_currentFrame.left = zero;

			m_currentBlood.top += m_rectSize.y;
			if (m_currentFrame.top > SPAWN_FRAME_END.y)//reached to the end of the sprite(height)
			{
				m_finishAnimation = true;
			}

			m_timer.restart();
			m_sprite.setTextureRect(m_currentBlood);
			m_sprite.setScale(SPLASH_SCALE);

		}
	}

	else if (m_animState == BLOOD && !m_finishblood )
	{
	
		
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentBlood.left += BLOOD_SIZE.x;
			if (m_currentBlood.left > BLOOD_FRAME_END.x)//reached to the end of the sprite(width)
				m_currentBlood.left = zero;

			m_currentBlood.top += BLOOD_SIZE.y;
			if (m_currentBlood.top > BLOOD_FRAME_END.y)//reached to the end of the sprite(height)
			{
				m_finishAnimation = true;
				m_finishblood = true;
			
			}

			m_timer.restart();
			m_sprite.setTextureRect(m_currentBlood);
			m_sprite.setScale(SPLASH_SCALE);

		}
	}
	else if (m_animState == EXPLODE && !m_finishAnimation )
	{
	
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.left += 200.f;
			if (m_currentFrame.left >1600.f)//reached to the end of the sprite(width)
				m_currentFrame.left = 0;

				m_currentFrame.top +=200.f;
				if (m_currentFrame.top >1550.f)//reached to the end of the sprite(height)
				{
					m_currentFrame.top = 0.f;
					m_finishAnimation = true;
				}
			
			m_timer.restart();
			m_sprite.setTextureRect(m_currentFrame);
			m_sprite.setScale(EXPLOSION_SCALE.x, EXPLOSION_SCALE.y);
			
		}
	}
	else if (m_animState == SPLASHY )
	{

		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left > SPLASH_FRAME_END.x)//reached to the end of the sprite(width)
				m_currentFrame.left = 0;

			m_currentFrame.top += m_rectSize.y;
			if (m_currentFrame.top > SPLASH_FRAME_END.y)//reached to the end of the sprite(height)
			{
				m_currentFrame.top = 0.f;
			}

			m_timer.restart();
			m_sprite.setTextureRect(m_currentFrame);

		}
	}



	else if (m_animState == ONPLACE)
	{
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.top = 0.f;
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left >= m_frameEnd.x-1)
				m_currentFrame.left = 0;

			m_timer.restart();
			m_sprite.setTextureRect(m_currentFrame);

		}

	}
	
	else if (m_animState == LEFT_DOWN)
	{
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.top = 0.f;
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left >= m_frameEnd.x)
				m_currentFrame.left = 0;

			m_timer.restart();
			m_sprite.setTextureRect(m_currentFrame);
		}
		m_sprite.setRotation(315.f);
		m_sprite.setScale(m_scale.x, m_scale.y);

	}
	else if (m_animState == RIGHT_DOWN)
	{
	if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
	{
		m_currentFrame.top = 0.f;
		m_currentFrame.left += m_rectSize.x;
		if (m_currentFrame.left >= m_frameEnd.x)
			m_currentFrame.left = 0;

		m_timer.restart();
		m_sprite.setTextureRect(m_currentFrame);
		m_sprite.setScale(-m_scale.x, m_scale.y);

	}
	m_sprite.setScale(-m_scale.x, m_scale.y);
	m_sprite.setRotation(45.f);

	}
	else if (m_animState == LEFT_UP)
	{
	if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
	{
		m_currentFrame.top = 0.f;
		m_currentFrame.left += m_rectSize.x;
		if (m_currentFrame.left >= m_frameEnd.x)
			m_currentFrame.left = 0;

		m_timer.restart();
		m_sprite.setTextureRect(m_currentFrame);
	}
	m_sprite.setRotation(45.f);
	m_sprite.setScale(m_scale.x, m_scale.y);

	}
	else if (m_animState == RIGHT_UP)
	{
	if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
	{
		m_currentFrame.top = 0.f;
		m_currentFrame.left += m_rectSize.x;
		if (m_currentFrame.left >= m_frameEnd.x)
			m_currentFrame.left = 0;

		m_timer.restart();
		m_sprite.setTextureRect(m_currentFrame);
		m_sprite.setScale(-m_scale.x, m_scale.y);
		m_sprite.setRotation(135.f);
	}
	m_sprite.setScale(-m_scale.x, m_scale.y);
	m_sprite.setRotation(345.f);


	}
	else if (m_animState == MOVING_LEFT)
	{
	if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
	{
		m_currentFrame.top = 0.f;
		m_currentFrame.left += m_rectSize.x;
		if (m_currentFrame.left >= m_frameEnd.x)
			m_currentFrame.left = 0;

		m_timer.restart();
		m_sprite.setTextureRect(m_currentFrame);
		m_sprite.setRotation(0);

	}
	m_sprite.setScale(m_scale.x, m_scale.y);

	}
	else if (m_animState == MOVING_RIGHT)
	{
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.top = 0;
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left >= m_frameEnd.x)
				m_currentFrame.left = 0;
	
			m_sprite.setTextureRect(m_currentFrame);
			m_timer.restart();
			m_sprite.setRotation(360.f);
	
		}
		m_sprite.setScale(-m_scale.x, m_scale.y);
	}
	else if (m_animState == MOVING_DOWN)
	{
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
	     	m_currentFrame.top = 0.f;
			m_currentFrame.left += m_rectSize.x;
				if (m_currentFrame.left >= m_frameEnd.x)
					m_currentFrame.left = 0;
			m_sprite.setTextureRect(m_currentFrame);
			m_sprite.setRotation(270.f);
			m_timer.restart();
		}
		m_sprite.setScale(m_scale.x, m_scale.y);
	}

	else if (m_animState == MOVING_UP)
	{
		
		if (m_timer.getElapsedTime().asSeconds() >= 0.3f)
		{
			m_currentFrame.top = 0.f;
			m_currentFrame.left += m_rectSize.x;
			if (m_currentFrame.left >= m_frameEnd.x)
				m_currentFrame.left = 0;
			m_sprite.setTextureRect(m_currentFrame);
			m_sprite.setRotation(-270.f);
			m_timer.restart();
		
		}
		m_sprite.setScale(m_scale.x, m_scale.y);

	}


}//end updateAnimations

void Animation::setSpriteSize(sf::Vector2f size)
{
	m_spriteSize = size;
}
ANIMATION_STATES Animation::getAnimationState()
{
	return m_animState;
}
//end setSpriteSize

void Animation::setFrameEnd(sf::Vector2f frameEnd)
{
	m_frameEnd = frameEnd;
}//end setFrameEnd



bool Animation::getFinishAnimation() const
{
	return m_finishAnimation;
}
bool Animation::getFinishBlood() const
{
	return m_finishblood;
}
void Animation::ChangeScale(sf::Vector2f sca)
{
	m_scale = sca;

}
void Animation::SetBlood(bool vur)
{
	m_finishblood = vur;
}
//end getFinishAnimation


