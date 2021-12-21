/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:04:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:21:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <HumanB.hpp>

HumanB::HumanB(const std::string name) {
	
	this->weapon = NULL;
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
