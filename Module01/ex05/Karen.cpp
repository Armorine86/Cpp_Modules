/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:15:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/11 20:26:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>

#include "Karen.hpp"

void Karen::complain(std::string level) 
{	
	
}

void Karen::debug(void) 
{
	std::cout << "<INFO>" << std::endl;
	std::cout << "I love to get extra bacon for my \
				7XL-double-cheese-triple-pickle-special-ketchup burger.\
				 I just love it!" << std::endl;
}

void Karen::info(void) 
{
	std::cout << "<DEBUG>" << std::endl;

	std::cout << "I cannot believe adding extra \
					bacon cost more money. You don't put enough! \
					If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void) 
{
	std::cout << "<WARNING>" << std::endl;

	std::cout << "I think I deserve to have some extra bacon for free.\
				I've been coming here for years and you just started \
				working here last month." << std::endl;
}

void Karen::error(void) 
{
	std::cout << "<ERROR>" << std::endl;

	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}
