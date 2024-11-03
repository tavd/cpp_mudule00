#include "PhoneBook.hpp"

int main()
{
    // int number = 0;
    // while (1)
    // {
    //   std::cout<<"input number: ";
    //   std::cin>>number;
    //   std::cout<<number;      
    // }

	PhoneBook phoneBook;
	std::string input;
	while (1)
	{
        std::cout<<std::endl<<"Enter command: ";
        if (!std::getline(std::cin, input))
        {
            std::cout<<std::endl;//todo
            return 0;
        }
        if (input == "EXIT" || input == "exit")
            break;
        else if (input == "ADD" || input == "add")
            phoneBook.add_contact();
		else if (input == "SEARCH" || input == "search")
			phoneBook.search_contact();
        else
            std::cout<<"Invalid command! Enter a valid one!"<<std::endl;
    }
}
