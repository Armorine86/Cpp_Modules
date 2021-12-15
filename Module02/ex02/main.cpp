/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:46:05 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 08:16:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Fixed.hpp"

int main(void)
{
	std::cout << "\nPart One\n";
	std::cout << "===========================\n" << std::endl;
	{	
		Fixed a;
		Fixed const b(10);
		Fixed const c(42.42f);
		Fixed const d(b);

		a = Fixed(1234.4321f);
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}

	//* Part Two
	std::cout << "\n\nPart Two\n";
	std::cout << "===========================\n" << std::endl;
	{
		Fixed       a;
    const Fixed b(Fixed(5.05f) * Fixed(2));
    Fixed       c(9.87f);
    Fixed       d(c);

    std::cout << "a   = " << a << '\n';
    std::cout << "++a = " << ++a << '\n';
    std::cout << "a   = " << a << '\n';
    std::cout << "a++ = " << a++ << '\n';
    std::cout << "a   = " << a << '\n';
    std::cout << "--a = " << --a << '\n';
    std::cout << "a   = " << a << '\n';
    std::cout << "a-- = " << a-- << '\n';
    std::cout << "a   = " << a << "\n\n";

    std::cout << "b = " << b << '\n';
    std::cout << "a = " << a << '\n';
    std::cout << "max(a, b) = " << Fixed::max(a, b) << "\n\n";

    Fixed t = Fixed::max(c, a);
    t.setRawBits(0xFF0FA);
    t = Fixed::min(a, d);
    t.setRawBits(0xFF0FA);

    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << '\n';
    std::cout << "min(b, c) = " << Fixed::min(b, c) << "\n\n";

    std::cout << "4.3f + 7.78 = " << 4.3f + 7.78f << '\n';
    std::cout << "c + 4.5 = " << c + Fixed(4.5f) << "\n\n";

    std::cout << "4.3f - 7.78f = " << 4.3f - 7.78f << '\n';
    std::cout << "c - 4.5 = " << c - Fixed(7.78f) << "\n\n";

    std::cout << "4.3f * 7.78f = " << 4.3f * 7.78f << '\n';
    std::cout << "c * 4.5 = " << c * Fixed(7.78f) << "\n\n";

    std::cout << "4.3f / 7.78f = " << 4.3f / 7.78f << '\n';
    std::cout << "c / 4.5 = " << c / Fixed(4.5f) << "\n\n";

    std::cout << std::setw(7) << a << std::setw(4) << " > " << std::setw(7) << b << " = "
              << std::boolalpha << (a > b) << std::endl;
    std::cout << std::setw(7) << c << std::setw(4) << " >= " << std::setw(7) << d << " = "
              << std::boolalpha << (c >= d) << std::endl;
    std::cout << std::setw(7) << a << std::setw(4) << " < " << std::setw(7) << b << " = "
              << std::boolalpha << (a < b) << std::endl;
    std::cout << std::setw(7) << c << std::setw(4) << " <= " << std::setw(7) << d << " = "
              << std::boolalpha << (c <= d) << std::endl;
    std::cout << std::setw(7) << c << std::setw(4) << " <= " << std::setw(7) << b << " = "
              << std::boolalpha << (c <= b) << std::endl;
    std::cout << std::setw(7) << a << std::setw(4) << " == " << std::setw(7) << b << " = "
              << std::boolalpha << (a == b) << std::endl;
    std::cout << std::setw(7) << c << std::setw(4) << " == " << std::setw(7) << d << " = "
              << std::boolalpha << (c == d) << std::endl;
	}
	
	
	return (0);
}
