#include "Contact.hpp"
#include "PhoneBook.hpp"

//Using Initializer List
PhoneBook::PhoneBook(void) : index(0), prompt{"Enter first name: ", "Enter last name: ", "Enter nickname: ",
									 "Enter phone number: ", "Enter darkest secret: "}
{
	std::cout<< "Welcome to the phonebook!" << std::endl;
	std::cout<< "Enter one of the following commands:" << std::endl;
	std::cout<< "ADD - add a new contact" << std::endl;
	std::cout<< "SEARCH - search for a contact by index" << std::endl;
	std::cout<< "EXIT - exit the program" << std::endl;
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
    bool has_digit = false;
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            has_digit = true;
        else if (str[i] == '+')
        {
            if (i != 0)
            return false;
        }
        else if (str[i] == '-')
        {
            if (i == 0 || i == str.length() - 1 || str[i - 1] == '-')
                return false;
        }
        else //any other characters
            return false;
    }
    return has_digit;
}


void PhoneBook::show_saved_contact(void)
{
	std::cout<<std::endl<<"Contact successfully saved!"<<std::endl<<"Details:"<<std::endl;
	for (int i = 0; i < 5; i++)
		std::cout<<prompt[i].substr(6)<<contacts[index].get_data(i)<<std::endl;
}

bool PhoneBook::contact_overwrite()
{
	std::cout << "Phone book is full! Adding new contact will overwrite the oldest one" << std::endl;
    std::cout << "Continue? (y/n):";
    std::string input;
    if (!std::getline(std::cin, input))//getline
    {
        std::cout << "\nInput interrupted. Contact is not added." << std::endl;
        return false;
    }
    if (input.empty() || input[0] != 'y')
        return false;
    return true;
}

void PhoneBook::add_contact(void)
{
    if (index == 8)
    {
		if (!contact_overwrite())
		return ;
        index = 0;
    }
    std::string input;
    for (int i = 0; i < 5;)
    {
        std::cout << prompt[i];
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nInput interrupted. Contact not fully added." << std::endl;
            return;//prints Enter command: then exits
        }
        if (is_all_spaces(input))
        {
            std::cout << "No empty fields allowed!" << std::endl;
            continue;
        }
        if (i == 3 && !is_valid_phone_number(input))
        {
            std::cout << "Invalid phone number! Usage: digits, '+', '-'" << std::endl;//todo change usage
            continue;
        }
        contacts[index].set_data(i, input);
        i++;
    }
    show_saved_contact();
    index++;
}

// Display the saved contacts as a list of 4 columns: index, first name, last
// name and nickname.
// ◦ Each column must be 10 characters wide. A pipe character (’|’) separates
// them. The text must be right-aligned. If the text is longer than the column,
// it must be truncated and the last displayable character must be replaced by a
// dot (’.’).
// ◦ Then, prompt the user again for the index of the entry to display. If the index
// is out of range or wrong, define a relevant behavior. Otherwise, display the
// contact information, one field per line.
void PhoneBook::show_contacts(int index)
{
	std::cout<<std::setw(10)<<index + 1<<"|";//std::setfill(' '); by default
	for (int i = 0; i < 3; i++)
	{
		std::string contact_data = contacts[index].get_data(i);
		if (contact_data.length() > 10)
		    contact_data = contact_data.substr(0, 9) + ".";
		std::cout<<std::setw(10)<<contact_data<<"|";
	}
	std::cout<<std::endl;
}

void PhoneBook::show_contact_details_by_index(void)
{
	std::string index;
	int number = 0;
	while (1)
	{
		std::cout<<"Input index of the contact: ";
		if (!std::getline(std::cin, index))
			{
				std::cout<<std::endl;
				return ;
			}
		if (index.length() == 1 && index[0] >= '1' && index[0] <= '8')
			break ;
		else
			std::cout<<"NO such index (min index = 1, max = 8)!" << std::endl;
	}
		number = index[0] - '0';
		if (contacts[number - 1].get_data(0).empty())//if the first field is empty the whole contact is empty
		{
			std::cout<<"No contact saved at this index." << std::endl;
			return ;
		}
		for (int i = 0; i < 5; i++)
		std::cout << prompt[i].substr(6)<<contacts[number - 1].get_data(i) << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::search_contact(void)
{
	std::cout<<std::endl<<"Choose a contact to search"<<std::endl;
	std::cout<<"Contacts:"<<std::endl;
	int i = 0;
	while (i < 8)
	{
		show_contacts(i);
		i++;
	}
	show_contact_details_by_index();
}
