/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:15:49 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:49:54 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>

#include "Karen.hpp"

Karen::Karen() 
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

void Karen::debug(void) 
{
	std::cout << "Karen's annoyance level is : [DEBUG MODE]" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n" << std::endl;
}

void Karen::info(void) 
{
	std::cout << "Karen's annoyance level is : [INFO MODE]" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Karen::warning(void) 
{
	std::cout << "Karen's annoyance level is : [AT CRITICAL LEVEL]" << std::endl;
	std::cout << "================================================" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month.\n" << std::endl;
}

void Karen::error(void) 
{
	std::cout << "Karen's annoyance level is : [OVER 9000!11!!1!!]" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "\"Screeches in unintelligible Karen language\"\n\n" << std::endl;
}


void Karen::complain(std::string level) 
{	
	int32_t i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	
	//* switch parameter must be an integral
	switch (i) {

		case 0 :
			debug();

		case 1 :
			info();

		case 2 : 
			warning();

		case 3 :
			error();
			break; 	//* break only at last case. 
					//* We want to print all levels above the passed level
			
		default : 
			std::cout << "\nKaren being Karen complaining about Karen things\n" << std::endl;
	}
}
