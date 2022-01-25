/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:47 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 14:31:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

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


Fixed::Fixed(const int32_t value) {
	
	// we want the fixed point number to have 8 bits for the fractional part
	// so we shit the bits to the left by 8;
	// 00000000 00000000 00000000 00000000
	// BECOMES
	// 00000000 00000000 00000000 . 00000000
	//							    |   ^  |
	//				Fractional part-----|
	std::cout << "Int Constructor Called" << std::endl;
	this->value = (value << bits);
}


Fixed::Fixed(const float value) {
	
	std::cout << "Float Constructor Called" << std::endl;
	this->value = roundf(value * (float)(1 << bits));
}


int32_t Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}


void Fixed::setRawBits(const int32_t raw) {
	
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}


float Fixed::toFloat(void) const
{
	//* the first bit of the mantissa (to the left of the binary point)
	//* is always "1" and therefore need not be stored. 
	//* It is called the implicit leading one.
	//* Because of that you cannot ever represent 0 ever.
	return ((float)value / (1 << bits));
}


int32_t Fixed::toInt(void) const
{
	// Since we only have 8 bits for the fractional part we shift 8 bits to the left
	// leaving us with a full 32-bits integer.
	// shifting one to the right is like dividing by two on integers
	return (value >> bits);
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

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	
	out << value.toFloat();
	return (out);
}

/* Ressources
* https://stackoverflow.com/questions/34027converting-floating-point-to-32-bit-fixed-point-in-java/
* https://www.youtube.com/watch?v=gc1Nl3mmCuY
* https://www.geeksforgeeks.org/introduction-of-floating-point-representation/
*/
