#include "PhoneBook.hpp"

std::string get_input_field(std::string prompt)
{
    std::string user_input;
    while (user_input.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, user_input))
        {
            // check if input was interrupted (EOF or error)
            if (std::cin.eof())
            {
                std::cout << "\nInput interrupted. Exiting..." << std::endl;
                exit(0); // exit the program or handle the EOF as appropriate
            }
            else
            {
                std::cin.clear(); // clear the error state
                std::cout << "Error reading input. Please try again." << std::endl;
            }
        }
    }
    return user_input;
}

//ccircular buffer
void PhoneBook::add()
{
    static int i = 0; // keeps track of the current contact index

    std::cout << "Fill in the info of your new contact." << std::endl;
    contacts[i].set_field("first name", get_input_field("First name: "));
    contacts[i].set_field("last name", get_input_field("Last name: "));
    contacts[i].set_field("nickname", get_input_field("Nickname: "));
    contacts[i].set_field("phone number", get_input_field("Phone number: "));
    contacts[i].set_field("darkest secret", get_input_field("Darkest secret: "));

    // update index for next contact. If it exceeds the max, reset to 0.
    i = (i + 1) % MAX_CONTACTS;
}

// utilisation du iomanip setw pour garantir que chaque colonne a une largeur fixe de 10 car
void	print_cell(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10);
	std::cout << str << "|";
}

void PhoneBook::display_contacts()
{
    // check if Phone book is empty
    if (contacts[0].get_field("first name").empty())
    {
        std::cout << "Your phonebook is empty." << std::endl;
        return ;
    }

    // print headers for the contact list table
    print_cell("index");
	print_cell("first name");
	print_cell("last name");
	print_cell("nickname");

    // newline for each row of data
    std::cout << std::endl;
    
    // iterates though contacts and print details
    for (int i = 0; i < MAX_CONTACTS; i++){
        if (!contacts[i].get_field("first_name").empty()){
            // print index i
            std::cout << std::setw(10);
            std::cout << i << "|";
            // print data
        	print_cell(contacts[i].get_field("first name"));
			print_cell(contacts[i].get_field("last name"));
			print_cell(contacts[i].get_field("nickname"));
            std::cout << std::endl;
        }
    } 
}

int PhoneBook::get_index()
{

    int index;
    int max = 0;

    // calculate the max index of non-empty contacts
    while (max < MAX_CONTACTS && !contacts[max].get_field("first name").empty())
        max++;
    max--;

    // if there are no contacts, return -1
    if (max == -1)
        return max;

    std::string line;
    while (true)
    {
        std::cout << "Enter the index of the contact: ";
        if (!std::getline(std::cin, line))
        {
            // handle end-of-file (EOF) or read error
            if (std::cin.eof())
            {
                std::cout << "\nInput interrupted. Exiting..." << std::endl;
                exit(0); // exit the program gracefully
            }
            else
            {
                std::cin.clear(); // elear any other error flags
                std::cout << "Error reading input. Please try again." << std::endl;
                continue;
            }
        }

        // check if the input line is empty or contains only whitespace
        std::istringstream iss(line);
        if (!(iss >> index))
        {
            std::cout << "Must be an integer between 0 and " << max << std::endl;
            continue;
        }

        // check if the index is within the valid range
        if (index >= 0 && index <= max)
        {
            break;
        }
        else
        {
            std::cout << "Must be an integer between 0 and " << max << std::endl;
        }
    }

    return index;
}

void	PhoneBook::print_info(int index)
{
	std::cout << "First name: " << contacts[index].get_field("first name") << std::endl;
    std::cout << "Last name: " << contacts[index].get_field("last name") << std::endl;
    std::cout << "Nickname: " << contacts[index].get_field("nickname") << std::endl;
    std::cout << "Phone number: " << contacts[index].get_field("phone number") << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_field("darkest secret") << std::endl;
}

