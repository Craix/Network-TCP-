#include <SFML\Network.hpp>
#include <iostream>
#include <string>


int main()
{
	sf::TcpSocket socket;
	std::string text = "Conected to... serwer";
	char buffer[2000];
	std::size_t received;


	std::cout << "Server" << std::endl;


	sf::TcpListener lisener;
	lisener.listen(2000); // lisen
	lisener.accept(socket); // accept

	socket.send(text.c_str(), text.length() + 1); // send massage

	socket.receive(buffer, sizeof(buffer), received); // recevedie

	std::cout << buffer << std::endl; // print massage

	bool start = true;

	while (start)
	{
		socket.receive(buffer, sizeof(buffer), received);

		std::cout << buffer << std::endl;
	}


	system("pause");

	return 0;

}