#include "Board.h"
#include"CollisionHandling.h"
#include"Collision.h" 
#include"macros.h"
Board::Board()
{

	loadLevel(1, true);
	static sf::Texture pause;
	pause.loadFromFile("puase.png");
	m_pause.setTexture(pause);
	m_pause.setScale((150.f / m_pause.getLocalBounds().width), (140.f/ m_pause.getLocalBounds().height));
	
	
	
}


bool Board::loadLevelFromFile(int numOfLevel)
{//load the level into char vector for easy restoration of the level - if needed
	m_levelBoard.clear();
	std::string fileName = "level1.txt";

	m_file.open(fileName);
	if (!m_file.is_open())
		return false;
	for (std::string line; std::getline(m_file, line);)
	{
		std::vector<char>  temp;//to read each line separately
		for (int k = 0; k < line.size(); k++)
		{
			temp.push_back(line[k]);
		}
		m_levelBoard.push_back(temp);
	}
	m_file.close();
	return true;
}//end loadLevelFromFile

bool Board::loadLevel(int numOfLevel, bool loadFile)
{
	if (loadFile)
		if (!loadLevelFromFile(numOfLevel))
			return false;
	sf::Vector2f mine(100.f, 100.f);
	for (auto i = 0; i < m_levelBoard.size(); ++i)//build the SFML representation from the board representation
	{
		for (auto j = 0; j < m_levelBoard[i].size(); ++j)//creating all objects---------------
		{
			sf::Vector2f objectIndex(j, i);//x = j, y = i
			char Symbol = m_levelBoard[i][j];
			switch (Symbol)
			{
			case CPLAYER:
			
				m_player = std::make_unique<Player>(createSprite(PLAYER, objectIndex), PLAYER_SIZE, PLAYER_SCALE);
				m_static.push_back(std::make_unique<Spawn>(createSprite(SPAWN, objectIndex), SPAWN_SIZE, SPAWN_SCALE));
				break;

			case CESHARK:
				m_enemies.push_back(std::make_unique<Enemy>(createSprite(ENEMYSHARK, objectIndex), ESHARK_SIZE, ESHARK_SCALE));
				
				break;

			case CPERROTFISH:
				m_fish.push_back(std::make_unique<PerrotFish>(createSprite(PERROTFISH, objectIndex), PERROTFISH_SIZE, PERROTFISH_SCALE));
				break;

			case CPUFFISH:
				m_fish.push_back(std::make_unique<PufFish>(createSprite(PUFFISH, objectIndex), PUFFISH_SIZE, PUFFISH_SCALE));
				break;

			case CLIONFISH:
				m_fish.push_back(std::make_unique<LionFish>(createSprite(LIONFISH, objectIndex), LIONFISH_SIZE, LIONFISH_SCALE));
				break;

			case CCRAB:
				m_fish.push_back(std::make_unique<Crab>(createSprite(CRAB, objectIndex), CRAB_SIZE, CRAB_SCALE));
				break;

			case CCRAB2:
				m_fish.push_back(std::make_unique<Crab>(createSprite(CRAB2, objectIndex), CRAB2_SIZE, CRAB2_SCALE));
				break;

			case CJELLY:
				m_fish.push_back(std::make_unique<Jelly>(createSprite(JELLY, objectIndex), JELLY_SIZE, JELLY_SCALE));
				break;

			case CNEMO:
				m_fish.push_back(std::make_unique<Nemo>(createSprite(NEMO, objectIndex), NEMO_SIZE, NEMO_SCALE));
				break;

			case CORCHID:
				m_static.push_back(std::make_unique<Orchid>(createSprite(ORCHID, objectIndex), ORCHID_SIZE, ORCHID_SCALE));
				break;

			case CSTONE:
				m_static.push_back(std::make_unique<Stone>(createSprite(STONE, objectIndex), STONE_SIZE, STONE_SCALE));
				break;

			case CFIRE:
				m_static.push_back(std::make_unique<Fire>(createSprite(FIRE, objectIndex), FIRE_SIZE, FIRE_SCALE));
				break;

			case CMINE:
				m_static.push_back(std::make_unique<Mine>(createSprite(MINE, objectIndex), MINE_SIZE, MINE_SCALE));
				break;

			case CSPLASH:
				m_static.push_back(std::make_unique<Splash>(createSprite(WATER, objectIndex), SPLASH_SIZE, SPLASH_SCALE));
				break;

			case CEXPL:
				m_static.push_back(std::make_unique<Explode>(createSprite(EXPLOSION, objectIndex), EXPLOSION_SIZE, EXPLOSION_SCALE));


			case CSPAWN:
				m_static.push_back(std::make_unique<Spawn>(createSprite(SPAWN, objectIndex), SPAWN_SIZE, SPAWN_SCALE));

			}
		}
	}

	for (auto& current : m_enemies)
	{
		auto one = m_player.get();
		current->SetEnemySpeed();
		current->setPlayer(dynamic_cast<Player*>(one));

	}
}//end loadLevel


void Board::restartLevel()
{
	

}//end restartLevel

sf::Sprite Board::createSprite(TexturesType type, sf::Vector2f objectIndex)
{//creating a sprite with TexturesType and position
	auto sprite = sf::Sprite(Textures::instance().getTexture(type));
	sprite.setPosition(objectIndex.x * CUBESIZE, objectIndex.y * CUBESIZE);
	return sprite;

	
}//end createSprite


void Board::update(float dt)
{//update all movement(movable) and animation(movable/static)
	for (auto& staticobj : m_static)
		if(!staticobj->getNeed2BDelete())
		staticobj->update(dt);

	for (auto& fish : m_fish)
		if(!fish->getNeed2BDelete())
	 	fish->update(dt);


	for (auto& enemy : m_enemies)
		if (!enemy->getNeed2BDelete())
			enemy->update(dt);
	m_player->updateMovement(dt);

	
}//end update

Player& Board::getPlayer()
{
	return *(m_player.get());
}//



template <typename FwdIt, typename FzdIt, typename Fn>
void for_each_pair(FwdIt begin1, FwdIt end1, FzdIt begin2, FzdIt end2, Fn fn)
{//template function checking each object from the first iterator sent, collision with all second iterator sent
	for (; begin1 != end1; ++begin1)
	{
		auto it = begin1;
		for (auto second2 = begin2; second2 != end2; ++second2)
			fn(*begin1, *second2);
	}
}//end for_each_pair

template <typename unique, typename FzdIt, typename Fn>
void for_each_pair_with_one(unique one, FzdIt begin2, FzdIt end2, Fn fn)
{//template function checking one object collision with iterator
	for (auto second2 = begin2; second2 != end2; ++second2)
		fn(one, *second2);
}


bool collide(GameObj& a, GameObj& b, sf::FloatRect& f)
{
	if (a.getSprite().getGlobalBounds().intersects(b.getSprite().getGlobalBounds(), f))
		return true;
	return false;
}//end collide

void Board::clearVectors()
{
	m_fish.clear();
	m_static.clear();
	m_player.get_deleter();
}
void Board::handleCollisions()
{
	static sf::FloatRect f;

	for_each_pair(m_fish.begin(), m_fish.end(), m_static.begin(), m_static.end(),
		[](auto& a, auto& b) {//fish vs static
			if (collide(*a, *b, f) )
				processCollision(*a, *b, f);
		});

	for_each_pair(m_enemies.begin(), m_enemies.end(), m_fish.begin(), m_fish.end(),
		[](auto& a, auto& b) {//sharks vs fish
			if (collide(*a, *b, f))
				processCollision(*a, *b, f);
		});

	for_each_pair_with_one(m_player.get(), m_fish.begin(), m_fish.end(),
		[](auto& a, auto& b) {//check player vs moveables
			if (collide(*a, *b, f) )
				processCollision(*a, *b, f);
		});

	for_each_pair_with_one(m_player.get(), m_static.begin(), m_static.end(),
		[](auto& a, auto& b) {//check player vs static
			if (collide(*a, *b, f))
				processCollision(*a, *b, f);
		});

			for_each_pair_with_one(m_player.get(), m_enemies.begin(), m_enemies.end(),
				[](auto& a, auto& b) {//check player vs static
					if (collide(*a, *b, f))
						processCollision(*a, *b, f);
				});

			for_each_pair(m_enemies.begin(), m_enemies.end(), m_static.begin(), m_static.end(),
				[](auto& a, auto& b) {//fish vs static
					if (collide(*a, *b, f))
						processCollision(*a, *b, f);
				});

					
	


}

bool Board::checkFinish()
{
	for (auto& moveableobj : m_enemies)
		if (!moveableobj->getNeed2BDelete())
			return false;
	return true;

}

bool Board::checkWin()
{
	for (auto& moveableobj : m_enemies)
		if(!moveableobj->getNeed2BDelete())
		if (moveableobj->getSprite().getScale().x > getPlayer().getSprite().getScale().x)
			return false;

	return true;

}

void Board::updateLife(sf::Clock& clock, sf::Vector2f pos)
{
	static float time;
	auto dt = clock.restart().asSeconds();
	auto LifeTime = m_player->getLifeTime() - dt;

	time += dt;
	m_player->getLifeBar().setposition(pos);

	if (time >= m_player->getfood())
	{
		m_player->getLifeBar().reduce();
		time = 0;
	}

}

void Board::draw(sf::RenderWindow& window)
{
	for (auto& staticobj : m_static)
		staticobj->draw(window);

	for (auto& moveableobj : m_fish)
		if(!moveableobj->getNeed2BDelete())
		moveableobj->draw(window);

	for (auto& enemyobj : m_enemies)
		if (!enemyobj->getNeed2BDelete())
			enemyobj->draw(window);

	m_player->draw(window);
}



//end draw