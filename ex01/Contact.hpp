# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string data[5];
	public:
		Contact(void);
		void fill_data(int index, std::string input);
		std::string get_data(int index);
};
#endif
