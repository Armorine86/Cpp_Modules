/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:45:56 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 08:44:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

class Fixed {

	private:
		int32_t value;  //* fixed point number --> A number that can holds fractional bits.
		static const int32_t bits; //* Number of fractional bits (after the ",")
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& def_c);
		int32_t getRawBits(void) const;
		void setRawBits(const int32_t raw);
		Fixed& operator=(const Fixed& rhs); //* rhs = Right hand side
}; 
