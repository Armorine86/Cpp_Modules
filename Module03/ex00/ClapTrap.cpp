/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 12:45:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

//* Constructors // Destructor
//* ===============================================================================
ClapTrap::ClapTrap() :
	name_("StandardClap"),
	Hitpoints(HITPOINTS),
	EnergyPoints(ENERGY),
	AttackDamage(ATK_DAMAGE)
{ std::cout << "ClapTrap <" << this->name_ << "> have been constructed!" << std::endl; }

ClapTrap::ClapTrap(const std::string& name) :
	name_(name),
	Hitpoints(HITPOINTS),
	EnergyPoints(ENERGY),
	AttackDamage(ATK_DAMAGE)
	{ std::cout << "ClapTrap <" << this->name_ << "> have been constructed!" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& src) 
{
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "ClapTrap <" << this->name_ << "> have been constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
	
	std::cout << "ClapTrap <" << this->name_ << "> have been destroyed" << std::endl; 
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

	std::cout << "ClapTrap <" << this->name_ << "> gets hit for <" << amount
			  << "> damage!" << std::endl;

	this->Hitpoints -= amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->Hitpoints
			  << "> Hitpoints left!\n" << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount) {
	
	this->Hitpoints += amount;
	if (this->Hitpoints >= HITPOINTS)
	{
		this->Hitpoints = HITPOINTS;
		std::cout << "ClapTrap <" << this->name_ << "> is back at full hp!" << std::endl;
	}
	else
		std::cout << "ClapTrap <" << this->name_ << "> regains <" << amount
			  << "> Hitpoints" << std::endl;
	
	this->EnergyPoints -= amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->EnergyPoints
			  << "> Energy left!\n" << std::endl;
	
}
//* ===============================================================================


//* Operator Overload
//* ===============================================================================
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {

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
//* ===============================================================================
