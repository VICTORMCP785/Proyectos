#include "CchatSFML.h"

CchatSFML::CchatSFML(): m_Window(sf::VideoMode(1000, 1000), "SFML Application"), m_Player()
{
		m_Player.setRadius(40.f);
		m_Player.setPosition(100.f, 100.f);
		m_Player.setFillColor(sf::Color::Cyan);

}

CchatSFML::~CchatSFML()
{

}
