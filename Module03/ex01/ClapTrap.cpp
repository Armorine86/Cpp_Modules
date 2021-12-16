/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 09:48:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"


//* Constructors // Destructor
//* ===============================================================================
ClapTrap::ClapTrap() : 
	name_("NoNameClap"),
	Hitpoints(CLAP_HP),
	EnergyPoints(CLAP_ENERGY),
	AttackDamage(CLAP_ATKDMG) {std::cout << "\nClapTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;}

ClapTrap::ClapTrap(std::string name) :
	name_(name),
	Hitpoints(CLAP_HP),
	EnergyPoints(CLAP_ENERGY),
	AttackDamage(CLAP_ATKDMG)
	{ std::cout << "\nClapTrap <" << this->name_ << "> have entered the fray!\n" << std::endl; }

ClapTrap::~ClapTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "\nClapTrap <" << this->name_ << "> leaves the arena.\n" << std::endl;
	else
		std::cout << "\nClapTrap <" << this->name_ << "> have been destroyed\n" << std::endl; 
}
//* ===============================================================================


//* Methods
//* ===============================================================================
void ClapTrap::attack(std::string const& target) {

	std::cout << "ClapTrap <" << this->name_ << "> attack <" << target
			  << ">, causing <" << this->AttackDamage << "> points of damage!\n"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	this->Hitpoints -= amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> gets hit for <" << amount
			  << "> damage!" << std::endl;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->Hitpoints
			  << "> Hitpoints left!\n" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	
	if ((int32_t)amount > this->EnergyPoints)
		amount = this->EnergyPoints;
		
	this->EnergyPoints -= amount;
	this->Hitpoints += amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->EnergyPoints
			  << "> Energy left!\n" << std::endl;
	
	if (this->Hitpoints >= CLAP_HP)
	{
		this->Hitpoints = CLAP_HP;
		std::cout << "ClapTrap <" << this->name_ << "> is back at full hp!" << std::endl;
	}
	else
		std::cout << "ClapTrap <" << this->name_ << "> regains <" << amount
			  << "> Hitpoints" << std::endl;
}
//* ===============================================================================



//* ===============================================================================
//* ClapTrap SUBCLASS ---> ScavTrap
//* ===============================================================================


//* Constructors / Destructor
//* ===============================================================================
ScavTrap::ScavTrap() {
	this->name_ = "Scavvy";
	this->Hitpoints = SCAV_HP;
	this->EnergyPoints = SCAV_ENERGY;
	this->AttackDamage = SCAV_ATKDMG;

	std::cout << "\nScavTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	
	this->name_ = name;
	this->Hitpoints = SCAV_HP;
	this->EnergyPoints = SCAV_ENERGY;
	this->AttackDamage = SCAV_ATKDMG;

	std::cout << "\nScavTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;
}

ScavTrap::~ScavTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "\nScavTrap <" << this->name_ << "> leaves the arena.\n" << std::endl;
	else
		std::cout << "\nScavTrap <" << this->name_ << "> have been destroyed\n" << std::endl; 
}
//* ===============================================================================


//* Getter//Setter
//* ===============================================================================
int32_t ScavTrap::getHitpoints() {
	
	return (this->Hitpoints);
}

int32_t ScavTrap::getEnergy() {
	
	return (this->EnergyPoints);
}
//* ===============================================================================
