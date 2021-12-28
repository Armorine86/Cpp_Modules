/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:08:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 14:32:21 by mmondell         ###   ########.fr       */
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
    std::cout << GREEN << "\n============================\n";
    std::cout << "||  INTERN MAKEFORM TEST  ||";
    std::cout << "\n============================" << END << std::endl;
    {
        Intern intern;
        
        Bureaucrat rogers("Rogers", 10, 10);
        Bureaucrat jones("Jones", 149, 149);
        Bureaucrat president("Jafod Beeblebrox", 1, 1);

        std::cout << std::endl;
    
        try {
            Form *robo = intern.makeForm("robotomy request", jones.getName());
            std::cout << *robo << std::endl;
            
            rogers.signForm(*robo);
            
            rogers.executeForm(*robo);
            delete robo;
            
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;
        
        try {
            Form *pardon = intern.makeForm("pardon request", jones.getName());
            std::cout << *pardon << std::endl;
           
            rogers.signForm(*pardon);
           
            president.executeForm(*pardon);
            delete pardon;
            
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }

        std::cout << std::endl;

        try {
            Form *shrub = intern.makeForm("shrubbery request", "home");
            std::cout << *shrub << std::endl;

            rogers.signForm(*shrub);
            
            rogers.executeForm(*shrub);
            delete shrub;
            
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;
        
        try {
            Form *test = intern.makeForm("", "Test");
            std::cout << *test << std::endl;

            rogers.signForm(*test);
            
            rogers.executeForm(*test);
            delete test;
            
        } catch (std::exception &e) {
            std::cout << RED << e.what() << END << std::endl;
        }
        
        std::cout << std::endl;
    }
}
