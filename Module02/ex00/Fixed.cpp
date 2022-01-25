/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:47 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 09:23:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

const int32_t Fixed::bits = 8;

Fixed::Fixed() : value(0) {
	
	std::cout << "Default Constructor Called" << std::endl;
}

//* Copy Constructor
Fixed::Fixed(const Fixed &src) {

	std::cout << "Copy Constructor Called" << std::endl;
	
	*this = src;
}

Fixed::~Fixed() {

	std::cout << "Destructor Called" << std::endl;
}

//* Operator Overloading
Fixed& Fixed::operator=(const Fixed& rhs) {

	std::cout << "Assignation operator called" << std::endl;
	
	//* Very important to make sure we're not dealing with the same object in memory
	if (this != &rhs) {
		value = rhs.getRawBits();
		return (*this);
	}
	return (*this);
}

int32_t Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}
