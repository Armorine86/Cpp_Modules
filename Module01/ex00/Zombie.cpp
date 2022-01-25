/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:06:52 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:16:28 by mmondell         ###   ########.fr       */
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
	
	// Output this message when the Destructor is called
	std::cout << name << "'s brain is all over the place!" << std::endl;
}

// Zombie Class member function
//
// Only member function inside the class have access to the private members
void Zombie::announce( void ) {
	
	// name is a private member of the Zombie Class
	std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
