#include "Menu.h"


Menu::Menu() :m_background(), m_start(), m_exit(), m_help(),m_restart()
{
	static sf::Texture background;
	static sf::Texture start;
	static sf::Texture exit;
	static sf::Texture gameover;
	static sf::Texture help;
	static sf::Texture restart;
	static sf::Texture win;
	static sf::Texture logo;
	static sf::Texture helpmenu;
	static sf::Texture gamehelp;

	background.loadFromFile("startmenu.png");
	start.loadFromFile("start.png");
	help.loadFromFile("help.png");
	exit.loadFromFile("exit.png");
	win.loadFromFile("bikini1.png");
	gameover.loadFromFile("bikini2.png");
	restart.loadFromFile("restart.png");
	logo.loadFromFile("logo_shark.png");
	helpmenu.loadFromFile("HelpMenu.png");
	
	m_background.setTexture(background);
	m_background.setScale((BACKGROUNDSIZE.x / m_background.getLocalBounds().width), (BACKGROUNDSIZE.y / m_background.getLocalBounds().height));
	m_background.setPosition(sf::Vector2f(0, 0));


	m_logo.setTexture(logo);
	m_logo.setScale((600.f / m_logo.getLocalBounds().width), (600.f/ m_logo.getLocalBounds().height));
	m_logo.setPosition(BACKGROUNDSIZE.x / 2-300.f , (BACKGROUNDSIZE.y / 2)-500.f);

	m_start.setTexture(start);
	m_start.setScale((BUTTON_SIZE.x / m_start.getLocalBounds().width), (BUTTON_SIZE.y / m_start.getLocalBounds().height));
	m_start.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2));

	m_restart.setTexture(restart);
	m_restart.setScale((BUTTON_SIZE.x / m_restart.getLocalBounds().width), (BUTTON_SIZE.y / m_restart.getLocalBounds().height));
	m_restart.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2));

	m_help.setTexture(help);
	m_help.setScale((BUTTON_SIZE.x / m_help.getLocalBounds().width), (BUTTON_SIZE.y / m_help.getLocalBounds().height));
	m_help.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2 + 5.0f) + BUTTON_SIZE.y);

	m_exit.setTexture(exit);
	m_exit.setScale((BUTTON_SIZE.x / m_exit.getLocalBounds().width), (BUTTON_SIZE.y / m_exit.getLocalBounds().height));
	m_exit.setPosition(BACKGROUNDSIZE.x / 2 - (BUTTON_SIZE.x / 2), (BACKGROUNDSIZE.y / 2 + 130.0f) + BUTTON_SIZE.y);

	m_helpMenu.setTexture(helpmenu);
	m_helpMenu.setScale((BACKGROUNDSIZE.x / m_helpMenu.getLocalBounds().width), (BACKGROUNDSIZE.y / m_helpMenu.getLocalBounds().height));
	m_helpMenu.setPosition(sf::Vector2f(0, 0));

	m_GameOver.setTexture(gameover);
	m_GameOver.setScale((BACKGROUNDSIZE.x / m_GameOver.getLocalBounds().width), (BACKGROUNDSIZE.y / m_GameOver.getLocalBounds().height));
	m_GameOver.setPosition(sf::Vector2f(0, 0));

	m_Win.setTexture(win);
	m_Win.setScale((BACKGROUNDSIZE.x / m_Win.getLocalBounds().width), (BACKGROUNDSIZE.y / m_Win.getLocalBounds().height));
	m_Win.setPosition(sf::Vector2f(0, 0));


	m_win.setFont(Textures::instance().getFont());
	m_win.setCharacterSize(40);
	m_win.setString("You have Won, Go play another Game");
	m_win.setOutlineColor(sf::Color::Yellow);
	m_win.setOutlineThickness(3.f);
	m_win.setColor(sf::Color::Red);
	m_win.setPosition((BACKGROUNDSIZE.x / 2) - 600.0f, (BACKGROUNDSIZE.y / 2 - 400.0f) + BUTTON_SIZE.y);
	

	m_loose.setFont(Textures::instance().getFont());
	m_loose.setCharacterSize(60);
	m_loose.setString("You have lost, Another shark beat you");
	m_loose.setOutlineColor(sf::Color::Yellow);
	m_loose.setOutlineThickness(3.f);
	m_loose.setColor(sf::Color::Red);
	m_loose.setPosition((BACKGROUNDSIZE.x / 2 )-600.0f, (BACKGROUNDSIZE.y / 2 - 400.0f) + BUTTON_SIZE.y);
	
}



void Menu::handleMouse(const sf::Vector2f& location)
{
	{
		if (m_start.getGlobalBounds().contains(location))
			m_start.setColor(sf::Color::Green);

		else if (m_help.getGlobalBounds().contains(location))
			m_help.setColor(sf::Color::Yellow);

		else if (m_exit.getGlobalBounds().contains(location))
			m_exit.setColor(sf::Color::Red);
		else
		{
			m_start.setColor(sf::Color::White);
			m_help.setColor(sf::Color::White);
			m_exit.setColor(sf::Color::White);
		}

	}
}

void Menu::draw(sf::RenderWindow& window) const
{
	window.draw(m_background);
	window.draw(m_start);
	window.draw(m_help);
	window.draw(m_exit);
	window.draw(m_logo);
}

void Menu::drawFinal(sf::RenderWindow& window,bool current) const
{
	if (current)
	{
		window.draw(m_Win);
		window.draw(m_win);
		window.draw(m_exit);
	}
	else
	{

		window.draw(m_GameOver);
		window.draw(m_loose);
		window.draw(m_restart);
		window.draw(m_exit);
	}

}



void Menu::drawHelp(sf::RenderWindow& window) const
{
	window.draw(m_helpMenu);
}

Button Menu::whoIsPressed(const sf::Vector2f& location)
{
	if (m_start.getGlobalBounds().contains(location))
		return Start;

	else if (m_help.getGlobalBounds().contains(location))
		return Help;

	else if (m_exit.getGlobalBounds().contains(location))
		return Exit;
	else
		return Nothing;
}

sf::Sprite& Menu::GetSprite()
{
	return m_GameOver;
}


