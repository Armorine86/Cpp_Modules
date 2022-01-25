/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:03:59 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 15:23:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) {
	
	wep_type = type;
}

const std::string& Weapon::getType() const
{
	return (wep_type);
}

void Weapon::setType(const std::string type) 
{
	this->wep_type = type;
}

