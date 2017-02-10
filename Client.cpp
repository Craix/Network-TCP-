#include <SFML\Network.hpp>
#include <iostream>
#include <string>


int main()
{
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket; 
	std::string text = "Conected to... client ";
	char buffer[2000];
	std::size_t received;

	std::cout << "Client" << std::endl; // initial

	for (int i = 0; i < 5; i++)
	{
		sf::Socket::Status status = socket.connect(ip, 2000);
		if (status != sf::Socket::Done)
		{
			std::cout << "Tray again : " << i << std::endl;
		}
		else
		{
			socket.connect(ip, 2000);

			socket.receive(buffer, sizeof(buffer), received);
			socket.send(text.c_str(), text.length() + 1);
			std::cout << buffer << std::endl;

			break;
		}
	}
	
	bool start = true;
	
	while (start)
	{
		text = "";
		std::cin >> text;
		
		if (text == "end")
		{
			start = !start;
		}
		else
		{
			socket.send(text.c_str(), text.length() + 1);
		}
	}

	system("pause");

	return 0;

}