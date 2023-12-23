#pragma once
#include "Moveable.h"
#include"LifeBar.h"
#include "Sounds.h"

class Player :public Moveable {

public:
	Player(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale);
	virtual void   updateMovement(float dt) override;
	void move(float dt);
	void initPhysics();
	
	virtual ~Player();
	void SetDirection(sf::Vector2f dic);
	sf::Vector2f GetDirection();
	void   updatePhysics(float dt);
	void SetLastLoc(sf::Vector2f);
	sf::Vector2f GetLastLoc();
	bool CanMove(float speed, const sf::Vector2f& direction);
	float getLifeTime();

	void Add2Score(int);
	int GetScore() const ;
	void setLifeTime(float);
	void changeAcceleration(float );

	void DecLifeTime();


	LifeBar & getLifeBar();
	float getfood();
	bool IsFeeding();
	void setfeeding(bool);

private:
	sf::Vector2f m_direction;
	float m_acceleration;
	float m_deccelaration;
	sf::Vector2f m_velocity;
	sf::Vector2f m_size;
	sf::Vector2f m_lastloc;
	float m_LifeTime;
	bool m_eat;
	std::unique_ptr<LifeBar> m_bar;
	float m_food ;
	bool m_feeding;
	int m_score;

};