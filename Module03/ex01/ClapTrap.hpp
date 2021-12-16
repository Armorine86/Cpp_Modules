/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:58:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 09:50:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>

#define CLAP_HP 10
#define CLAP_ENERGY 10
#define CLAP_ATKDMG 0

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_ATKDMG 20

class ClapTrap {

	protected:
		std::string name_;
		int32_t Hitpoints;
		int32_t EnergyPoints;
		int32_t AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		int32_t getHitpoints();
		int32_t getEnergy();
		void setHitpoints(int32_t&);
		void setEnergy(int32_t&);
};
