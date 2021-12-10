/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:06:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 08:25:12 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Zombie.hpp"

Zombie::Zombie() {} //* Default Constructor

Zombie::Zombie(const std::string& new_name) { //* Overloaded Constructor
	
	this->name = new_name;
}

Zombie::~Zombie() { //* Default Destructor
	
	//* Message outputed by the Destructor everytime an object is destroyed
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::randName() {
	
	//* list of Male and Female names
	std::string male[10] = {"Earl", "Eddie", "Edward", "Edwin", "Elmer", "Ernest", "Eugene", "Everett", "Francis", "Frank"};
	std::string female[10] = {"Charlotte", "Claire", "Clara", "Constance", "Daisy", "Dolores", "Dora", "Doris", "Dorothy", "Edith"};
	std::string new_name;
	
	int32_t	genre;
	
	//* rand() give a big random number based on the seed in main (otherwise its always the same)
	//* modulo 2 will always give 0 or 1
	genre = rand() % 2;
	if (genre == 0)
		new_name = male[rand() % 10]; //* modulo 10 will give a random number between 0 and 9. which give an index in either name lists
	else
		new_name = female[rand() % 10];
	this->name = new_name;
}

void Zombie::announce( void ) {
	
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
