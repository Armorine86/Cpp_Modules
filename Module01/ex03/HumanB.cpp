/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:04:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 21:40:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <HumanB.hpp>

HumanB::HumanB(const std::string name) {
	
	this->name = name;	
}

void HumanB::setWeapon(Weapon& weapon) {
	
	this->weapon = &weapon;
}

void HumanB::attack() const {
	
	if (!this->weapon)
		std::cout << this->name << " doesn't have a weapon " << std::endl;
	else
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
