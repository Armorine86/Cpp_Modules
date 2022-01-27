/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:58:45 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/27 08:41:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>
#include <iostream>

#define CLAP_HP 10
#define CLAP_ENERGY 10
#define CLAP_ATKDMG 0

class ClapTrap {

	// Private members are only accessible trough methods of the same class
	// Protected members will also be available to subclasses.
	protected:
		std::string name_;
		int32_t Hitpoints;
		int32_t EnergyPoints;
		int32_t AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& rhs);

		virtual void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};
