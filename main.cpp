#include <SFML\Network.hpp>
#include <iostream>
#include <string>


int main()
{
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpSocket socket; 
	std::string text = "Conected to... ";
	char buffer[2000];

	std::size_t received;

	char conection_type, mode;

	std::cout << "Conection type s or c" << std::endl;
	std::cin >> conection_type; 


	if (conection_type == 's')
	{
		sf::TcpListener lisener;
		lisener.listen(2000); // port 2000
		lisener.accept(socket);
		text += "serwer";
	}
	else if(conection_type == 'c')
	{
		socket.connect(ip,2000);
		text += "client";
	}

	socket.send(text.c_str(), text.length() + 1);

	socket.receive(buffer, sizeof(buffer), received);

	std::cout << buffer << std::endl;
	
	system("pause");

	return 0;

}