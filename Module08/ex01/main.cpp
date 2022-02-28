/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:32 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/28 10:18:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include "colors.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << GREEN << "======================\n";
		std::cout << "|| EMPTY ARRAY TEST ||\n";
		std::cout << "======================\n" << END << std::endl;

		Span vec1;
		
		try {
			vec1.longestSpan();
		} catch (std::exception &e) {
			std::cout 	<< ORANGE << e.what() << ": "
						<< BRED << "No Long Span" << END << std::endl;
		}

		try {
			vec1.shortestSpan();
		} catch (std::exception &e) {
			std::cout << ORANGE << e.what() << ": " << BRED << "No Short Span" << END << std::endl;
		}

		std::cout << std::endl;
		
		std::cout << GREEN << "=========================\n";
		std::cout << "|| SIZE ONE ARRAY TEST ||\n";
		std::cout << "=========================\n" << END << std::endl;

		Span vec2(1);

		vec2.addNumber(1);
		
		try {
			vec1.longestSpan();
		} catch (std::exception &e) {
			std::cout 	<< ORANGE << e.what() << ": "
						<< BRED << "No Long Span" << END << std::endl;
		}

		try {
			vec1.shortestSpan();
		} catch (std::exception &e) {
			std::cout 	<< ORANGE << e.what() << ": "
						<< BRED << "No Short Span" << END << std::endl;
		}

	}
	
	std::cout << std::endl;
	
	{
		std::cout << GREEN << "====================\n";
		std::cout << "|| MAX ARRAY TEST ||\n";
		std::cout << "====================\n" << END << std::endl;
		
		Span vec1(MAX);

		vec1.random_populate();

		try {
			vec1.addNumber(1);
		} catch (std::exception &e) {
			std::cout 	<< ORANGE << e.what() << ": "
						<< BRED << "Max Capacity Reached" << END << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "=======================\n";
		std::cout << "|| ADDING ARRAY TEST ||\n";
		std::cout << "=======================\n" << END << std::endl;

		Span vec1(5);

		vec1.addNumber(1);
		vec1.addNumber(2);
		vec1.addNumber(3);
		vec1.addNumber(4);
		vec1.addNumber(5);

		std::cout << "Vector: ";
		vec1.print_vector();

		try {
			vec1.addNumber(6);
		} catch (std::exception &e) {
			std::cout	<< ORANGE << e.what() << ": "
						<< BRED << "Max Capacity Reached" << END << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "===========================\n";
		std::cout << "|| BIG RANDOM ARRAY TEST ||\n";
		std::cout << "===========================\n" << END << std::endl;

		Span vec(MAX);

		vec.random_populate();
		
		std::cout << "Vector Size: " << vec.getSize() << "\n" << std::endl;
		std::cout << "Short Span: " << vec.shortestSpan() << std::endl;
		

		std::cout << "\nLong Span: " << vec.longestSpan() << std::endl;
		
	}

	std::cout << std::endl;
}
