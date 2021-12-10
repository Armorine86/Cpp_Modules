/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:40 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 08:11:23 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanA.hpp"

HumanA::HumanA(const std::string firstname, Weapon& club_) {

	name = firstname;
	weapon = club_; //TODO Why can't I assign this->weapon to pass by ref weapon_
}

HumanA::HumanA(const std::string firstname, Weapon& weapon) : name(firstname), weapon(weapon) {}

void HumanA::attack() const {
	
	std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}

