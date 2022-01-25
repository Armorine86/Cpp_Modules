/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:31 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 15:25:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {

	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	std::cout << std::endl;
	
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("bob", club);
		HumanB jim("Jim");

		bob.attack();
		jim.attack();

		jim.setWeapon(club);
		jim.attack();
		
		club.setType("some other type of club");
		bob.attack();
		jim.attack();
	}
}
