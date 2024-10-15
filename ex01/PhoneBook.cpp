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
	for (std::string::size_type i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-')
		return false;
	}
	return true;
}

void PhoneBook::show_saved_contact(void)
{
	std::cout<<std::endl<<"Contact successfully saved!"<< std::endl<<std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout<<prompt[i].substr(6)<<contacts[index].get_contact_data(i)<<std::endl;
	}//substr(6) will skip first 6 chars of a string: "Enter first name:", the result: "first name:"
}

void PhoneBook::add_contact(void)
{
	std::cout<<"index="<<index<<std::endl;
	if (index == 2)//todo
	{
		std::cout<<"Phone book is full! Adding new contact will overite the oldest one"<<std::endl;
		std::cout<<"Continue? (y/n):";
		std::string input;
		if (!std::getline(std::cin, input))
    	{
            std::cout<<"\nInput interrupted. Contact not fully added."<<std::endl;
            return;
        }
		if (input.empty() || input[0] != 'y')
			return ;
		index = 0;
	}
	std::string input;
	for (int i = 0; i < 5;)
	{
		std::cout<<prompt[i];
		//If getline() fails due to EOF (ctrl+D) or another input error
		if (!std::getline(std::cin, input))
    	{
            std::cout<<"\nInput interrupted. Contact not fully added."<<std::endl;
            return;
        }
		if (input.empty() || is_all_spaces(input))
		std::cout<<"No empty fields allowed!"<< std::endl;
		if (i == 3 && (input.empty() || !is_valid_phone_number(input)))
		{
			std::cout<<"Invalid phone number! Usage: digits, '+', '-'"<<std::endl;
			continue;
		}
		else
		{
		contacts[index].fill_contact_data(i, input);
		i++;
		}
	}
	show_saved_contact();
	index++;
}

void PhoneBook::show_contacts(int index)
{
	std::cout<<std::setw(10)<<index + 1<<"|";
	for (int i = 0; i < 3; i++)//first name, last name, nickname
	{
		std::string contact_data = contacts[index].get_contact_data(i);
		if (contact_data.length() > 10)
		contact_data = contact_data.substr(0, 9) + ".";
		std::cout<<std::setw(10)<<std::right<<contact_data<<"|";
	}
}

void PhoneBook::search_contact(void)
{
	std::cout<<"Contacts:"<<std::endl;
	int i = 0;
	while (i < 8)
	{
		show_contacts(i);
		i++;
	}
	// std::cout<<"Choose a contact"<<std::endl;
}
