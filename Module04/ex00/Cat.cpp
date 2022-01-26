/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:57:19 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 12:37:10 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

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
    *this = src;
    std::cout << "Cat Subclass Copy Constructor Called [COPY]" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
    if (this != &rhs) {
        this->type = rhs.type;
        return (*this);
    }
    return (*this);
}

void Cat::makeSound() const
{
    // since this function is virtual, this will be called instead of the one
    // in the Parent Class
    std::cout << "[" << getType() << "] " << "Meow Meow !"  << std::endl;
}
