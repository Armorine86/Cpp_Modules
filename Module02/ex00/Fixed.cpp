/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/14 10:20:38 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

const int32_t Fixed::bits = 8;

Fixed::Fixed() : value(0) {
	
	std::cout << "Default Constructor Called" << std::endl;
}

//* Copy Constructor
Fixed::Fixed(const Fixed &def_c) {

	std::cout << "Copy Constructor Called" << std::endl;
	
	*this = def_c;
}

Fixed::~Fixed() {

	std::cout << "Destructor Called" << std::endl;
}

int32_t Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(const int32_t raw) {
	
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

//* Operator Overloading
Fixed& Fixed::operator=(const Fixed& rhs) {

	std::cout << "Assignation operator called" << std::endl;
	
	if (this != &rhs) //* Very important to make sure we're not dealing with the same object in memory
		value = rhs.getRawBits();
	return (*this);
}
