/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:04 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 15:49:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	
	//* Constructors
	std::cout << "\nConstructors" << std::endl;
	std::cout << "============" << std::endl;
	ClapTrap claptrap("CL4P-TP");
	ScavTrap scavtrap("SC4V-TP");
	FragTrap fragtrap("FR4G-TP");
	DiamondTrap diamondtrap("DI4M0ND-TP");
	
	std::cout << std::endl;
	
	//* Claptrap
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

	std::cout << std::endl;
	
	//*FragTrap
	std::cout << "FRAGTRAP: Attacks" << std::endl;
	std::cout << "=================" << std::endl;
	fragtrap.attack("Marauder");
	fragtrap.takeDamage(75);
	
	std::cout << "\nFRAGTRAP: beRepaired:\n";
	std::cout << "=====================" << std::endl;
	fragtrap.beRepaired(35);
	fragtrap.beRepaired(50);
	
	std::cout << "\nFRAGTRAP: High Five Guys !:\n";
	std::cout << "===========================" << std::endl;
	fragtrap.highFivesGuys();

	std::cout << std::endl;

	//*DiamondTrap
	std::cout << "DIAMONDTRAP: Attacks" << std::endl;
	std::cout << "=================" << std::endl;
	diamondtrap.attack("Marauder");
	diamondtrap.takeDamage(75);
	
	std::cout << "\nDIAMONDTRAP: beRepaired:\n";
	std::cout << "=====================" << std::endl;
	diamondtrap.beRepaired(35);
	diamondtrap.beRepaired(50);
	
	std::cout << "\nDIAMONDTRAP: Special Moves!:\n";
	std::cout << "=============================" << std::endl;
	diamondtrap.GuardGate();
	diamondtrap.highFivesGuys();

	std::cout << "\nDIAMONDTRAP: Who am I ?:\n";
	std::cout << "=============================" << std::endl;
	diamondtrap.whoAmI(); //TODO Need fix
	
	std::cout << "\nDestructors\n";
	std::cout << "===========" << std::endl;
}
