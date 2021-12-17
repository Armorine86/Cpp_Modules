/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:56:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 14:01:29 by mmondell         ###   ########.fr       */
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

	std::cout << "ScavTrap <" << this->name_ << "> has arrived! [DEFAULT]" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	
	name_ = name;
	Hitpoints = SCAV_HP;
	EnergyPoints = SCAV_ENERGY;
	AttackDamage = SCAV_ATKDMG;

	std::cout << "ScavTrap <" << this->name_ << "> has arrived! [OVERLOAD]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "ScavTrap <" << this->name_ << "> has arrived! [COPY]" << std::endl;
}

ScavTrap::~ScavTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "ScavTrap <" << this->name_ << "> is leaving the battlefied" << std::endl;
	else
		std::cout << "ScavTrap <" << this->name_ << "> have been defeated" << std::endl;
}
//* ===============================================================================


//* METHODS
//* ===============================================================================
void ScavTrap::GuardGate() {
	
	std::cout << "ScavTrap <" << this->name_
			  << "> Look out, everybody, things are about to get awesome!"
			  << " [GATE KEEPER MODE IS ON!]" << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
	std::cout << "SkavTrap <" << this->name_ << "> attack <" << target
			  << ">, causing <" << this->AttackDamage << "> points of damage!"
			  << std::endl;
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
