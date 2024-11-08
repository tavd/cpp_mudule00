#include "PhoneBook.hpp"
#include <limits>

int main(void)
{
	PhoneBook book;
	std::string command;
	while (command != "EXIT" && command != "exit")
	{
  		if (std::cin.good())
		{
			std::cout << "Enter command: ";
			std::getline(std::cin, command);
            std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			return (0);
		}
		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			book.add_contact();
		else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
			book.search_contact();
		else if (command != "EXIT" && command != "exit")
			std::cout << "Invalid command! Enter valid one!" << std::endl;
	}
	return (0);
}

