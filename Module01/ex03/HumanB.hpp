/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:04:33 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 15:33:26 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Weapon.hpp"

class HumanB {

	// Since HumanB may not start with a weapon, we need to set it as a pointer
	// so we can assign a weapon later on. Which we could not do with a reference.
	// A reference CANNOT be null.
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanB(const std::string name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};
