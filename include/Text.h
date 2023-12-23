#pragma once
#include <SFML/Graphics.hpp>


class Text {
public:
	Text( sf::Font& font);
	void drawo(sf::RenderWindow& window)  ;
	void setcolor(const sf::Color& color);
	void setText(std::string str);
	void setPosition(const sf::Vector2f& location);
	void setCharSize(int size);

private:
	sf::Text m_text;
};