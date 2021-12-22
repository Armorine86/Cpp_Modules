/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:17:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 10:28:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "colors.hpp"

int main(void)
{
    std::cout << GREEN <<"\n===============================================\n";
	std::cout << "||    Basic Bureaucrat Constructor Tests     ||";
	std::cout << "\n===============================================" << END <<  std::endl;
    try {
        Bureaucrat rogers("Rogers", HIGHEST);
		std::cout << rogers;
		std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
	
	std::cout << std::endl;
    
    std::cout << GREEN <<"\n===================================================\n";
	std::cout << "||    Bureaucrat Constructor Exception Tests     ||";
	std::cout << "\n===================================================" << END <<  std::endl;
    try {
        Bureaucrat rogers("Rogers", HIGHEST - 1);
		std::cout << rogers;
		std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
	
	std::cout << std::endl;

	try {
        Bureaucrat rogers("Rogers", LOWEST + 1);
		std::cout << rogers;
		std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
	
	std::cout << std::endl;

	std::cout << GREEN <<"\n==========================\n";
	std::cout << "|| Rank UP / DOWN Tests ||";
	std::cout << "\n==========================" << END <<  std::endl;
	try {
        Bureaucrat lawrence("Lawrence", HIGHEST);
        std::cout << lawrence;

        std::cout << std::endl;
        lawrence.rankUp();

        std::cout << lawrence; //* Should Not Print
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }

    std::cout << std::endl;
	
	try {
        Bureaucrat lawrence("Lawrence", LOWEST);
        std::cout << lawrence;

        std::cout << std::endl;
        lawrence.rankDown();

        std::cout << lawrence; //* Should Not Print
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }
}
