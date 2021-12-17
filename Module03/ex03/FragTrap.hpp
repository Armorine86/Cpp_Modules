/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:37:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/17 14:01:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

#define FRAG_HP 100
#define FRAG_ENERGY 100
#define FRAG_ATKDMG 30

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& src);
		virtual ~FragTrap();
		FragTrap& operator=(const FragTrap& rhs);

		virtual void attack(const std::string& target);

		void highFivesGuys();
};
