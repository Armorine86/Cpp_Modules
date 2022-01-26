/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:57:14 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 12:36:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    
    std::cout << "WrongCat Subclass Constructor [DEFAULT]" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
    *this = src;

    std::cout << "WrongCat Subclass Constructor [COPY]" << std::endl;
}

WrongCat::WrongCat(const std::string& type)
{
    this->type = type;

    std::cout << "WrongCat Subclass Constructor [OVERLOAD]" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat has been destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if (this != &rhs) {
        this->type = rhs.type;
        return (*this);
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    // Since this function is not virtual, it will be called from WrongAnimal Parent Class
    std::cout << "WrongCat Noise: Wouf Wouf !" << std::endl;
}
