/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:06:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 16:36:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& new_name) {
	
	this->name = new_name;
}

Zombie::~Zombie() {
	
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::randName() {
	
	std::string male[10] = {"Earl", "Eddie", "Edward", "Edwin", "Elmer", "Ernest", "Eugene", "Everett", "Francis", "Frank"};
	std::string female[10] = {"Charlotte", "Claire", "Clara", "Constance", "Daisy", "Dolores", "Dora", "Doris", "Dorothy", "Edith"};
	std::string new_name;
	
	int32_t	genre;
	
	genre = rand() % 2;
	if (genre == 0)
		new_name = male[rand() % 10];
	else
		new_name = female[rand() % 10];
	this->name = new_name;
	// std::string vowels = "aeiouy";
	// std::string conson = "bcdfghjklmnpqrstvwxz";
	// std::string new_name;
	// int32_t n_letter;

	// n_letter = 5;
	// if (rand() % 2 == 0)
	// 	n_letter = 7;
	// for (int32_t i = 0; i < n_letter; i++)
	// {
	// 	if (i % 2 == 0)
	// 		new_name += conson[rand() % 20];
	// 	else
	// 		new_name += vowels[rand() % 6];
	// }
	// name = new_name;
}

void Zombie::announce( void ) {
	
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
