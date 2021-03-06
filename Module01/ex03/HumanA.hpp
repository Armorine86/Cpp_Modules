/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:49 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 15:15:16 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Weapon.hpp"


class HumanA {

	private:
		std::string name;
		Weapon& weapon;
	
	public:
		HumanA(const std::string& firstname, Weapon& club_);
		void attack() const;
};

