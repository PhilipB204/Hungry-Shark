#include "Controller.h"
#include"Sounds.h"
#include"Text.h"
Controller::Controller()//Controller constructor 
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BPP), "Hungry_shark", sf::Style::Titlebar | sf::Style::Close),
    m_numOfLevel(1), m_currentView(0, m_window.getSize().y /2), m_menu(), winloose(false),
    m_exitMenu(false), m_levelended(false), m_clock(), m_parralexclock()
{
    m_window.setFramerateLimit(80);
    m_window.setVerticalSyncEnabled(true);

    m_playerView.reset(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
    m_playerView.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    m_forground.setTexture(Textures::instance().getTexture(FOREGROUND));
    m_forground.setPosition(-900.f, -300.f);
    m_forground.setScale(WINDOW_LONG / 1920.f, WINDOW_TALL / 1015.f);

    m_farground.setTexture(Textures::instance().getTexture(FARGROUND));
    m_farground.setPosition(-900.f, -300.f);
    m_farground.setScale(WINDOW_LONG / 1920.f, WINDOW_TALL / 1058.f);

    m_midground.setTexture(Textures::instance().getTexture(MIDGROUND));
    m_midground.setPosition(-900.f, -300.f);
    m_midground.setScale(WINDOW_LONG / 1920.f, WINDOW_TALL / 877.f);

    m_background.setTexture(Textures::instance().getTexture(SEA));
    m_background.setPosition(-900.f, -300.f);
    m_background.setScale(WINDOW_LONG / 1920.f, WINDOW_TALL / 1080);
 

      m_score.setFont(Textures::instance().getFont());
      m_score.setCharacterSize(60);
      m_score.setString("SCORE:");

      pause.setFont(Textures::instance().getFont());
      pause.setCharacterSize(40);
      pause.setString("PRESS any button on the keyboard to resume:");



      static sf::Texture pause;
      pause.loadFromFile("pause.png");
      m_pause.setTexture(pause);
      m_pause.setScale((75.f / m_pause.getLocalBounds().width), (75.f / m_pause.getLocalBounds().height));

      static sf::Texture explain;
      explain.loadFromFile("HelpMenu.png");
      m_explain.setTexture(explain);
      m_explain.setScale((1000.f / m_pause.getLocalBounds().width), (1000.f / m_pause.getLocalBounds().height));


      static sf::Texture gameHelp;
      gameHelp.loadFromFile("gamehelp.png");
      m_gameHelp.setTexture(gameHelp);
      m_gameHelp.setPosition(0,0);
      m_gameHelp.setScale((210.f / m_pause.getLocalBounds().width), (180.f / m_pause.getLocalBounds().height));


      static sf::Texture help;
      help.loadFromFile("hel.png");
      m_help.setTexture(help);
      m_help.setScale((75.f / m_help.getLocalBounds().width), (75.f / m_help.getLocalBounds().height));


}//end Controller constructor

void Controller::run()
{
   runMenu();
    runGame();
}//end run

void Controller::runGame()
{
    while (m_window.isOpen())
    {

        m_window.clear();
        this->handleView();
        this->draw();
        m_board->handleCollisions();
        m_board->update(m_clock.restart().asSeconds());
        m_board->updateLife(m_life, m_currentView);
        SetGameStats();
        gameEventHandle();
        m_window.display();

        if (checkLevelFinish())
            runGameOverMenu();


        if (m_board->getPlayer().getLifeBar().isEmpty())
        {
            m_board->getPlayer().getSprite().setTexture(Textures::instance().getTexture(BLOODY));
            m_board->getPlayer().setAnimState(BLOOD);
            m_board->getPlayer().setAcceleration(0);

            if (m_board->getPlayer().getFinishAnimation())
            {
                runGameOverMenu();

                break;
            }
        }
    }
}
   
  
         
    
//end runGame

void Controller::draw()
{
    
    m_window.clear();


        m_window.draw(m_background);
        m_window.draw(m_farground);
        m_window.draw(m_midground);
        m_window.draw(m_forground);




       m_board->draw(m_window);
 
       m_window.draw(m_pause);
       m_window.draw(m_help);
       m_window.draw(m_score);

       if ( !m_board->getPlayer().getLifeBar().isEmpty())
       {
           m_board->getPlayer().getLifeBar().setposition(m_currentView);
           m_board->getPlayer().getLifeBar().draw(m_window);
       }

       


}//end draw

void Controller::handleView()
{//set the view by the player posision

    if (m_board->getPlayer().getPosition().x + 10.f > m_window.getSize().x / pos && m_board->getPlayer().getPosition().x + 10.f<WINDOW_LONG)
    {
        if (m_board->getPlayer().getPosition().x < WINDOW_LONG)
            m_currentView.x = m_board->getPlayer().getPosition().x + 0.5f;
    
    }
    else if (m_board->getPlayer().getPosition().x - 10.f < m_window.getSize().x / pos)
    {
        if (m_board->getPlayer().getPosition().x > 0)
            m_currentView.x = m_board->getPlayer().getPosition().x - 0.5f;
        else
            m_currentView.x = WINDOW_LONG;
    }
    else
        m_currentView.x = (float)m_window.getSize().x / pos;
 

    if (m_board->getPlayer().getPosition().y + 10.f > m_window.getSize().y / 2  )
    {
        if (m_board->getPlayer().getPosition().y < WINDOW_TALL)
            m_currentView.y = m_board->getPlayer().getPosition().y + 0.5f;

        else if (m_board->getPlayer().getPosition().y > 0 )
            m_currentView.x = m_board->getPlayer().getPosition().y - 0.5f;
        else
            m_currentView.y = WINDOW_TALL;
    }
    else
        m_currentView.y = (float)m_window.getSize().y / 2;

    m_playerView.setCenter(m_currentView);
    m_window.setView(m_playerView);
      
    
}//end handleView

void Controller::runMenu()
{//print menu,and wait until user press button
    sf::Music song;
    song.openFromFile("music.wav");
    song.setVolume(50);
    song.play();
 
    while (m_window.isOpen())
    {
        m_window.clear();
        m_menu.draw(m_window);
        m_window.display();

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (sf::Event::MouseMoved)
            {
                auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                m_menu.handleMouse(location);
            }

            if (sf::Event::MouseButtonReleased)
            {
                auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                auto answer = m_menu.whoIsPressed(location);
                if (answer == Start)
                {
              
                    m_board = std::make_unique<Board>();
                    return;
                }

                    if (answer == Help)
                    {
                        while (!isKeyPressed())
                        {
                            runHelp();

                        }
                      
                    }
                    if (answer == Exit)
                        m_window.close();
                }
            }
        }


    }


   
//end runMenu

void Controller::menuDuring()
{//print menu during the game 

    
}
bool Controller::Pause()
{
    return true;
}
bool Controller::isKeyPressed()
{
        for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
        {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
                return true;
        }
        return false;
    }
void Controller::setPress(sf::RenderWindow& window)
{
  
    window.draw(pause);
    window.draw(m_help);
    window.display();
  
}
void Controller::setHelp(sf::RenderWindow& window)
{
    window.draw(m_explain);
    window.draw(pause);
    window.display();
}

//end menuDuring


bool Controller::checkLevelFinish()
{
    if (m_board->checkFinish())
        return true;

    return false;
}

void Controller::runGameOverMenu()
{
    m_currentView.x = m_window.getSize().x-930.f;
    m_currentView.y = m_window.getSize().y-550.f;
    m_playerView.setCenter(m_currentView);
     m_window.setView( m_playerView);
 
     m_clock.restart();
     if(m_board->checkFinish())
     winloose = m_board->checkWin();

     m_board->clearVectors();
  
    while (m_window.isOpen())
    {

        m_window.clear();
        m_gameovermenu.drawFinal(m_window,winloose);
        m_window.display();

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (sf::Event::MouseMoved)
            {
                auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                m_menu.handleMouse(location);
            }

            if (sf::Event::MouseButtonReleased)
            {
                auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                auto answer = m_menu.whoIsPressed(location);

                if (answer == Start)
                {
                    m_board = std::make_unique<Board>();
                    if(m_clock.getElapsedTime().asSeconds()>=1.f)
                    runGame();
                  //  return;
                }


                if (answer == Help)
                {
                    runHelp();
                   
                }

                if (answer == Exit)
                    m_window.close();
            }
        }
    }


}





void Controller::restartLevel()
{
    m_board->restartLevel();
    this->ClockRestart();
}
void Controller::runHelp()
{
    m_window.clear();
    m_window.draw(m_gameHelp);
    pause.setPosition(m_gameHelp.getPosition().x+320.f , m_gameHelp.getPosition().y+630.f);
    m_window.draw(pause);
    m_window.display();
}



void Controller::ClockRestart()
{
    m_clock.restart();
 
}//end clocksResrtart

void Controller::help()
{
    (m_currentView.x) ? m_help.setPosition(m_currentView.x - 800.f, 100.f) : m_help.setPosition(m_currentView.x + 150.f, 100.f);
    while (true)
    {
        m_window.draw(m_help);
        m_window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
    }
}//end help




void Controller::gameEventHandle()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::KeyReleased:
        {
          
            break;
        }
        case sf::Event::MouseButtonReleased:
        {
            auto location = m_window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (m_pause.getGlobalBounds().contains(location))
            {
                while (!isKeyPressed())
                {
                    m_clock.restart();
                    setPress(m_window);
                }
             }

            if (m_help.getGlobalBounds().contains(location))
            {
                while (!isKeyPressed())
                {
                    m_clock.restart();
                    setHelp(m_window);
                }
            }
        }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
     //   menuDuring();
       // clockRestart();
    }
}




void Controller::SetGameStats()
{
    std::string str;
    str = "Score: ";
    str.append(std::to_string(m_board->getPlayer().GetScore())) ;
    m_score.setString(str);
    m_score.setOutlineColor(sf::Color::Blue);
    m_score.setOutlineThickness(3.f);
    m_score.setColor(sf::Color::Red);
    m_score.setPosition(m_currentView.x-190.f, m_currentView.y-500.f);
    pause.setPosition(m_currentView.x - 600.f, m_currentView.y);
    m_pause.setPosition(m_currentView.x-100.f, m_currentView.y - 420.f);
    m_help.setPosition(m_currentView.x+20.f , m_currentView.y - 420.f);
    m_explain.setPosition(m_currentView.x-700.f, m_currentView.y-600.f );
}
//end gameEventHandle
