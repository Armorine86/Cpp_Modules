/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:56 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 10:40:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

class Fixed
{

private:
	int32_t value;			   //* fixed point number --> A number that can hold fractional bits.
	static const int32_t bits; //* Number of fractional bits (after the ",")

public:
	//* Constructors
	Fixed();
	~Fixed();
	Fixed(const int32_t value);
	Fixed(const float value);
	Fixed(const Fixed&);

	//* Setter // Getters
	int32_t getRawBits(void) const;
	void setRawBits(const int32_t raw);
	
	//* Methods
	float toFloat(void) const;
	int32_t toInt(void) const;
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
	
	//* Assignment Operator Overload
	Fixed &operator=(const Fixed &rhs); //* rhs = Right hand side
	
	//*Comparison Operator Overloads
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	//* Arithmetic Operators Overload
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	//* Incrementor / Decrementor Operators Overload
	Fixed &operator++();			//* Prefix increment operator
	Fixed &operator--();			//* Prefix decrement oprator
	Fixed operator++(int32_t); 	//* Postfix increment operator
	Fixed operator--(int32_t); 	//* Postfic decrement operator
	

};

//* outside the class because it's not for the class itself but ostream class.
std::ostream &operator<<(std::ostream &out, const Fixed &value);
