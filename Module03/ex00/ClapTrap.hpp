/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:58:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 09:17:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>

#define HITPOINTS 10
#define ENERGY 10
#define ATK_DAMAGE 0

class ClapTrap {

	private:
		std::string name_;
		int32_t Hitpoints;
		int32_t EnergyPoints;
		int32_t AttackDamage;
	
	public:
		//* According to Module 2 bonus rule, Every class needs a
		//* Default Constructor, Copy constructor
		//* a Destructor and an Operator Overload functions
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& rhs);
		
		//* Methods
		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
