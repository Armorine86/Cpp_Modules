/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:08:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 14:03:00 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "colors.hpp"

int main(void)
{
    std::cout << GREEN << "\n===============================================\n";
    std::cout << "||    Basic Bureaucrat Constructor Tests     ||";
    std::cout << "\n===============================================" << END << std::endl;
    try {
        Bureaucrat rogers("Rogers", HIGHEST, HIGHEST);
        std::cout << rogers;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    //* Form class is now Abstract and cannot be instanciated
    // try {
    //     Form testForm("testForm", 100, 100);
    //     std::cout << testForm;
    //     std::cout << std::endl;

    // } catch (std::exception &e) {
    //     std::cerr << RED << e.what() << END << std::endl;
    // }

    std::cout << std::endl;

    std::cout << GREEN << "\n===================================================\n";
    std::cout << "||    Bureaucrat Constructor Exception Tests     ||";
    std::cout << "\n===================================================" << END << std::endl;
    try {
        Bureaucrat rogers("Rogers", HIGHEST - 1, 100);
        std::cout << rogers;
        std::cout << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << END << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat rogers("Rogers", LOWEST + 1, 100);
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
        Bureaucrat lawrence("Lawrence", HIGHEST, HIGHEST);
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
        Bureaucrat lawrence("Lawrence", LOWEST, LOWEST);
        std::cout << lawrence;

        std::cout << std::endl;
        lawrence.rankDown();

        std::cout << lawrence;  //* Should Not Print
        std::cout << std::endl;
    } catch (std::exception &exc) {
        std::cerr << RED << exc.what() << END << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << GREEN << "\n===========================\n";
    std::cout << "|| FORM INHERITANCE TEST ||";
    std::cout << "\n===========================" << END << std::endl;
    {
        Bureaucrat Jones("Jones", 145, 145);
        std::cout << Jones << std::endl;
        std::cout << std::endl;
        
        Bureaucrat rogers("Rogers", 10, 50);
        std::cout << rogers << std::endl;
        std::cout << std::endl;
        
        Bureaucrat President("Jafod Beeblebrox", 1, 1);
        std::cout << President << std::endl;
        std::cout << std::endl;
        
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        std::cout << std::endl;
        
        RobotomyRequestForm robo(Jones.getName());
        std::cout << robo << std::endl;
        std::cout << std::endl;
        
        PresidentialPardonForm pardon(rogers.getName());
        std::cout << pardon << std::endl;
        std::cout << std::endl;
        
        try {
            shrub.beSigned(rogers);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;

        try {
            rogers.executeForm(shrub);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;

        try {
            robo.beSigned(rogers);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }

        std::cout << std::endl;

        try {
            rogers.executeForm(robo);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        try {
            pardon.beSigned(rogers);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }

        std::cout << std::endl;

        try {
            President.executeForm(pardon);
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << GREEN << "\n============================\n";
    std::cout << "||  INTERN MAKEFORM TEST  ||";
    std::cout << "\n============================" << END << std::endl;
    {
        Intern intern;
        
        Bureaucrat rogers("Rogers", 10, 10);
        Bureaucrat jones("Jones", 149, 149);

        std::cout << std::endl;
    
        Form *shrub = intern.makeForm("shrubbery request", "home");
        std::cout << *shrub << std::endl;

        Form *robo = intern.makeForm("robotomy request", jones.getName());
        std::cout << *robo << std::endl;
        
        Form *pardon = intern.makeForm("pardon request", jones.getName());
        std::cout << *pardon << std::endl;

        rogers.signForm(*shrub);
        rogers.signForm(*robo);
        rogers.signForm(*pardon);
    }

}
