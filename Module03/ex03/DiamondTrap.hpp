/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:36:08 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 12:27:25 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string name_;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& rhs);
		
		virtual void attack(const std::string& target);

		void whoAmI();
};


//* https://www.makeuseof.com/what-is-diamond-problem-in-cpp/   README !
