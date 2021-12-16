/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:22:51 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 08:02:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>

#include "Phonebook.hpp"

//* Where you have a header file for a Class, you have a cpp file for it.
//* This is where you implement the class method functions
//* You can also implement the method inside the class file.

Phonebook::Phonebook() {
	count = 0;
}

int32_t Phonebook::GetCount() 
{
	return (count);
}

//* verify that the input is all digits and no bigger than total active contacts
//* and no lower than 0.
bool Phonebook::VerifyInput(std::string const input) 
{
	int32_t index = atoi(input.c_str());
	
	for (int32_t i = 0; input[i]; i++)
	{
		if (isdigit(input[i]))
			continue;
		return (false);
	}
	if (index > GetCount() - 1 || index < 0)
		return (false);
	return (true);
}

//* Adds a contact to the Contact array
//* Shifts all the existing contacts down the array, setting their new index
//* Then prompts the user to enter all the required fields
void Phonebook::add_contact()
{
	std::string input;
	int32_t i;

	for (i = N_CONTACT - 1; i > 0; i--)
	{
		contact[i] = contact[i - 1];
		contact[i].SetContactIndex(i);
	}
	std::cout << "\nPlease fill all required fields\n";
	std::cout << "-------------------------------\n" << std::endl;
	std::cout << "Enter First Name: ";
	std::getline(std::cin >> std::ws, input);
	contact[0].SetField(input, "first_name");
	std::cout << "Enter Last Name: ";
	std::getline(std::cin >> std::ws, input);
	contact[0].SetField(input, "last_name");
	std::cout << "Enter Nickname: ";
	std::getline(std::cin >> std::ws, input);
	contact[0].SetField(input, "nickname");
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin >> std::ws, input);
	contact[0].SetField(input, "phone_number");
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin >> std::ws, input);
	std::cout << std::flush;
	contact[0].SetField(input, "darkest_secret");
	contact[0].SetContactIndex(0);
	contact[0].SetActive(); //* Simple bool to set the "index" or "contact" as active
	count++;
	if (count > N_CONTACT)
		count = N_CONTACT;
}

//* Lists all the "active" contacts of the array
void Phonebook::list_contact() 
{
	std::string input;
	int32_t index;
	
	std::cout << "\nCONTACT LIST\n";
	std::cout << " ______________________________________________\n";
	std::cout << "|     Index||First Name|| Last Name||  Nickname|\n";
	std::cout << "|----------||----------||----------||----------|\n";
	for (int32_t i = 0; i < N_CONTACT; i++)
	{
		if (contact[i].IsActive())
		{	
			//* "setw(10)" formats the width of each column to 10.
			//* TruncateStr truncates longer than 10 chars strings and replaces the last char with a dot "."
			std::cout << "|" << std::setw(10) << contact[i].GetContactIndex() << "|";
			std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("first_name")) << "|";
			std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("last_name")) << "|";
			std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("nickname")) << "|" << std::endl;
			std::cout << "|----------------------------------------------|" << std::endl;
		}
	}
	
	//* Prompts the user to select a specific valid "active" index to show contacts informations
	std::cout << "Please, Select an index to expand the contact informations." << std::endl;
	while (std::cin.good())
	{
		std::cout << "> ";
		std::getline(std::cin >> std::ws, input);
		
		//* Cannot use stoi() here to convert string to int because we are limited to c++98.
		//* Since C doesn't support std:string class we have to use atoi(). 
		//* But, since atoi only takes (const char *) we can convert our std::string input
		//* to (const char *) using c_str() method.
		index = atoi(input.c_str());

		if (input == "RETURN")
			return;
		else if (VerifyInput(input))
		{
			if (contact[index].IsActive())
			{
				ExpandContact(index);
				break;
			}	
		}
		else 
			std::cout << "Invalid Index. Please select a valid index\n" << std::endl;
	}
}

void Phonebook::ExpandContact(int32_t index) 
{
	std::cout << "\n==============================\n";
	std::cout << "First Name:   " << contact[index].GetField("first_name") << "\n";
	std::cout << "Last Name:    " << contact[index].GetField("last_name") << "\n";
	std::cout << "NickName:     " << contact[index].GetField("nickname") << "\n";
	std::cout << "Phone Number: " << contact[index].GetField("phone_number") << "\n";
	std::cout << "Dark Secret:  " << contact[index].GetField("darkest_secret") << "\n";
	std::cout << "==============================" << std::endl;
}
