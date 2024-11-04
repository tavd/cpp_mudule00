#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;
    bool showPrompt = true; // Controls whether to show "Enter command:"

    while (1)
    {
        if (showPrompt)
            std::cout << std::endl << "Enter command:";
        showPrompt = true; // Reset the flag before each command
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            return 0;
        }
        if (input == "EXIT" || input == "exit")
            break;
        else if (input == "ADD" || input == "add")
        {
            if (!phoneBook.add_contact())
            {
                showPrompt = false; // Prevents "Enter command:" after interruption
                continue;
            }
        }
        else if (input == "SEARCH" || input == "search")
            phoneBook.search_contact();
        else
            std::cout << "Invalid command! Enter a valid one!" << std::endl;
    }
}
