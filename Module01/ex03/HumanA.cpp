/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:40 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 20:37:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanA.hpp"

//* the ":" initiates the variable directly. this way we can pass
//* the weapon by reference. That part of the Constructor is called
//* Constructor Initializer list, and is better performance wise.
HumanA::HumanA(const std::string& firstname, Weapon& weapon) : name(firstname), weapon(weapon) {}

void HumanA::attack() const {
	
	std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}

