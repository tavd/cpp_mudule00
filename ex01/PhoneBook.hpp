# ifndef BOOK_HPP
# define BOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	int		index;
	Contact contacts[8];
	std::string prompt[5];
	bool	is_all_spaces(const std::string& str);
	bool	is_valid_phone_number(const std::string &str);
	void	show_saved_contact(void);
	void	show_contacts(int index);
	void	show_index_contact(void);
public:
	PhoneBook(void);
	void	add_contact(void);
	void	search_contact(void);
};

#endif