/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:50:38 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/27 08:21:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_ATKDMG 20

//* ScavTrap Subclass inherits from ClapTrap
class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
		virtual ~ScavTrap();
		ScavTrap& operator=(const ScavTrap& rhs);
		
		// virtual keyword override the same function in the parent Class
		// so this one is called instead of ClapTrap one
		virtual void attack(const std::string& target);
		
		// since this function doesn't exist in parent Class we don't need to prefix
		// virtual in front of the function.
		void GuardGate();
		
};
