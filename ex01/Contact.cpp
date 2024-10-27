#include "Contact.hpp"

Contact::Contact(void)
{}

void Contact::fill_data(int index, std::string input)
{
	data[index] = input;
}

std::string Contact::get_data(int index)
{
	return data[index];
}
