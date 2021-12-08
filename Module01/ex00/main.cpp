/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:15:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 14:35:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("Zomboy");
	Zombie *zombie2 = newZombie("ZomGirl");
	
	zombie1->announce();
	zombie2->announce();
	randomChump("Jack");

	delete zombie1;
	delete zombie2;
}
