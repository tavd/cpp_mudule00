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

void PhoneBook::show_added_contact(void)
{
	std::cout<<std::endl<<"Contact successfully added!"<< std::endl<<std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout<<prompt[i].substr(6)<<contacts[index].get_contact_data(i)<<std::endl;
	}
}

void PhoneBook::add_contact(void)
{
	if (index == 2)//todo
	{
		std::cout<<"Phone book is full! Adding new contact will overite the first one"<<std::endl;
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
	show_added_contact();
	index++;
}

// void PhoneBook::add_contact(void)
// {
// 	if (this->index == 8) //full Phone_book (max = 8 contacts)
// 	{
// 		std::cout << "Phonebook is full! Adding a new contact will overwrite the oldest one!" << std::endl;
// 		std::cout << "Do you want to continue? (y/n): ";
// 		std::string input;
// 		std::getline(std::cin, input);
// 		if (input.empty() || input[0] != 'y')
// 			return ;
// 		this->index = 0;
		
// 	}
// 	std::string input;
// 	for (int j(0); j < 5;)
// 	{
// 		std::cout << this->prompt[j];
// 		std::getline(std::cin, input);
// 		if (std::cin.eof())
// 		{
// 			std::cout << std::endl;
// 			return ;
// 		}
// 		if (j == 3) //phone number
//         {
//             if (input.empty() || !is_valid_phone_number(input))
//             {
//                 std::cout << "Invalid phone number! Please enter digits, '+' or '-'." << std::endl;
//                 continue;
//             }
//         }
// 		if (input.empty() || is_all_spaces(input))
// 			std::cout << "No empty fields allowed! Fill your info!" << std::endl;
// 		else
// 		{
// 			std::cout<<"here"<<std::endl;
// 			this->contacts[this->index].fill_contact_data(j, input);
// 			j++;
// 		}
// 	}
// 	show_added_contact();
// 	this->index++;
// }