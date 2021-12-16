/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:50:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 15:25:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_ATKDMG 20

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		virtual ~ScavTrap();
		
		void GuardGate();
		void attack(const std::string& target);
		std::string getName();
		
		ScavTrap& operator=(const ScavTrap& rhs);
};
