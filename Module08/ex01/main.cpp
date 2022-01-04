/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:32 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/04 15:58:05 by mmondell         ###   ########.fr       */
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
		
		Span sp0(0); // Size 0
		
		std::cout << GREEN << "sp0: \n" << END;
		try {
			std::cout << "Short span: " << sp0.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << END << std::endl;
		}

		try {
			std::cout << "Long span: " << sp0.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << END << std::endl;
		}

		std::cout << std::endl;

		Span sp1(1); //size 1
		
		std::cout << GREEN << "sp1: \n" << END;
		try {
			std::cout << "Short span: " << sp1.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << END << std::endl;
		}

		try {
			std::cout << "Long span: " << sp1.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << END << std::endl;
		}
	}
	
	std::cout << std::endl;

	{
		std::cout << GREEN << "=====================\n";
		std::cout << "|| ADD NUMBER TEST ||\n";
		std::cout << "=====================\n" << END << std::endl;
		
		Span sp(5); //size 5
		
		try {
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "Short span: " << sp.shortestSpan() << std::endl;
			std::cout << "Long span: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl;

	{
		std::cout << GREEN << "===============================\n";
		std::cout << "|| ADD NUMBER EXCEPTION TEST ||\n";
		std::cout << "===============================\n" << END << std::endl;
		
		try {
			Span sp(MAX);

			sp.random_populate();
			sp.addNumber(5); // should throw an exception
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl;

	{
		std::cout << GREEN << "=========================\n";
		std::cout << "|| BIG ARRAY SPAN TEST ||\n";
		std::cout << "=========================\n" << END << std::endl;
		
		try {
			Span sp(MAX);

			sp.random_populate();

			std::cout << "Short span: " << sp.shortestSpan() << std::endl;
			std::cout << "Long span: " << sp.longestSpan() << std::endl;
					
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
}
