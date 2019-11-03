#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "iostream"
#include <string>


class CchatSFML
{
public:
	CchatSFML();
	~CchatSFML();

private:

	sf::RenderWindow m_Window;
	sf::CircleShape  m_Player;
};