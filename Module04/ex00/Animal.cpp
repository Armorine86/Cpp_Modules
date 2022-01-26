/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:56:01 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 10:18:36 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Basic Animal")
{
    std::cout << "Base Class Animal Constructor [DEFAULT]" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    this->type = type;
    std::cout << "Base Class Animal Constructor [OVERLOAD]" << std::endl;
}

Animal::Animal(const Animal& src)
{
    *this = src;
    std::cout << "Base Class Animal Constructor Called [COPY]" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    if (this != &rhs) {
        this->type = rhs.type;
        return (*this);
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "[Random Animal Noises]" << std::endl;
}
