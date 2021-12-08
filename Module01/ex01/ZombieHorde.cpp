/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:55:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 15:39:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde( int32_t N, std::string name) {

	Zombie* horde;
	
	if (N == 1)
		return (new Zombie(name));
		
	else if (N < 1)
	{
		std::cout << "Insuficient number of zombies" << std::endl;
		return (NULL);
	}
		
	horde = new Zombie[N];
	return (horde);
}
