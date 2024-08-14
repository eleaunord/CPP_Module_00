#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(){

    std::string command;
    int i;
    PhoneBook list;

    std::cout << "Welcome to your Phonebook!!" << std::endl;
    std::cout << "Do You want to :" << std::endl;
    std::cout << "ADD - Add a new contact"  << std::endl;
    std::cout << "SEARCH - Search for a specific contact " << std::endl;
	std::cout << "EXIT - Close phonebook. WARNING : you will loose all your contacts." << std::endl;

    while (1)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
            list.add();
        else if (command == "SEARCH")
        {
            list.display_contacts();
            i = list.get_index();
            if (i >= 0)
                list.print_info(i);
        }
        else if (command == "EXIT")
            break;
    }
    std::cout << std::endl;
    return 0;
}