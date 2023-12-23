#pragma once
#include <SFML/Graphics.hpp>
#include "textures.h"
#include "macros.h"
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "macros.h"


const sf::Vector2f BACKGROUNDSIZE(WINDOW_WIDTH, WINDOW_HEIGHT);
const sf::Vector2f BUTTON_SIZE(150, 140);
enum  Button { Start, Exit, Help, Nothing ,Restart};


class Menu {
public:
	Menu();
	void handleMouse(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;//draw the open screen
	void drawFinal(sf::RenderWindow& window,bool current) const;//draw the final(game over) screen
	void drawHelp(sf::RenderWindow& window) const;//draw the help screen
	Button whoIsPressed(const sf::Vector2f& location);
	sf::Sprite& GetSprite();


private:
	sf::Sprite m_start;
	sf::Sprite m_help;
	sf::Sprite m_exit;
	sf::Sprite m_background;
	sf::Sprite m_GameOver;
	sf::Sprite m_Win;
	sf::Sprite m_helpMenu;
	sf::Sprite m_restart;
	sf::Sprite m_logo;
	sf::Sprite m_gameHelp;

	sf::Text m_win;
	sf::Text m_loose ;
};