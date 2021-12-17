/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:50:38 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 12:27:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_ATKDMG 20

class ScavTrap : virtual public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();
		
		void GuardGate();
		virtual void attack(const std::string& target);
		
		ScavTrap& operator=(const ScavTrap& rhs);
};
