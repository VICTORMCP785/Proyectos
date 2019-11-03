#include "Game.h"

Game::Game() 
: m_Window(sf::VideoMode(1000, 1000), "SFML Application"), 
m_Player() 
{    
	m_Player.setRadius(40.f);    
	m_Player.setPosition(100.f, 100.f);
	m_Player.setFillColor(sf::Color::Cyan); 
} 

void Game::run() 
{    
	sf::Clock clock;    
	while (m_Window.isOpen()) 
	{ 
		sf::Time deltaTime = clock.restart();        
		processEvents();        
		update(deltaTime);        
		render(); 
	}
} 

void Game::processEvents()
{
	sf::Event event;    
	while (m_Window.pollEvent(event)) 
	{
		switch (event.type) 
		{
			case sf::Event::TextEntered:
				//handlePlayerInput(event.key.code, true);                
				break;            
			//case sf::Event:::                
			//	//handlePlayerInput(event.key.code, false);                
			//	break;            
			case sf::Event::Closed:                
				m_Window.close();                
				break;
		}
	}
}

//void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) 
//{ 
//	if (key == sf::Keyboard::W)
//	{
//		mIsMovingUp = isPressed;
//	}
//	else if (key == sf::Keyboard::S)
//	{
//		mIsMovingDown = isPressed;
//	}
//	else if (key == sf::Keyboard::A)
//	{
//		mIsMovingLeft = isPressed;
//	}
//	else if (key == sf::Keyboard::D)
//	{
//		mIsMovingRight = isPressed;
//	}
//}

void Game::update(sf::Time deltaTime)
{

	/*sf::Vector2f movement(0.f, 0.f);    
	if (mIsMovingUp)        
		movement.y -= PlayerSpeed;    
	if (mIsMovingDown)        
		movement.y += PlayerSpeed;    
	if (mIsMovingLeft)        
		movement.x -= PlayerSpeed;    
	if (mIsMovingRight)        
		movement.x += PlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());*/
}

void Game::render()
{
	m_Window.clear();    
	m_Window.draw(m_Player);    
	m_Window.display();
}
