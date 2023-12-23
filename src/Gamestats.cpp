#include <SFML/Graphics.hpp>
#include"Gamestats.h"
#include<iostream>


Gamestats::Gamestats(sf::Font font) :
	m_score(font)
	
{
	setstring("Score:", 0);
	m_score.setCharSize(10);
	
}//end game stats

void Gamestats::setstring(std::string str, int data)
{

		str.append(std::to_string(data));//attach int data to the string
		m_score.setText(str);
	
}//end setstring

void Gamestats::changeColor(const sf::Color& color, stats kind)
{
	
m_score.setcolor(color);
	

}//end changeColor

void Gamestats::draw(sf::RenderWindow& window) 
{
	m_score.drawo(window);
}
void Gamestats::setposition(sf::Vector2f pos)
{

	sf::Vector2f position(pos.x + 50.f, pos.y + 50.f);
	m_score.setPosition(pos);

}
//end draw
