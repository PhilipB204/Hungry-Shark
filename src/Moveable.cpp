#include "Moveable.h"
#include"Textures.h"
Moveable::Moveable(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale)
	: GameObj(sprite, size, scale), m_dead(false),m_isfish(true)
{
	m_blood.setTexture(Textures::instance().getTexture(BLOODY));
	m_blood.setScale(BLOOD_SCALE);
	initPhysics();
}
Moveable::~Moveable()
{
}
//end constructor

void Moveable::setDirection(sf::Vector2f dic)
{
	m_direction = dic;
}//end setDirection

const sf::Vector2f& Moveable::getDirection() const
{
	return m_direction;
}//end getDirection

void Moveable::draw(sf::RenderWindow& window)
{
	
	window.draw(getSprite());
}//end draw


void Moveable::setDead(bool status)
{
	m_dead = status;
}

bool Moveable::GetDead()
{
	return m_dead;
}


//end move

void Moveable::update(float dt)
{

	updateMovement(dt);
	updateAnomations();
	updatePhysics(dt);
	//moveFish(dt);

}
bool Moveable::canMove(float speed, const sf::Vector2f& direction)
{
	if (getPosition().x + getSize().x + direction.x * speed > (float)6000)
		return false;

	if (getPosition().x + direction.x * speed < 0)
		return false;

	if (getPosition().y + getSize().y + direction.y * speed > (float)3000)
		return false;

	if (getPosition().y + direction.y * speed < 0)
		return false;

	return true;

}
void Moveable::SetLastLoc(sf::Vector2f loc)
{
	m_lastLocation = loc;
}
void Moveable::SetFishDirection()
{

	if (m_clock.getElapsedTime().asSeconds() > 2  )
	{
		m_clock.restart();

		
		int	side = rand() % 8;
			switch (side)
			{
			case 0://right

				setDirection(sf::Vector2f(1, 0));
				break;

			case 1://left
				setDirection(sf::Vector2f(-1, 0));
				break;

			case 2://up
				setDirection(sf::Vector2f(0, -1));
				break;

			case 3://down
				setDirection(sf::Vector2f(0, 1));
				break;

			case 4://right up

				setDirection(sf::Vector2f(0.5, -0.5));
				break;

			case 5://left up
				setDirection(sf::Vector2f(-0.5, -0.5));
				break;

			case 6://right down
				setDirection(sf::Vector2f(0.5, 0.5));
				break;

			case 7://left down
				setDirection(sf::Vector2f(-0.5, 0.5));
				break;
			}
		
	}

}

void Moveable::SetCrastationDirection()
{

	if (m_clock.getElapsedTime().asSeconds() > 2)
	{
		m_clock.restart();


		int	side = rand() % 2;
		switch (side)
		{
		case 0://right

			setDirection(sf::Vector2f(1, 0));
			break;

		case 1://left
			setDirection(sf::Vector2f(-1, 0));
			break;


		}

	}
}

void Moveable::setisfish(bool isit)
{
	m_isfish == isit;
}
bool Moveable::getisfish() 
{
	return m_isfish;
}
void Moveable::initPhysics()
{
	m_acceleration = ACCELERATION;
	m_deccelaration = DECELERATION;
}
void Moveable::updatePhysics(float dt)
{

	m_velocity *= m_deccelaration;
	if(this->GetAcceleration()!=0)
	getSprite().move(m_velocity);
}
void Moveable::move(float dt)
{
	m_velocity.x += m_acceleration * m_direction.x * dt;
	m_velocity.y += m_acceleration * m_direction.y * dt;
}
sf::Vector2f Moveable::getVelocity() const
{
	return m_velocity;
}
void Moveable::setVelocityX(float x)
{
	m_velocity.x = x;
}
void Moveable::setVelocityY(float y)
{
	m_velocity.y = y;
}
void Moveable::setAcceleration(float ac)
{
	m_acceleration = ac;
}
float Moveable::GetAcceleration()
{
	return m_acceleration;
}
void Moveable::moveFish(float dt)
{

	//float speed = 30 * dt;
	SetLastLoc(getPosition());
	if (canMove(m_acceleration, getDirection()))
	{
		auto location = sf::Vector2f(getPosition().x + dt * getDirection().x,
			getPosition().y + dt * getDirection().y);

		if (location.x >= (float)WINDOW_LONG)
			setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

		if (location.y >= (float)WINDOW_TALL)
			setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction

		if (location.x <= 0)
			setDirection(sf::Vector2f(getDirection().x * -1, 0));//Reverse the direction

		if (location.y <= 0)
			setDirection(sf::Vector2f(0, getDirection().y * -1));//Reverse the direction
	
	}
}
//end update



