/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:22:51 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 10:45:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Phonebook.hpp"

Phonebook::Phonebook() {
	count = 0;
}

int32_t Phonebook::GetCount() 
{
	return (count);
}

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
	contact[0].SetActive();
	count++;
	if (count > N_CONTACT)
		count = N_CONTACT;
}

void Phonebook::list_contact() 
{
	std::string input;

	std::cout << "\nCONTACT LIST\n";
	std::cout << " ______________________________________________\n";
	std::cout << "|     Index||First Name|| Last Name||  Nickname|\n";
	std::cout << "|----------||----------||----------||----------|\n";
	for (int32_t i = 0; contact[i].IsActive(); i++)
	{
		std::cout << "|" << std::setw(10) << contact[i].GetContactIndex() << "|";
		std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("first_name")) << "|";
		std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("last_name")) << "|";
		std::cout << "|" << std::setw(10) << contact[i].TruncateStr(contact[i].GetField("nickname")) << "|" << std::endl;
		std::cout << "|----------------------------------------------|" << std::endl;
	}
	
	std::cout << "Please, Select an index to expand the contact informations." << std::endl;
	while (std::cin.good())
	{
		std::cout << "> ";
		std::getline(std::cin >> std::ws, input);
		if (input == "RETURN")
			return;
		else if (contact[std::stoi(input)].IsActive())
		{
			ExpandContact(std::stoi(input));
			break;
		}
		else
			std::cout << "Invalid Index. Please select a valid index\n" << std::endl;
	}
}

void Phonebook::ExpandContact(int32_t index) 
{
	std::cout << "\n========================\n";
	std::cout << "First Name:   " << contact[index].GetField("first_name") << "\n";
	std::cout << "Last Name:    " << contact[index].GetField("last_name") << "\n";
	std::cout << "NickName:     " << contact[index].GetField("nickname") << "\n";
	std::cout << "Phone Number: " << contact[index].GetField("phone_number") << "\n";
	std::cout << "Dark Secret:  " << contact[index].GetField("darkest_secret") << "\n";
}
