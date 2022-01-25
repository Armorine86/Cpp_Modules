/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:56 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 09:26:41 by mmondell         ###   ########.fr       */
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
	Fixed();
	~Fixed();
	Fixed(const int32_t value);
	Fixed(const float value);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs); //* rhs = Right hand side
	
	int32_t getRawBits(void) const;
	void setRawBits(const int32_t raw);
	float toFloat(void) const;
	int32_t toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);
