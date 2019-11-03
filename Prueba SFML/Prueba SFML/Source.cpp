#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp";
#include <string>
#include <iostream>


std::string Message_user()
{
	std::string MU;
	while (true)
	{		
		std::cout << "Introdusca Mensaje \n\nLimite de caracteres 255" << std::endl;
		std::cin >> MU;
		
		if (MU.size() > 255)
		{
			std::cout << "Numero de caracteres exedido" << std::endl;
			sf::sleep(sf::seconds(3));
		}
		else
		{
			break;
		}
	}
	return MU;
}

int main()
{
	sf::TcpSocket socket;
	char mode;
	char buffer[2000];
	int eleccion = 0;
	std::size_t received;
	std::string A;
	bool done = false;
	std::string text = "Connected to: ";

	std::cout << "Cliente = 1 o Server = 2" << std::endl;
	std::cin >> eleccion;
	if (eleccion == 1)
	{
		/*sf::TcpSocket tcpsocket;
		if (tcpsocket.connect("127.0.0.1", 45000) != sf::Socket::Done)
		{
			return -1;
		}
		else
		{
			std::cout << "Conectado al server" << std::endl;
		}

		sf::sleep(sf::seconds(1));

		const int m = 255;
		A = Message_user();
		char message[m];
		strcpy_s(message, A.c_str());

		if (tcpsocket.send(message, m) != sf::Socket::Done)
		{
			
		}
		else
		{
			std::cout << "Message Send" << std::endl;
		}*/
		socket.connect("127.0.0.1", 20000);
		text += "Client"; 
		mode = 'r';
	}
	else if (eleccion == 2)
	{
		/*sf::TcpListener listener;
		listener.listen(45000);

		sf::TcpSocket socket;
		if (listener.accept(socket) != sf::Socket::Done)
		{
			return -1;
		}

		sf::sleep(sf::seconds(1));

		const std::size_t size = 255;
		char data[size];
		std::size_t ReadSize;

		if (socket.receive(data, size, ReadSize) != sf::Socket::Done)
		{
			return -1;
		}


		std::cout << data << std::endl;*/
		sf::TcpListener listener;
		listener.listen(20000);
		listener.accept(socket);
		text += "Server";
		mode = 's';
	}

	socket.send(text.c_str(), text.length() + 1);

	socket.receive(buffer, sizeof(buffer), received);

	std::cout << buffer << std::endl;

	system("cls");

	while (!done)
	{
		if (mode == 's')
		{
			text = Message_user();
			socket.send(text.c_str(), text.length() + 1);
			mode = 'r';
		}
		else 
		{
			socket.receive(buffer, sizeof(buffer), received);
			std::cout << "Mesaje\n" << buffer << std::endl;
			mode = 's';
		}
	}
	
	
	//127.0.0.1
	//Game game;
	//game.run();
	/*sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	sf::CircleShape shape(50.f);

	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
*/

	std::cin.ignore();
	std::cin.get();
	return 0;
}