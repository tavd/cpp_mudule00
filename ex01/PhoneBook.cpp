#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : current_contact_index(0)
{
    prompt[0] = "Enter first name: ";
	prompt[1] = "Enter last name: ";
	prompt[2] = "Enter nickname: ";
	prompt[3] = "Enter phone number: ";
	prompt[4] = "Enter darkest secret: ";
	std::cout << std::endl << "Welcome to the phonebook!" << std::endl << std::endl;
	std::cout << "You can enter one of the following commands:" << std::endl;
	std::cout << "ADD/add - add a new contact" << std::endl;
	std::cout << "SEARCH/search - search for a contact by index" << std::endl;
	std::cout << "EXIT/exit - exit the program" << std::endl<< std::endl;
}

bool PhoneBook::is_all_spaces(const std::string &str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return false;
    }
    return true;
}

bool PhoneBook::is_valid_phone_number(const std::string &str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
        {
        if (str[i] == '+')
        {
            if (i != 0)
            return false;
        }
        else if (str[i] == '-')
        {
            if (i == 0 || i == str.length() - 1 || str[i - 1] == '-')
            return false;
        }
        else
            return false;
        }
    }
    return true;
}

void PhoneBook::show_saved_contact(void)
{
	std::cout<<std::endl << "Contact successfully saved!" << std::endl << std::endl << "Details:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << prompt[i].substr(6) << contacts[current_contact_index].get_data(i)<<std::endl;
        std::cout << std::endl;
}

bool PhoneBook::contact_overwrite()
{
	std::cout << "Phone book is full! Adding new contact will overwrite the oldest one" << std::endl;
    std::cout << "Continue? (y/n):";
    std::string input;
    if (!std::getline(std::cin, input))
        return false;
    if (input.empty() || input[0] != 'y')
        return false;
    return true;
}

void PhoneBook::add_contact(void)
{
    if (current_contact_index == 8)
    {
        if (!contact_overwrite())
            return ;
        current_contact_index = 0;
    }
    std::string input;
    for (int i = 0; i < 5;)
    {
        std::cout << prompt[i];
        if (!std::getline(std::cin, input))
            return ;
        if (is_all_spaces(input))
        {
            std::cout << "No empty fields allowed!" << std::endl;
            continue ;
        }
        if (i == 3 && !is_valid_phone_number(input))
        {
            std::cout << "Invalid phone number!" << std::endl
                      << "Please enter a phone number containing only digits,"
                      << " optional leading '+'," << std::endl
                      << "and hyphens separating groups of digits (e.g., +1234, 567-890)." << std::endl;
            continue;
        }
        contacts[current_contact_index].set_data(i, input);
        i++;
    }
    show_saved_contact();
    current_contact_index++;
}

//• SEARCH: display a specific contact
// Display the saved contacts as a list of 4 columns: index, first name, last
// name and nickname.
// ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
// them. The text must be right-aligned. If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a dot (’.’).
// ◦ Then, prompt the user again for the index of the entry to display. If the index
// is out of range or wrong, define a relevant behavior. Otherwise, display the
// contact information, one field per line.

void PhoneBook::show_contacts(int index)
{
    std::cout << std::setw(10) << index + 1 << "|";//std::right, std::setfill(' '); by default
    for (int i = 0; i < 3; i++)
    {
        std::string result = contacts[index].get_data(i);
        if (result.length() > 10)
            result = result.substr(0, 9) + ".";
        std::cout << std::setw(10) << result << "|";
    }
    std::cout << std::endl;
}


void PhoneBook::search_contact_details_by_index(void)
{
	std::string input;
	int index = 0;
	while (1)
	{
		std::cout << std::endl << "Enter index of a contact: ";
		if (!std::getline(std::cin, input))
			return ;
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
			break ;
		else
        {
			std::cout<<"No such index (min index = 1, max = 8)!" << std::endl;
            continue ;
        }
	}
		index = input[0] - '0';
		if (contacts[index - 1].get_data(0).empty())
		{
			std::cout<< std::endl << "No contact saved at this index!" << std::endl << std::endl;
			return ;
		}
        std::cout << std::endl;
        std::cout << "Contact info:" << std::endl;
		for (int i = 0; i < 5; i++)
		std::cout << prompt[i].substr(6) << contacts[index - 1].get_data(i) << std::endl;
        std::cout << std::endl;
}

void PhoneBook::search_contact(void)
{
	int i = 0;
    if(!contacts[i].get_data(0).empty())
    std::cout << "Choose a contact to search from the list below:" << std::endl;
	while (i < 8 && !contacts[i].get_data(0).empty())
	{
		show_contacts(i);
		i++;
	}
    if (contacts[0].get_data(0).empty())
        std::cout<< "Phone book is empty!" << std::endl << std::endl;
    else
	    search_contact_details_by_index();
}
