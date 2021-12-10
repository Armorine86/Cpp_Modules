/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:04:33 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 21:33:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Weapon.hpp"

class HumanB {

	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanB(const std::string name);
		void setWeapon(Weapon& weapon);
		void attack() const;
};
