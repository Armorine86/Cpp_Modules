/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:08:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/27 19:49:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

int main(void)
{
    ShrubberyCreationForm shrub("home");
    std::cout << shrub << std::endl;

    Bureaucrat rogers("Rogers", 10, 10);
    std::cout << rogers << std::endl;
    try {
        shrub.beSigned(rogers);
    } catch (std::exception &e) {
         std::cout << RED << e.what() << END << std::endl;
    }
    try {
        rogers.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << RED << e.what() << END << std::endl;
    }
}
