/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:37:22 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 09:27:57 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

//*Constructors
//* ===============================================================================
FragTrap::FragTrap() { 
	
	this->name_ = "Interplanetary Ninja Assassin Claptrap",
	this->Hitpoints = FRAG_HP;
	this->EnergyPoints = FRAG_ENERGY;
	this->AttackDamage = FRAG_ATKDMG;	
	
	std::cout << "FragTrap <" << name_ << "> It's time to phase you suckers out!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {

	this->name_ = name,
	this->Hitpoints = FRAG_HP;
	this->EnergyPoints = FRAG_ENERGY;
	this->AttackDamage = FRAG_ATKDMG;
	
	std::cout << "FragTrap <" << name_ << "> It's time to phase you suckers out!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "FragTrap <" << name_ << "> It's time to phase you suckers out!" << std::endl;
}

FragTrap::~FragTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "FragTrap <" << this->name_ << "> Ha ha ha! Fall before your robot overlord!" << std::endl;
	else
		std::cout << "FragTrap <" << this->name_ << "> I'M DEAD I'M DEAD OHMYGOD I'M DEAD!"
				  << std::endl;
}
//* ===============================================================================


//* Operator Overload
//* ===============================================================================
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	
	name_ = rhs.name_;
    Hitpoints = rhs.Hitpoints;
    EnergyPoints = rhs.EnergyPoints;
    AttackDamage = rhs.AttackDamage;

    return (*this);
}
//* ===============================================================================


//* METHODS
//* ===============================================================================
void FragTrap::attack(const std::string& target) {
	
	std::cout << "SkavTrap <" << this->name_ << "> attack <" << target
			  << ">, causing <" << this->AttackDamage << "> points of damage!"
			  << std::endl;
}

void FragTrap::highFivesGuys() {
	
	std::cout << "Secret handshake!" << std::endl;
}
//* ===============================================================================
