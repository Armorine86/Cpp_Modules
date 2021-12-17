/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 14:01:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"


//* Constructors // Destructor
//* ===============================================================================

//* Default Constructor
ClapTrap::ClapTrap() :
	name_("BasicClapTrap"),
	Hitpoints(CLAP_HP),
	EnergyPoints(CLAP_ENERGY),
	AttackDamage(CLAP_ATKDMG)
	{ std::cout << "ClapTrap <" << this->name_ << "> have entered the fray! [DEFAULT]" << std::endl; }

//* Constructor Overload
ClapTrap::ClapTrap(const std::string& name) :
	name_(name),
	Hitpoints(CLAP_HP),
	EnergyPoints(CLAP_ENERGY),
	AttackDamage(CLAP_ATKDMG)
	{std::cout << "ClapTrap <" << this->name_ << "> have entered the fray! [OVERLOAD]" << std::endl;}

//* Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& src) 
{
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "ClapTrap <" << this->name_ << "> have entered the fray! [COPY]" << std::endl;
}

//* Destructor
ClapTrap::~ClapTrap() {
	
	if (this->Hitpoints > 0)
		std::cout << "ClapTrap <" << this->name_ << "> leaves the arena." << std::endl;
	else
		std::cout << "ClapTrap <" << this->name_ << "> have been destroyed" << std::endl; 
}
//* ===============================================================================


//* Methods
//* ===============================================================================
void ClapTrap::attack(std::string const& target) {

	std::cout << "ClapTrap <" << this->name_ << "> attack <" << target
			  << ">, causing <" << this->AttackDamage << "> points of damage!"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	this->Hitpoints -= amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> gets hit for <" << amount
			  << "> damage!" << std::endl;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->Hitpoints
			  << "> Hitpoints left!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {
	
	if ((int32_t)amount > this->EnergyPoints)
		amount = this->EnergyPoints;
		
	this->EnergyPoints -= amount;
	this->Hitpoints += amount;
	
	std::cout << "ClapTrap <" << this->name_ << "> have <" << this->EnergyPoints
			  << "> Energy left!" << std::endl;

	std::cout << "ClapTrap <" << this->name_ << "> regains <" << amount
			  << "> Hitpoints" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) 
{
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
