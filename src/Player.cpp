#include "Player.h"



Player::Player(const sf::Sprite& sprite, sf::Vector2f size, sf::Vector2f scale) :Moveable(sprite, size, scale), m_LifeTime(10.f), m_food(1.f), m_score(0)
, m_feeding(false)
{
	setFrameEnd(PLAYER_FRAME_END);
	this->setisfish(true);
	initPhysics();
	m_bar = std::make_unique<LifeBar>();

}
void Player::updateMovement(float dt)
{
	static bool released = true;
	bool keyPressed = false;//for the sounds - stop sound if nothing pressed
	SetDirection(STILL);
	SetLastLoc(this->getPosition());
	bool blood = false;

	if (this->getAnimationState() == BLOOD)
		blood = true;
	if(this->getAnimationState()!=BLOOD)
	setAnimState(ONPLACE);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			keyPressed = true;

			SetDirection(LEFT);
			setAnimState(MOVING_LEFT);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			keyPressed = true;

			SetDirection(RIGHT);
			setAnimState(MOVING_RIGHT);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			keyPressed = true;

			SetDirection(DOWN);
			setAnimState(MOVING_DOWN);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (released)
			{
				keyPressed = true;

				SetDirection(UP);
				setAnimState(MOVING_UP);
				updateAnomations();
				if (CanMove(m_acceleration, this->getDirection()))
					move(dt);

			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			keyPressed = true;
			SetDirection(RIGHTUP);

			setAnimState(RIGHT_UP);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			keyPressed = true;

			SetDirection(RIGHTDOWN);
			setAnimState(RIGHT_DOWN);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			keyPressed = true;

			SetDirection(LEFTDOWN);
			setAnimState(LEFT_DOWN);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			keyPressed = true;

			SetDirection(LEFTUP);
			setAnimState(LEFT_UP);
			updateAnomations();
			if (CanMove(m_acceleration, this->getDirection()))
				move(dt);

		}
		

	
	updateAnomations();
	if(!blood)
	updatePhysics(dt);
	
	
}

void Player::move(float dt)
{
	m_velocity.x += m_acceleration * m_direction.x * dt;
	m_velocity.y += m_acceleration * m_direction.y * dt;
}

void Player::initPhysics()
{
	m_acceleration = ACCELERATION2;
	m_deccelaration = DECELERATION;
}





Player::~Player()
{
}

void Player::SetDirection(sf::Vector2f dic)
{
	m_direction = dic;
}

sf::Vector2f Player::GetDirection()
{
	return m_direction;
}

void Player::updatePhysics(float dt)
{
	m_velocity *= m_deccelaration;

	getSprite().move(m_velocity);
}

void Player::SetLastLoc(sf::Vector2f thisone)
{
	m_lastloc = thisone;
}

sf::Vector2f Player::GetLastLoc()
{

	return m_lastloc;
}

bool Player::CanMove(float speed, const sf::Vector2f& direction)
{
	if (getPosition().x + getSize().x + m_direction.x * speed > (float)6000.f)
		return false;

	if (getPosition().x + m_direction.x * speed < 0)
		return false;

	if (getPosition().y + getSize().y + m_direction.y * speed > (float)3000.f)
		return false;

	if (getPosition().y + m_direction.y * speed < 0)
		return false;

	return true;
	
}

float Player::getLifeTime()
{
	return m_LifeTime;
}

void Player::Add2Score(int amount)
{
	m_score+=amount; 
}

int Player::GetScore() const
{
	return m_score;
}

void Player::setLifeTime(float time)
{
	m_LifeTime = time;
}

void Player::changeAcceleration(float ace)
{
	m_acceleration = ace;
}

void Player::DecLifeTime()
{
	if (m_food > 0.2f)
		m_food = -00.1f;
	else m_food = 0.2f;

}



LifeBar& Player::getLifeBar()
{
	return (*m_bar.get());
}

float Player::getfood()
{
	return m_food;
}

bool Player::IsFeeding()
{
	return m_feeding;
}

void Player::setfeeding(bool current)
{
	m_feeding = current;
}

