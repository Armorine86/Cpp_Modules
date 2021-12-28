/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:08:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/28 09:52:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

int main(void)
{
    Bureaucrat Jones("Jones", 145, 145);
    std::cout << Jones << std::endl;
    std::cout << std::endl;
    
    Bureaucrat rogers("Rogers", 10, 145);
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
    
    PresidentialPardonForm pardon(Jones.getName());
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
