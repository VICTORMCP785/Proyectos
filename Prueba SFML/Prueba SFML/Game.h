#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "iostream"

class Game
{
public:
	Game();
	void run();

	/*bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;
	float PlayerSpeed = 500.0f;*/

private:

	void processEvents();
	//void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	void update(sf::Time);
	void render();

private:        

	sf::RenderWindow m_Window;        
	sf::CircleShape  m_Player;
};
