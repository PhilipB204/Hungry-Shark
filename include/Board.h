#pragma once
//required to run
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include"CollisionHandling.h"
#include"Splash.h"
#include<vector>

// base functions for the rest 
#include"GameObj.h"
#include"macros.h"
#include "Textures.h"
#include "Static.h"
#include"Moveable.h"
#include"Enemy.h"
#include"Animation.h"
#include"Gamestats.h"
#include"Text.h"
#include"LifeBar.h" 
#include"Spawn.h"

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
#include"Gamestats.h"

class Controller;

class Board
{
public:
	Board();
	bool    loadLevel(int numOfLevel, bool loadFile);
	bool    loadLevelFromFile(int numOfLevel);
	void    draw(sf::RenderWindow& window);
	void    restartLevel();
	void    update(float dt = 0);
	Player& getPlayer();
	void    clearVectors();
	void handleCollisions();
	bool checkFinish();
	bool checkWin();
;

	void    updateLife(sf::Clock& clock, sf::Vector2f pos);

	

	sf::Sprite createSprite(TexturesType type, sf::Vector2f objectIndex);

private:

	std::ifstream                         m_file;
	sf::RectangleShape                    m_backGroundRec;
	std::unique_ptr <Player>              m_player;
	std::vector <std::unique_ptr<Static>> m_static;
	std::vector <std::unique_ptr<Moveable>>  m_fish;
	std::vector <std::unique_ptr<Enemy>>  m_enemies;
	std::vector <std::vector<char>>       m_levelBoard;//to load the level once, and than we will be able to restart level from vector
	float m_lifetime;
	sf::Sprite m_pause;
	bool winloose;

};

