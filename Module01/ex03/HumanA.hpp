/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 21:21:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Weapon.hpp"


class HumanA {

	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanA(const std::string firstname, Weapon &weapon);
		void attack() const;
};

