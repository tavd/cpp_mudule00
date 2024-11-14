#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string input;
	while (input != "EXIT" && input != "exit")
	{    //checks if the last operation on std::cin was successful (if getline didn't fail in other functions)
  		if (std::cin.good())
		{
			std::cout << "Enter command: ";
            if (!std::getline(std::cin, input))
			{
              std::cout << std::endl;
              return 0;
            }
            std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			return 0;
		}
		if (input.compare("ADD") == 0 || input.compare("add") == 0)
			phoneBook.add_contact();
		else if (input.compare("SEARCH") == 0 || input.compare("search") == 0)
			phoneBook.search_contact();
		else if (input != "EXIT" && input != "exit")
			std::cout << "Invalid command! Enter command from the list above!" << std::endl;
	}
    	return 0;
}

