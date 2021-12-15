/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:47 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 10:36:35 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ressources
* https://stackoverflow.com/questions/3402702/converting-floating-point-to-32-bit-fixed-point-in-java/
* https://www.youtube.com/watch?v=gc1Nl3mmCuY
* https://www.geeksforgeeks.org/introduction-of-floating-point-representation/
* https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
*/

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

//* Fractal Bits Initializer
const int32_t Fixed::bits = 8;


//* Constructors
//==================================================================
Fixed::Fixed() {
	
	value = 0;
}

//* Copy Constructor
Fixed::Fixed(const Fixed &def_c) {

	*this = def_c;
}

Fixed::Fixed(const int32_t value) {
	
	this->value = (value << bits);
}

Fixed::Fixed(const float value) {
	
	this->value = roundf(value * (float)(1 << bits));
}
//==================================================================

//* Destructor
//==================================================================
Fixed::~Fixed() {

}
//==================================================================


//* Methods
//==================================================================
int32_t Fixed::getRawBits(void) const {

	return (value);
}

void Fixed::setRawBits(const int32_t raw) {
	
	value = raw;
}

float Fixed::toFloat(void) const {
	
	return ((float)value / (float)(1 << bits)); //* the first bit of the mantissa (to the left of the binary point) is always "1" and therefore need not be stored. 
												//* It is called the implicit leading one.
}

int32_t Fixed::toInt(void) const {
	
	return (value >> bits);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	
	if (f1.value < f2.value)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	
	if (f1.value > f2.value)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	
	if (f1.value > f2.value)
		return (f1);
	return (f2);
}
//===================================================================


//* Assignment Operator Overloading
//===================================================================
Fixed& Fixed::operator=(const Fixed& rhs) {
	
	if (this != &rhs) //* Very important to make sure we're not dealing with the same object in memory
		value = rhs.getRawBits();
	return (*this);
}
//===================================================================


//* Comparison Operator Overload
//===================================================================
bool Fixed::operator<(const Fixed &rhs) const {

	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const {

	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const {

	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const {

	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const {

	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const {

	return (this->getRawBits() != rhs.getRawBits());
}
//===================================================================


//* Arithmetic Operator Overload
//===================================================================
Fixed Fixed::operator+(const Fixed &rhs) const {

	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
//===================================================================


//* Incrementor / Decrementor Operator Overload
//==================================================================
Fixed Fixed::operator--(int32_t) {
	
	Fixed decrement = *this;
	--*this;

	return (decrement);
}

Fixed& Fixed::operator--() {

	value--;
	return (*this);
}

Fixed Fixed::operator++(int32_t) {
	
	Fixed increment = *this;
	++*this;
	
	return (increment);
}

Fixed& Fixed::operator++() {

	value++;
	return (*this);
}
//===================================================================


//* Output operator Overload
//==================================================================
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	
	out << value.toFloat();
	return (out);
}
//==================================================================
