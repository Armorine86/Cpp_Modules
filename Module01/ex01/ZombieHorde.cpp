/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:55:17 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:42:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde(int32_t N, std::string name) {

	Zombie* horde;
	
	if (N == 1)
		return (new Zombie(name));
		
	else if (N < 1)
	{
		std::cout << "Insufficient number of zombies" << std::endl;
		return (NULL);
	}
		
	//* Allocates an array in memory for N objects of class Zombie
	horde = new Zombie[N];
	return (horde);
}
