#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

const enum stats { SCORE, LIFE };

class Gamestats
{
public:
	Gamestats( sf::Font font);
	void setstring(std::string str, int data);
	void changeColor(const sf::Color& color, stats kind);
	void draw(sf::RenderWindow& window) ;
	void setposition(sf::Vector2f pos);

private:
	Text m_score;
	
};

