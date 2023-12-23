#pragma once
#include <SFML/Graphics.hpp>

enum TexturesType {
	PLAYER, ENEMYSHARK, PERROTFISH, PUFFISH,UNPUFF, LIONFISH, NEMO, ORCHID, CRAB,CRAB2, JELLY, STONE,WATER,BUBBLE,SPAWN, FIRE, MINE,
	FOREGROUND, FARGROUND, MIDGROUND, SEA,EXPLOSION,BLOODY,MAP,LAST
};

enum SoundsType {SWIM,EAT,EXPLODING };

enum ANIMATION_STATES { IDLE, MOVING_LEFT, MOVING_RIGHT,MOVING_UP,MOVING_DOWN, STATIC,ONPLACE,EXPLODE,BLOOD,LEFT_UP
	,LEFT_DOWN,RIGHT_DOWN,RIGHT_UP,DIE,SPLASHY,SPAWNY};

const auto CPLAYER = 's';
const auto CESHARK = 'e';
const auto CPUFFISH = 'p';
const auto CLIONFISH = 'l';
const auto CPERROTFISH = 'r';
const auto CNEMO = 'n';
const auto CCRAB = 'c';
const auto CCRAB2 = 'b';
const auto CJELLY = 'j';
const auto CFIRE = 'f';
const auto CSTONE = 't';
const auto CMINE = 'm';
const auto CSPLASH = 'h';
const auto CORCHID = 'o';
const auto CEXPL = 'x';
const auto CSPAWN = 'z';

//-----------------Controller Consts-------------------
const auto WINDOW_WIDTH = sf::VideoMode::getFullscreenModes()[0].width;
const auto WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
const auto BPP = sf::VideoMode::getFullscreenModes()[0].bitsPerPixel;
const auto WINDOW_LONG = 8000.f;
const auto WINDOW_TALL = 3800.f;
const auto CUBESIZE = 100.f;
const auto EXPLSIZE = 500.f;

//---------------------Direction consts------------------
const auto LEFT = sf::Vector2f(-1, 0);
const auto RIGHT = sf::Vector2f(1, 0);
const auto UP = sf::Vector2f(0, -1);
const auto DOWN = sf::Vector2f(0, 1);
const auto STILL = sf::Vector2f(0, 0);

const auto LEFTUP = sf::Vector2f(-0.5, -0.5);
const auto LEFTDOWN = sf::Vector2f(-0.5, 0.5);
const auto RIGHTUP = sf::Vector2f(0.5,-0.5);
const auto RIGHTDOWN = sf::Vector2f(0.5,0.5);


//---------------------Button consts---------------------
const auto BUTTON_X = 235.f;
const auto BUTTON_Y = 150.f;
const auto BUTTON_HEIGHT = 6.F;
const auto BUTTON_WIDTH = 13.F;
const auto BUTTON_DISTANCE = 200.f;

//----------------------game data consts----------------


const auto BAR_LOC = sf::Vector2f(((float)(WINDOW_WIDTH / 3) + 20.f), (float)WINDOW_HEIGHT - 140.f);
const auto BAR_LOC_CHANGE_X = 350.f;
const auto BAR_LOC_CHANGE_Y = 450.f;

const auto NUM_OF_LIVES = 3;

//----------------------moveable consts----------------
auto const MAX_VELOCITY = 70.f;
auto const MIN_VELOCITY = 1.f;

auto const ACCELERATION = 15.f;
auto const ACCELERATION1 = 40.f;
auto const ACCELERATION2 = 50.f;
auto const ACCELERATION3 = 300.f;

auto const DECELERATION = 0.8f;


//----------------------Sprites & scales consts----------------

const auto PLAYER_SIZE = sf::Vector2f(227.9, 109);
const auto PLAYER_SCALE = sf::Vector2f(CUBESIZE / PLAYER_SIZE.x, CUBESIZE / PLAYER_SIZE.y);
const auto PLAYER_FRAME_END = sf::Vector2f(2000, 0);

const auto ESHARK_SIZE = sf::Vector2f(160,70);
const auto ESHARK_SCALE = sf::Vector2f((CUBESIZE ) / ESHARK_SIZE.x, (CUBESIZE ) / ESHARK_SIZE.y);
const auto ESHARK_FRAME_END = sf::Vector2f(1600, 0);


const auto PUFFISH_SIZE = sf::Vector2f(160, 115);
const auto PUFFISH_SCALE = sf::Vector2f(CUBESIZE / PUFFISH_SIZE.x, CUBESIZE / PUFFISH_SIZE.y);
const auto PUFFISH_FRAME_END = sf::Vector2f(1600, 0);


const auto PERROTFISH_SIZE = sf::Vector2f(175.4, 142);
const auto PERROTFISH_SCALE = sf::Vector2f(CUBESIZE / PERROTFISH_SIZE.x, CUBESIZE / PERROTFISH_SIZE.y);
const auto PERROTFISH_FRAME_END = sf::Vector2f(1600, 0);

const auto CRAB2_SIZE = sf::Vector2f(160, 77);
const auto CRAB2_SCALE = sf::Vector2f(CUBESIZE / CRAB2_SIZE.x, CUBESIZE / CRAB2_SIZE.y);
const auto CRAB2_FRAME_END = sf::Vector2f(1600, 0);


const auto LIONFISH_SIZE = sf::Vector2f(182.5 ,134);
const auto LIONFISH_SCALE = sf::Vector2f(CUBESIZE / LIONFISH_SIZE.x, CUBESIZE / LIONFISH_SIZE.y);
const auto LIONFISH_FRAME_END = sf::Vector2f(1800, 0);


const auto CRAB_SIZE = sf::Vector2f(160, 70);
const auto CRAB_SCALE = sf::Vector2f((CUBESIZE / CRAB_SIZE.x), (CUBESIZE )/ CRAB_SIZE.y);
const auto CRAB_FRAME_END = sf::Vector2f(1600, 0);

const auto NEMO_SIZE = sf::Vector2f(160, 93);
const auto NEMO_SCALE = sf::Vector2f(CUBESIZE / NEMO_SIZE.x, CUBESIZE / NEMO_SIZE.y);
const auto NEMO_FRAME_END = sf::Vector2f(1600, 0);

const auto ORCHID_SIZE = sf::Vector2f(160, 163);
const auto ORCHID_SCALE = sf::Vector2f(CUBESIZE / ORCHID_SIZE.x, CUBESIZE / ORCHID_SIZE.y);
const auto ORCHID_FRAME_END = sf::Vector2f(1600, 0);

const auto JELLY_SIZE = sf::Vector2f(129.2, 193);
const auto JELLY_SCALE = sf::Vector2f(CUBESIZE / JELLY_SIZE.x, CUBESIZE / JELLY_SIZE.y);
const auto JELLY_FRAME_END = sf::Vector2f(1200, 0);


const auto STONE_SIZE = sf::Vector2f(536, 465);
const auto STONE_SCALE = sf::Vector2f(CUBESIZE / STONE_SIZE.x, CUBESIZE/ STONE_SIZE.y);


const auto SPLASH_SIZE = sf::Vector2f(66, 77);
const auto SPLASH_SCALE = sf::Vector2f(CUBESIZE / SPLASH_SIZE.x, CUBESIZE / SPLASH_SIZE.y);
const auto SPLASH_FRAME_END = sf::Vector2f(330, 231);

const auto FIRE_SIZE = sf::Vector2f(112.5, 300);
const auto FIRE_SCALE = sf::Vector2f(CUBESIZE / FIRE_SIZE.x, CUBESIZE / FIRE_SIZE.y);
const auto FIRE_FRAME_END = sf::Vector2f(800, 0);


const auto EXPLOSION_SIZE = sf::Vector2f(200, 200);
const auto EXPLOSION_SCALE = sf::Vector2f(500.f / EXPLOSION_SIZE.x, 500.f / EXPLOSION_SIZE.y);
const auto EXPLOSION_FRAME_END = sf::Vector2f(1600, 1600);

const auto BLOOD_SIZE = sf::Vector2f(100, 100);
const auto BLOOD_SCALE = sf::Vector2f(150.f / BLOOD_SIZE.x, 150.f / BLOOD_SIZE.y);
const auto BLOOD_FRAME_END = sf::Vector2f(600, 600);

const auto SPAWN_SIZE = sf::Vector2f(400, 400);
const auto SPAWN_SCALE = sf::Vector2f(400.f / SPAWN_SIZE.x, 400.f / SPAWN_SIZE.y);
const auto SPAWN_FRAME_END = sf::Vector2f(2000, 800);

const auto MINE_SIZE = sf::Vector2f(200, 200);
const auto MINE_SCALE = sf::Vector2f(CUBESIZE / MINE_SIZE.x, CUBESIZE / MINE_SIZE.y);


const auto pos = 1.5;

const auto zero = 0;
