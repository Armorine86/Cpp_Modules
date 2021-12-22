/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:17:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/22 07:51:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "colors.hpp"

int main(void)
{
    std::cout << "\n\nConstructor Exception Checks\n";
    std::cout << "=============================" << std::endl;

    try {
        Bureaucrat high("John", HIGHEST);
        std::cout << high;                  //* ostream test
        std::cout << std::endl;
        Bureaucrat low("Jack", LOWEST);
        std::cout << low;                   //* ostream test
        std::cout << std::endl;

        Bureaucrat tooHigh("Clarence", 0);  //* Should throw an exception

        //* Should Not be Executed
        std::cout << tooHigh;
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }

    std::cout << "\n\nRanking Up/Down Exception Checks\n";
    std::cout << "=================================" << std::endl;

    try {
        Bureaucrat lawrence("Lawrence", HIGHEST);
        std::cout << lawrence;

        std::cout << std::endl;
        lawrence.rankDown();

        std::cout << lawrence;
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat peter("Peter", LOWEST);
        std::cout << peter;
        std::cout << std::endl;
        try {
            peter.rankDown();
            std::cout << std::endl;

            //* should not be executed
            std::cout << peter;
        } catch (std::exception &exc) {
            std::cerr << RED << exc.what() << END << std::endl;
        }
    } catch (std::exception &exc) {
        std::cout << RED << exc.what() << END << std::endl;
    }
    std::cout << std::endl;
}
