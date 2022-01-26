/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:39:17 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 12:36:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog Subclass Constructor called [DEFAULT]" << std::endl;
}

Dog::Dog(std::string type) : Animal()
{
    this->type = type;
    std::cout << "Doc Subclass Overload Constructor called [CONSTRUCTOR]" << std::endl;
}

Dog::Dog(const Dog& src)
{
    *this = src;
    std::cout << "Dog Subclass Copy Constructor Called [COPY]" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if (this != &rhs) {
        this->type = rhs.type;
        return (*this);
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "[" << getType() << "] " << "Wouf Wouf !"  << std::endl;
}
