#include "Textures.h"

Textures::Textures()
{//constructor - load all Textures into the vector

	m_font.loadFromFile("font.ttf");

	m_textures[PLAYER].loadFromFile("Player.png");
	m_textures[ENEMYSHARK].loadFromFile("enemyshark.png");
	m_textures[PUFFISH].loadFromFile("puffish.png");
	m_textures[UNPUFF].loadFromFile("unpuff.png");
	m_textures[PERROTFISH].loadFromFile("perrotfish.png");
	m_textures[LIONFISH].loadFromFile("lionfish.png");
	m_textures[NEMO].loadFromFile("nemo.png");
	m_textures[CRAB].loadFromFile("crab.png");
	m_textures[CRAB2].loadFromFile("crab2.png");
	m_textures[JELLY].loadFromFile("jelly.png");
	m_textures[ORCHID].loadFromFile("orchid.png");
	m_textures[MINE].loadFromFile("mine.png");
	m_textures[FIRE].loadFromFile("fire.png");
	m_textures[STONE].loadFromFile("stone.png");
	m_textures[WATER].loadFromFile("watersplash.png");
	m_textures[BUBBLE].loadFromFile("bubble.png");
	m_textures[SPAWN].loadFromFile("spawn.png");
	m_textures[FARGROUND].loadFromFile("farground.png");
	m_textures[FARGROUND].loadFromFile("farground.png");
	m_textures[MIDGROUND].loadFromFile("mid_background.png");
	m_textures[SEA].loadFromFile("map.png");
	m_textures[EXPLOSION].loadFromFile("expl.png");
	m_textures[BLOODY].loadFromFile("blood.png");
	m_textures[LAST].loadFromFile("bikini1.png");

}//end constructor 

Textures& Textures::instance()
{//get the single Textures object
	static Textures tex;
	return tex;
}//end instance

const sf::Texture& Textures::getTexture(TexturesType kind)
{//return the texture according to sent simbolIndex
	if (int(kind) >= m_textures.size())
		throw std::out_of_range("getTexture is out of range");
	m_textures[kind].setSmooth(true);
	return m_textures[kind];
}//end getTexture


const sf::Font& Textures::getFont() const
{
	return m_font;
}//end getFont