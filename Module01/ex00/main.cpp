/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:15:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 08:14:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

int main(void)
{
	//* Instanciation of two objects Zombie passing a name to the function
	Zombie *zombie1 = newZombie("Zomboy");
	Zombie *zombie2 = newZombie("ZomGirl");
	
	//* Zombies announce themselves
	zombie1->announce();
	zombie2->announce();
	randomChump("Jack");

	//* Calls the Destructor and output a message.
	//* Also frees the memory allocated on the heap.
	delete zombie1;
	delete zombie2;
}
