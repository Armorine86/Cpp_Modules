/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:08:36 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 12:51:54 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"

int main(void)
{
    std::cout << GREEN << "\n===============================================\n";
    std::cout << "||    Basic Bureaucrat Constructor Tests     ||";
    std::cout << "\n===============================================" << END << std::endl;
    
    try {
        Bureaucrat rogers("Rogers", HIGHEST);
        std::cout << rogers;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    try {
        Form testForm("testForm", 100);
        std::cout << testForm;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    std::cout << GREEN << "\n===================================================\n";
    std::cout << "||    Bureaucrat Constructor Exception Tests     ||";
    std::cout << "\n===================================================" << END << std::endl;
    
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

    std::cout << GREEN << "\n==========================\n";
    std::cout << "|| Rank UP / DOWN Tests ||";
    std::cout << "\n==========================" << END << std::endl;
    
    try {
        Bureaucrat lawrence("Lawrence", HIGHEST);
        std::cout << lawrence;

        std::cout << std::endl;
        lawrence.rankUp();

        std::cout << lawrence;  //* Should Not Print
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

        std::cout << lawrence;  //* Should Not Print
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }

    std::cout << std::endl;

    std::cout << GREEN << "\n======================================\n";
    std::cout << "|| Form Constructor Exception Tests ||";
    std::cout << "\n======================================" << END << std::endl;
    
    try {
        Form SoulContract("Relinquish Soul's Ownership", HIGHEST - 1);
        std::cout << SoulContract;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    try {
        Form SoulContract("Relinquish Soul's Ownership", LOWEST + 1);
        std::cout << SoulContract;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    std::cout << GREEN << "\n===============================\n";
    std::cout << "||      Signature Tests      ||";
    std::cout << "\n===============================" << END << std::endl;
    
    try {
        Bureaucrat rogers("Rogers", 131);
        std::cout << rogers;
        std::cout << std::endl;

        Form CoffeeForTheBoss("CoffeeForTheBoss", 135);
        std::cout << CoffeeForTheBoss;
        std::cout << std::endl;

        rogers.signForm(CoffeeForTheBoss);
        std::cout << std::endl;

        Form SoulContract("Relinquish Soul's Ownership", 120);
        std::cout << SoulContract;
        std::cout << std::endl;

        rogers.signForm(SoulContract);
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    std::cout << GREEN << "\n===============================\n";
    std::cout << "|| Already Signed Form Tests ||";
    std::cout << "\n===============================" << END << std::endl;
    
    try {
        Bureaucrat rogers("Rogers", 131);
        std::cout << rogers;
        std::cout << std::endl;

        Bureaucrat seymour("Seymour", 75);
        std::cout << seymour;
        std::cout << std::endl;

        Form CoffeeForTheBoss("CoffeeForTheBoss", 135);
        std::cout << CoffeeForTheBoss;
        std::cout << std::endl;

        rogers.signForm(CoffeeForTheBoss);
        std::cout << std::endl;

        seymour.signForm(CoffeeForTheBoss);
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }
    std::cout << std::endl;
}
