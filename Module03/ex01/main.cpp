/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 13:38:20 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


//* Extended the tests from last Module to now test the SubClass's inheritance
int main(void) {
	
	//* Constructor Calls
	std::cout << "\nConstructors" << std::endl;
	std::cout << "============" << std::endl;
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("SC4V-TP");
	
	std::cout << std::endl;
	
	//* ClapTrap 
	std::cout << "CLAPTRAP: Attacks" << std::endl;
	std::cout << "=================" << std::endl;
	claptrap.attack("Marauder");
	claptrap.takeDamage(5);
	
	std::cout << "\nCLAPTRAP: beRepaired:\n";
	std::cout << "=====================" << std::endl;
	claptrap.beRepaired(3);
	claptrap.beRepaired(3);
	
	std::cout << std::endl;
	
	//* ScavTrap
	std::cout << "SCAVTRAP: Attacks" << std::endl;
	std::cout << "=================" << std::endl;
	scavtrap.attack("Marauder");
	scavtrap.takeDamage(75);
	
	std::cout << "\nSCAVTRAP: beRepaired:\n";
	std::cout << "=====================" << std::endl;
	scavtrap.beRepaired(35);
	scavtrap.beRepaired(50);
	
	std::cout << "\nSCAVTRAP: Gate Keeper Mode:\n";
	std::cout << "===========================" << std::endl;
	scavtrap.GuardGate();

	std::cout << "\nDestructors\n";
	std::cout << "===========" << std::endl;
	
}
