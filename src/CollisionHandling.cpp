
#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Collision.h"
#include"Textures.h"
#include"LifeBar.h"
#include <SFML/Audio.hpp>
#include"Enemy.h"

// base functions for the rest b

//charectors 
#include "Player.h"
#include "PerrotFish.h"
#include"PufFish.h"
#include"LionFish.h"
#include "Nemo.h"
#include "Orchid.h"
#include"Jelly.h" 
#include "EnemyShark.h"
#include"Crab.h"

//static
#include"Stone.h"
#include"Mine.h"
#include"Fire.h"
#include"Explode.h"


#include"Sounds.h"



namespace // anonymous namespace — the standard way to make function "static"
{

	template <typename objRef1, typename objRef2>
	sf::Vector2f collisionDirection(objRef1 first, objRef2 second)
	{//check the direction of the collision

		auto firstBounds = first.getSprite().getGlobalBounds();
		auto secondBounds = second.getSprite().getGlobalBounds();

		float object1_bottom = first.getPosition().y + firstBounds.height;
		float object2_bottom = second.getPosition().y + secondBounds.height;
		float object1_right = first.getPosition().x + firstBounds.width;
		float object2_right = second.getPosition().x + secondBounds.width;

		float b_collision = object2_bottom - first.getPosition().y;
		float t_collision = object1_bottom - second.getPosition().y;
		float l_collision = object1_right - second.getPosition().x;
		float r_collision = object2_right - first.getPosition().x;


		if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision)
			return DOWN;
		if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision)
			return UP;
		if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision)
			return LEFT;
		if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision)
			return RIGHT;
	}//end collisionDirection

	// primary collision-processing functions
	void PlayerStone(GameObj& playerobj, GameObj& stoneobj, sf::FloatRect& f)
	{
		Player& player = dynamic_cast<Player&>(playerobj);
		Stone& stone = dynamic_cast<Stone&>(stoneobj);

		auto playerBounds = player.getSprite().getGlobalBounds();
		auto stoneBounds = stone.getSprite().getGlobalBounds();

		if (Collision::PixelPerfectTest(player.getSprite(), stone.getSprite()))
			player.setPosition(player.GetLastLoc());
	}



	void PlayerFire(GameObj& playerobj, GameObj& fireobj, sf::FloatRect& f)
	{
		Fire& fire = dynamic_cast<Fire&>(fireobj);
		Player& player = dynamic_cast<Player&>(playerobj);
		if (Collision::PixelPerfectTest(player.getSprite(), fire.getSprite()) && !fire.getNeed2BDelete())
		{
			player.getSprite().setColor(sf::Color::Red);
		}
		else player.getSprite().setColor(sf::Color::White);
	}//end playerFire



	void PlayerEnemy(GameObj& playerobj, GameObj& sharko, sf::FloatRect& f)
	{
		Player& player = dynamic_cast<Player&>(playerobj);
		Enemy& shark = dynamic_cast<Enemy&>(sharko);
		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);

		if (shark.getBlood() && !shark.getNeed2BDelete())
		{
			shark.setNeed2BDelete();
			scale.x = abs(scale.x * 1.02f);
			scale.y = scale.y * 1.02;
			player.MakeBigger(scale);
		}

		if (Collision::PixelPerfectTest(player.getSprite(), shark.getSprite()) && !shark.getNeed2BDelete())
		{
			if (player.getSprite().getScale().x > shark.getSprite().getScale().x &&
				player.getSprite().getScale().y> shark.getSprite().getScale().y)
			{
				shark.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
				shark.setAnimState(BLOOD);
				shark.setAcceleration(0);
				player.Add2Score(1);
				player.setfeeding(true);

				if (player.IsFeeding())
				{
					player.getLifeBar().add();
					player.setfeeding(false);
				}
			}
			else if(!shark.getNeed2BDelete() && shark.getAnimationState()!=BLOOD)
				player.getLifeBar().reduce();
		}



	}

	void PlayerPuff(GameObj& playerobj, GameObj& puffish, sf::FloatRect& f)
	{
		PufFish& puf = dynamic_cast<PufFish&>(puffish);
		Player& player = dynamic_cast<Player&>(playerobj);
		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);
		if (puf.getBlood() && !puf.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.03f);
			scale.y = scale.y * 1.03;
			player.MakeBigger(scale);
			puf.setNeed2BDelete();
		}
		

		if (Collision::PixelPerfectTest(player.getSprite(), puf.getSprite()) && !puf.getNeed2BDelete())
		{
			puf.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			puf.setAnimState(BLOOD);
			puf.setAcceleration(0);
	        player.Add2Score(1);
			player.setfeeding(true);

			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.setfeeding(false);
			}

		}
	}
	

	void PlayerPerrot(GameObj& playerobj, GameObj& perrot, sf::FloatRect& f)
	{
		PerrotFish& per = dynamic_cast<PerrotFish&>(perrot);
		Player& player = dynamic_cast<Player&>(playerobj);

		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);
		if (per.getBlood() && !per.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.03f);
			scale.y = scale.y * 1.03f;
			player.MakeBigger(scale);
			//player.getLifeBar().add();
			//player.DecLifeTime();
			player.Add2Score(1);
			per.setNeed2BDelete();
		}
		
		if (Collision::PixelPerfectTest(player.getSprite(), per.getSprite()) && !per.getNeed2BDelete())
		{

			per.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			per.setAnimState(BLOOD);
			per.setAcceleration(0);
			player.Add2Score(1);
			player.setfeeding(true);
			Sounds::instance().PlaySound(EAT);
			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.setfeeding(false);
			}
		}
	}

	void PlayerLion(GameObj& playerobj, GameObj& lion, sf::FloatRect& f)
	{

		LionFish& lio = dynamic_cast<LionFish&>(lion);
		Player& player = dynamic_cast<Player&>(playerobj);
		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);

		if (lio.getBlood() && !lio.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.03f);
			scale.y = scale.y * 1.03f;
			player.MakeBigger(scale);
			lio.setNeed2BDelete();
		}
	
		if (Collision::PixelPerfectTest(player.getSprite(), lio.getSprite()) && !lio.getNeed2BDelete())
		{

			lio.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			lio.setAnimState(BLOOD);
			lio.setAcceleration(0);
			player.Add2Score(1);
			player.setfeeding(true);
			Sounds::instance().PlaySound(EAT);
			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.DecLifeTime();
				player.setfeeding(false);

			}


		}
	}


	void PlayerCrab(GameObj& playerobj, GameObj& crabo, sf::FloatRect& f)
	{
		Crab& crab = dynamic_cast<Crab&>(crabo);
		Player& player = dynamic_cast<Player&>(playerobj);

		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);


		if (crab.getBlood() && !crab.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			player.MakeBigger(scale);
			//player.getLifeBar().add();
		//	player.DecLifeTime();
			crab.setNeed2BDelete();
			Sounds::instance().PlaySound(EAT);
		
		}
		
		if (Collision::PixelPerfectTest(player.getSprite(), crab.getSprite()) && !crab.getNeed2BDelete())
		{

			crab.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			crab.setAnimState(BLOOD);
			crab.setAcceleration(0);
			player.Add2Score(1);
			player.setfeeding(true);
			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.DecLifeTime();
				player.setfeeding(false);
				Sounds::instance().PlaySound(EAT);
			}


		}

	
	}

	void PlayerNemo(GameObj& playerobj, GameObj& nemo, sf::FloatRect& f)
	{
		Nemo& nem = dynamic_cast<Nemo&>(nemo);
		Player& player = dynamic_cast<Player&>(playerobj);
		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);

		if (nem.getBlood() && !nem.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.04f);
			scale.y = scale.y * 1.04f;
			player.MakeBigger(scale);
			Sounds::instance().PlaySound(EAT);
			nem.setNeed2BDelete();
		}
		
		if (Collision::PixelPerfectTest(player.getSprite(), nem.getSprite()) && !nem.getNeed2BDelete())
		{
		
			nem.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			nem.setAnimState(BLOOD);
			nem.setAcceleration(0);
			player.Add2Score(1);
			player.setfeeding(true);
			Sounds::instance().PlaySound(EAT);
			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.DecLifeTime();
				player.setfeeding(false);
			}

			
		}
	}

	void PlayerOrchid(GameObj& playerobj, GameObj& orchid, sf::FloatRect& f)
	{
		Orchid& orch = dynamic_cast<Orchid&>(orchid);
		Player& player = dynamic_cast<Player&>(playerobj);
		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);

		if (orch.getBlood() && !orch.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.02f);
			scale.y = scale.y * 1.02;

			player.MakeBigger(scale);
			Sounds::instance().PlaySound(EAT);
			orch.setNeed2BDelete();
		}
		
		if (Collision::PixelPerfectTest(player.getSprite(), orch.getSprite()) && !orch.getNeed2BDelete())
		{
			orch.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			orch.setAnimState(BLOOD);
			player.Add2Score(1);
			player.setfeeding(true);
			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.DecLifeTime();
				player.setfeeding(false);
			}
		}
		

	}
	void PlayerMine(GameObj& playerobj, GameObj& mine, sf::FloatRect& f)
	{
		Mine& min = dynamic_cast<Mine&>(mine);
		Player& player = dynamic_cast<Player&>(playerobj);

		if (Collision::PixelPerfectTest(player.getSprite(), min.getSprite()) && !min.getNeed2BDelete())
		{
			player.getLifeBar().reduce();
			player.getSprite().setColor(sf::Color::Red);
			min.getSprite().setTexture(Textures::instance().getTexture(EXPLOSION));
			min.setAnimState(EXPLODE);
			Sounds::instance().PlaySound(EXPLODING);


		}
		else  player.getSprite().setColor(sf::Color::White);

	}
	void PlayerJelly(GameObj& playerobj, GameObj& jelly, sf::FloatRect& f)
	{
		Jelly& jel = dynamic_cast<Jelly&>(jelly);
		Player& player = dynamic_cast<Player&>(playerobj);

		sf::Vector2f scale(player.getSprite().getScale().x, player.getSprite().getScale().y);

		if (jel.getBlood() && !jel.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.05f);
			scale.y = scale.y * 1.05f;
			player.MakeBigger(scale);
			jel.setNeed2BDelete();
		}
		
		if (Collision::PixelPerfectTest(player.getSprite(), jel.getSprite()) && !jel.getNeed2BDelete())
		{

			jel.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			jel.setAnimState(BLOOD);
			jel.setAcceleration(0);
			player.Add2Score(1);
			player.setfeeding(true);
			Sounds::instance().PlaySound(EAT);

			if (player.IsFeeding())
			{
				player.getLifeBar().add();
				player.DecLifeTime();
				player.setfeeding(false);
			}
		}

	}

//---------------------------------------enemies vs the fish//////////
	///////////////////////////////
	void EnemyPuf(GameObj& enemy, GameObj& puf, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		PufFish& puff = dynamic_cast<PufFish&>(puf);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (puff.getBlood() && !puff.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			enem.MakeBigger(scale);
			puff.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), puff.getSprite()) && !puff.getNeed2BDelete())
		{

			puff.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			puff.setAnimState(BLOOD);
			puff.setAcceleration(0);
		}
    }

	void EnemyJely(GameObj& enemy, GameObj& jely, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		Jelly& jel = dynamic_cast<Jelly&>(jely);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (jely.getBlood() && !jely.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			enem.MakeBigger(scale);
			jel.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), jel.getSprite()) && !jely.getNeed2BDelete())
		{

			jel.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			jel.setAnimState(BLOOD);
			jel.setAcceleration(0);
		}
	}

	void EnemyPerrot(GameObj& enemy, GameObj& perrot, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		PerrotFish& per = dynamic_cast<PerrotFish&>(perrot);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (per.getBlood() && !per.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.02f);
			scale.y = scale.y * 1.02f;
			enem.MakeBigger(scale);
			per.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), per.getSprite()) && !per.getNeed2BDelete())
		{

			per.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			per.setAnimState(BLOOD);
			per.setAcceleration(0);

		}
	}

	void EnemyNemo(GameObj& enemy, GameObj& nemo, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		Nemo& nem = dynamic_cast<Nemo&>(nemo);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (nem.getBlood() && !nem.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			enem.MakeBigger(scale);
			nem.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), nem.getSprite()) && !nem.getNeed2BDelete())
		{
			nem.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			nem.setAnimState(BLOOD);
			nem.setAcceleration(0);

		}
	}

	void EnemyCrab(GameObj& enemy, GameObj& crabo, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		Crab& crab = dynamic_cast<Crab&>(crabo);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (crab.getBlood() && !crab.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			enem.MakeBigger(scale);
			crab.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), crab.getSprite()) && !crab.getNeed2BDelete())
		{
			crab.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			crab.setAnimState(BLOOD);
			crab.setAcceleration(0);


		}
	}

	void EnemyLion(GameObj& enemy, GameObj& lion, sf::FloatRect& f)
	{
		Enemy& enem = dynamic_cast<Enemy&>(enemy);
		LionFish& lio = dynamic_cast<LionFish&>(lion);

		sf::Vector2f scale(enem.getSprite().getScale().x, enem.getSprite().getScale().y);

		if (lio.getBlood() && !lio.getNeed2BDelete())
		{
			scale.x = abs(scale.x * 1.01f);
			scale.y = scale.y * 1.01f;
			enem.MakeBigger(scale);
			lio.setNeed2BDelete();
		}

		if (Collision::PixelPerfectTest(enem.getSprite(), lio.getSprite()) && !lio.getNeed2BDelete())
		{
			lio.getSprite().setTexture(Textures::instance().getTexture(BLOODY));
			lio.setAnimState(BLOOD);
			lio.setAcceleration(0);

		}
	}

	void EnemyMine(GameObj& enemy, GameObj& mine, sf::FloatRect& f)
	{
		Mine& min = dynamic_cast<Mine&>(mine);
		Enemy& enem = dynamic_cast<Enemy&>(enemy);


		if (min.getFinishAnimation() && !min.getNeed2BDelete() && !enem.getNeed2BDelete())
			if (min.getFinishAnimation())
			{
				min.setNeed2BDelete();
				enem.setNeed2BDelete();
			}


		if (Collision::PixelPerfectTest(enem.getSprite(), min.getSprite()) && !min.getNeed2BDelete() && !enem.getNeed2BDelete())
		{
			enem.setAnimState(BLOOD);
			enem.setAcceleration(0);
			min.getSprite().setTexture(Textures::instance().getTexture(EXPLOSION));
			min.setAnimState(EXPLODE);
			//Sounds::instance().PlaySound(EXPLODING);

		}

	}


}
	using HitFunctionPtr = void (*)(GameObj&, GameObj&, sf::FloatRect&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player), typeid(Stone))] = &PlayerStone;
		phm[Key(typeid(Player), typeid(Fire))] = &PlayerFire;
		phm[Key(typeid(Player), typeid(Mine))] = &PlayerMine;
		phm[Key(typeid(Player), typeid(PerrotFish))] = &PlayerPerrot;
		phm[Key(typeid(Player), typeid(PufFish))] = &PlayerPuff;
		phm[Key(typeid(Player), typeid(LionFish))] = &PlayerLion;
		phm[Key(typeid(Player), typeid(Nemo))] = &PlayerNemo;
		phm[Key(typeid(Player), typeid(Crab))] = &PlayerCrab;
		phm[Key(typeid(Player), typeid(Orchid))] = &PlayerOrchid;
		phm[Key(typeid(Player), typeid(Enemy))] = &PlayerEnemy;
		phm[Key(typeid(Player), typeid(Jelly))] = &PlayerJelly;
		//---------------------------------------------------------
		phm[Key(typeid(Enemy), typeid(PufFish))] = &EnemyPuf;
		phm[Key(typeid(Enemy), typeid(Jelly))] = &EnemyJely;
		phm[Key(typeid(Enemy), typeid(PerrotFish))] = &EnemyPerrot;
		phm[Key(typeid(Enemy), typeid(Nemo))] = &EnemyNemo;
		phm[Key(typeid(Enemy), typeid(Crab))] = &EnemyCrab;
		phm[Key(typeid(Enemy), typeid(LionFish))] = &EnemyLion;
		phm[Key(typeid(Enemy), typeid(Mine))] = &EnemyMine;


		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));

		if(mapEntry==collisionMap.end())
		return nullptr;
		
		return mapEntry->second;
	}

// end namespace

void processCollision(GameObj& object1, GameObj& object2, sf::FloatRect& f)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (phf)
	{
		phf(object1, object2, f);
	}
}



