#pragma once

#include "GameObj.h"
#include "Animation.h"
#include "macros.h"
//#include "Sounds.h"
#include <iostream>

class Moveable : public GameObj {
public:
	Moveable(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual ~Moveable();
	void                setDirection(sf::Vector2f dic);
	const sf::Vector2f& getDirection() const;
	void virtual		draw(sf::RenderWindow& window) override;
	virtual void        updateMovement(float dt) = 0;
	virtual void		update(float dt) override;
	void                moveFish(float dt);
	bool canMove(float speed, const sf::Vector2f& direction);
	void SetLastLoc(sf::Vector2f);
	void SetFishDirection();
	void SetCrastationDirection();
	void setisfish(bool);
	bool getisfish()  ;
	void initPhysics();

	void                updatePhysics(float dt);
	void                move(float dt);

	sf::Vector2f        getVelocity() const;
	void                setVelocityX(float x);
	void                setVelocityY(float y);
	void                setAcceleration(float ac);
	float GetAcceleration();


	void setDead(bool status);
	bool GetDead();

private:

	sf::Vector2f m_velocity;
	float m_acceleration;
	float m_deccelaration;

	sf::Vector2f m_direction;
	sf::Vector2f m_lastLocation;
	sf::Clock m_clock;
	bool m_isfish;
	sf::Sprite m_blood;
	bool m_dead;

};