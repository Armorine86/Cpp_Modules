/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/14 12:20:58 by mmondell         ###   ########.fr       */
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
Fixed::Fixed(const Fixed &def_c) {

	std::cout << "Copy Constructor Called" << std::endl;
	
	*this = def_c;
}


Fixed::~Fixed() {

	std::cout << "Destructor Called" << std::endl;
}


Fixed::Fixed(const int32_t value) : value(value << bits) {
	
	std::cout << "Int Constructor Called" << std::endl;
}


Fixed::Fixed(const float value) : value((int)roundf(value * (float)(1 << bits))) {
	
	std::cout << "Float Constructor Called" << std::endl;
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
	return ((float)value / (float)(1 << bits));
}


int32_t Fixed::toInt(void) const
{
	return (value >> bits);
}

//* Operator Overloading
Fixed& Fixed::operator=(const Fixed& rhs) {

	std::cout << "Assignation operator called" << std::endl;
	
	if (this != &rhs) //* Very important to make sure we're not dealing with the same object in memory
		value = rhs.getRawBits();
	return (*this);
}


std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	
	out << value.toFloat();
	return (out);
}

/* Ressources
* https://stackoverflow.com/questions/3402702/converting-floating-point-to-32-bit-fixed-point-in-java/
* https://www.youtube.com/watch?v=gc1Nl3mmCuY
* https://www.geeksforgeeks.org/introduction-of-floating-point-representation/
*/
