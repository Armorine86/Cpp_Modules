/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:56:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 15:08:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//* Constructors / Destructor
//* ===============================================================================
ScavTrap::ScavTrap() : ClapTrap("BasicClapTrap") {
	
	this->name_ = "Scavvy";
	this->Hitpoints = SCAV_HP;
	this->EnergyPoints = SCAV_ENERGY;
	this->AttackDamage = SCAV_ATKDMG;

	std::cout << "\nScavTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	
	ScavTrap::name_ = name;
	Hitpoints = SCAV_HP;
	EnergyPoints = SCAV_ENERGY;
	AttackDamage = SCAV_ATKDMG;

	std::cout << "\nScavTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "\nScavTrap <" << this->name_ << "> have entered the fray!\n" << std::endl;
}



ScavTrap::~ScavTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "\nScavTrap <" << this->name_ << "> leaves the arena.\n" << std::endl;
	else
		std::cout << "\nScavTrap <" << this->name_ << "> have been destroyed\n" << std::endl; 
}

//* ===============================================================================

void ScavTrap::GuardGate() {
	
	std::cout << "Look out, everybody, things are about to get awesome!" << std::endl;
}

std::string ScavTrap::getName() {
	
	return (this->name_);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {

	if (this != &rhs)
	{
		this->name_ = rhs.name_;
		this->Hitpoints = rhs.Hitpoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDamage = rhs.AttackDamage;
		return (*this);
	}
	return (*this);
}
