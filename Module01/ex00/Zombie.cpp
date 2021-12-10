/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:06:52 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 08:14:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

//* The Constructor. Called everytime a Class object is instanciated
Zombie::Zombie(const std::string& new_name) {
	
	this->name = new_name;
}

//* the Destructor. Called everytime a Class object is deleted
Zombie::~Zombie() {
	
	std::cout << name << "'s brain is all over the place!" << std::endl;
}

void Zombie::announce( void ) {
	
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
