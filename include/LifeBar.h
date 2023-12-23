#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "macros.h"

const auto recs = 50;//the time of life, 
const auto FRAME_SIZE = 60;

class LifeBar {
public:
	LifeBar();
	void setposition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	bool isEmpty();
	void reduce();
	void add();

private:
	std::vector<sf::RectangleShape> m_rectangles; //each half second get a rectangle
	sf::RectangleShape m_frame;
};
