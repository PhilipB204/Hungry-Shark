#include "LifeBar.h"

LifeBar::LifeBar()
{//sets the frame size and num of rectangles
	m_frame.setSize(sf::Vector2f(FRAME_SIZE *10 ,50));
	m_frame.setFillColor(sf::Color::Transparent);
	m_frame.setOutlineThickness(5.f);
	m_frame.setOutlineColor(sf::Color::Blue);

	auto rec = sf::RectangleShape(sf::Vector2f(3, 48));
	rec.setFillColor(sf::Color::Red);

	for (auto i = 0; i < recs * 2; ++i)
	{
		m_rectangles.push_back(rec);
	}
}//end constructor 

void LifeBar::setposition(sf::Vector2f pos)
{
	float x = pos.x - BAR_LOC_CHANGE_X;
	float y = pos.y + BAR_LOC_CHANGE_Y;
	m_frame.setPosition(sf::Vector2f(x, y));
	for (auto& rectangl : m_rectangles)
	{
		rectangl.setPosition(sf::Vector2f(x + 1.f, y + 1.f));
		x += 6.1f;
	}
}//end setposition 

void LifeBar::draw(sf::RenderWindow& window)
{
	window.draw(m_frame);
	for (auto& rec : m_rectangles)
		window.draw(rec);
}//end draw 

bool LifeBar::isEmpty()
{
	return m_rectangles.empty();
}//end isEmpty 

void LifeBar::reduce()
{
	if(!m_rectangles.empty())
		m_rectangles.pop_back();
}
void LifeBar::add()
{
	if (m_rectangles.size() <=99)
	{
		auto rec = sf::RectangleShape(sf::Vector2f(3,48));
		rec.setFillColor(sf::Color::Red);
		m_rectangles.push_back(rec);
	}
}
//end reduce 

