/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:57:19 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:21:56 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat Subclass Constructor Called [DEFAULT]" << std::endl;
}

Cat::Cat(std::string type) : Animal()
{
	this->type = type;
	std::cout << "Cat Subclass Overload Constructor Called [OVERLOARD]" << std::endl;
}

Cat::Cat(const Cat& src) 
{
	this->type = src.type;
	std::cout << "Cat Subclass Copy Constructor Called [COPY]" << std::endl;
}

Cat::~Cat() 
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) 
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		return (*this);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow ! [CAT]" << std::endl;
}