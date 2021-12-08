/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:16:44 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 11:27:26 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

#include "Phonebook.hpp"

void manual(void)
{
	std::cout << "\n\nSELECT AN OPTION\n";
	std::cout << "================\n";
	std::cout << "ADD -> Add a new contact" << std::endl;
	std::cout << "SEARCH -> Search for an existing contact" << std::endl;
	std::cout << "EXIT -> Exit and close your Phonebook. All contacts will be lost." << std::endl;
}

int main(void)
{
	Phonebook phonebook;
	std::string cmd;

	std::cout << "\n|---------------------------------|\n";
	std::cout << "|WELCOME TO YOUR CRAPPY PHONEBOOK!|\n";
	std::cout << "|---------------------------------|\n" << std::endl;

	manual();
	while (std::cin.good())
	{
		std::cout << "\nNumber of currently active contact: [" << phonebook.GetCount() << "]\n";
		std::cout << "\n>";
		std::getline(std::cin >> std::ws, cmd);
		if (cmd == "ADD")
		{
			if (phonebook.GetCount() == 8)
				std::cout << "Phonebook is full. Oldest contact will be overwritten" << std::endl;
			phonebook.add_contact();
		}
		else if (cmd == "SEARCH")
			phonebook.list_contact();
		else if (cmd == "EXIT" || cmd == "")
		{
			std::cout << "Now exiting programm. All contacts will be lost" << std::endl;
			break;
		}
		else
			std::cout << "Invalid Command" << std::endl;
	}
	return (0);
}
