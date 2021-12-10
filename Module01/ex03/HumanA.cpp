/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:40 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 21:37:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "HumanA.hpp"

HumanA::HumanA(const std::string firstname, Weapon &weapon) 
{
	this->name = firstname;
	this->weapon = &weapon;
}

void HumanA::attack() const
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

