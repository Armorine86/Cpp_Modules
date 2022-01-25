/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:55:06 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:37:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Zombie.hpp"

int main(void) {

	Zombie *horde;
	
	horde = zombieHorde(N_ZOMBIES, "Zomboy");
	srand(time(NULL)); //* seed for the random number generator

	std::cout << std::endl;
	
	for (int32_t i = 0; i < N_ZOMBIES; i++)
	{
		horde[i].randName();
		horde[i].announce();
	}
	
	std::cout << std::endl;

	// deletes an allocated array
	delete[] horde;
}
