/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:39:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:35:10 by mmondell         ###   ########.fr       */
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
    std::cout << "Wouf Wouf ! [DOG]" << std::endl;
}
