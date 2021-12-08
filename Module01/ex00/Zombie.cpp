/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:06:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/08 14:47:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(const std::string& new_name) {
	
	this->name = new_name;
}

Zombie::~Zombie() {
	
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce( void ) {
	
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
