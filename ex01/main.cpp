#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (input != "EXIT" && input != "exit")
	{
		// if (std::getline(std::cin, input))
		// 	std::cout<<"Enter command: ";
		if (!std::cin.eof())
		{
			std::cout << "Enter command: ";
			std::getline(std::cin, input);
		}
		else
		{
			std::cout<<std::endl;
			return 0;			
		}
		if (input.compare("ADD") == 0 || input.compare("add") == 0)
			phoneBook.add_contact();
		else if (input != "EXIT" && input != "exit")
			std::cout << "Invalid command! Enter valid one!" << std::endl;

	}
}