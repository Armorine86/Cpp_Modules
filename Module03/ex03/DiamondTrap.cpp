/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:35:53 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 20:05:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


//*Constructors
//* ===============================================================================
DiamondTrap::DiamondTrap() : ClapTrap()
{
	name_ = "BasicClapTrap";
	Hitpoints = FragTrap::Hitpoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	
	std::cout << "DiamondTrap <" << this->name_ << "> have entered the fray! [DEFAULT]" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	name_(name)
{
	Hitpoints = FragTrap::Hitpoints;
	EnergyPoints = ScavTrap::EnergyPoints;
	AttackDamage = FragTrap::AttackDamage;
	
	std::cout << "DiamondTrap <" << this->name_ << "> have entered the fray! [OVERLOAD]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src)
{
	this->name_ = src.name_;
	this->Hitpoints = src.Hitpoints;
	this->EnergyPoints = src.EnergyPoints;
	this->AttackDamage = src.AttackDamage;
	
	std::cout << "DiamondTrap <" << this->name_ << "> have entered the fray! [COPY]" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
	if (this->Hitpoints > 0)
		std::cout << "FragTrap <" << this->name_ << "> Ha ha ha! Fall before your robot overlord! [DIAMOND]" << std::endl;
	else
		std::cout << "FragTrap <" << this->name_ << "> I'M DEAD I'M DEAD OHMYGOD I'M DEAD! [DIAMOND]"
				  << std::endl;
}
//* ===============================================================================


//* Operator Overload
//* ===============================================================================
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) 
{
	name_ = rhs.name_;
    Hitpoints = rhs.Hitpoints;
    EnergyPoints = rhs.EnergyPoints;
    AttackDamage = rhs.AttackDamage;

    return (*this);
}
//* ===============================================================================


//* Methods
//* ===============================================================================
void DiamondTrap::attack(const std::string& target) 
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() 
{
	std::cout << "I am a bit of: " << this->name_ << " and a bit of : " << ClapTrap::name_
			  << std::endl;
}
//* ===============================================================================
