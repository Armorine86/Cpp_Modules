/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:51:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:10:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Base Class Constructor [DEFAULT]" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) 
{
	this->type = type;

	std::cout << "WrongAnimal Base Class Constructor Called [OVERLOAD]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) 
{
	*this = src;

	std::cout << "WrongAnimal Base Class Constructor called [COPY]" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) 
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		return (*this);
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal random noises" << std::endl;
}