/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:36:08 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 15:47:35 by mmondell         ###   ########.fr       */
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
		virtual ~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap& rhs);
		
		virtual void attack(const std::string& target);

		void whoAmI();
};


//* https://www.makeuseof.com/what-is-diamond-problem-in-cpp/   README !
