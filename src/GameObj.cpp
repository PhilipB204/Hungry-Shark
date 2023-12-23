#include "GameObj.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "macros.h"
GameObj::GameObj(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale)
	: m_sprite(sprite), m_animation(m_sprite, size, scale), m_need2BDelete(false)
{

}

//end constructor

sf::Sprite& GameObj::getSprite()
{
	return m_sprite;
}//end getSprite

const sf::Sprite& GameObj::getSprite() const
{
	return m_sprite;
}//end getSprite

sf::Vector2f GameObj::getPosition() const
{
	return m_sprite.getPosition();
}//end getPosition

sf::Vector2f GameObj::getSize() const
{
	return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
}

void GameObj::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}
void GameObj::setFrameEnd(sf::Vector2f frameEnd)
{
	m_animation.setFrameEnd(frameEnd);
}
//end setPosition

void GameObj::setNeed2BDelete()
{
	m_need2BDelete = true;
}
void GameObj::UnDelete()
{
	m_need2BDelete = false;
}
void GameObj::MakeBigger(sf::Vector2f size)
{
	m_animation.ChangeScale(size);
}
//end setNeed2BDelete

bool GameObj::getNeed2BDelete() const
{
	return m_need2BDelete;
}//end getNeed2BDelete

bool GameObj::getFinishAnimation() const
{
	return m_animation.getFinishAnimation();
}
ANIMATION_STATES GameObj::getAnimationState()
{
	return m_animation.getAnimationState();
}
bool GameObj::getBlood() const
{
	return m_animation.getFinishBlood();
}
void GameObj::setBlood(bool vur)
{
	m_animation.SetBlood(vur);
}
//end getFinishAnimation

void GameObj::updateAnomations()
{
	m_animation.updateAnimations();
}//end updateAnomations

void GameObj::setAnimState(ANIMATION_STATES state)
{
	m_animation.setAnimState(state);
}//end setAnimState

void GameObj::setSpriteSize(sf::Vector2f size)
{
	m_animation.setSpriteSize(size);
}//end setSpriteSize
