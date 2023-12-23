#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "Menu.h"
#include <vector>
#include <string>
#include"macros.h"
#include"LifeBar.h"
#include "Sounds.h"

const auto FIRSTLEVEL = 1;
enum gameStatus { Failed, Finish };//if game is finish succesfull or died during.

class Controller {
public:
	Controller();
	void run();
private:
	//------------private function-------------------------
	void runGame();
	void draw();
	void handleView();
	void runMenu();
	void menuDuring();
	bool Pause();
	bool isKeyPressed();
	void setPress(sf::RenderWindow& window);
	void setHelp(sf::RenderWindow& window);
	bool checkLevelFinish();
	void runGameOverMenu();
	void restartLevel();
	void runHelp();


	//void handleButtonsPress(ButtonName button);
	void ClockRestart();
	void help();

	void gameEventHandle();
	void SetGameStats();
	//------------private members-------------------------
	sf::RenderWindow m_window;
	std::unique_ptr<Board> m_board;

	sf::Sprite m_background;
	sf::Sprite m_farground;
	sf::Sprite m_forground;
	sf::Sprite m_midground;

	Menu m_menu;
	Menu m_gameovermenu;
	//Menu m_duringMenu;
	//Menu m_gameoverMenu;
	sf::View m_playerView;
	int m_numOfLevel;
	sf::Vector2f m_currentView;
	bool m_exitMenu;
	bool m_levelended;
	sf::Clock m_clock;
	sf::Text m_score;
	sf::Text pause;
	sf::Sprite m_pause;
	sf::Sprite m_explain;
	sf::Sprite m_help;
	sf::Sprite m_gameHelp;
	sf::Clock m_life;
	sf::Clock m_parralexclock;
	bool winloose;
};


