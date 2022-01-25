/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:15:49 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 08:38:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>

#include "Karen.hpp"


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
	std::cout << "\"Screeches in unintelligible Karen language\"\n" << std::endl;
}

void Karen::complain(std::string level) 
{	
	//* Functions also have an address in memory. We can make function pointers
	//* to point to different functions in an array.
	
	//* associates each bracket/pointers to the wanted function
	fncPtr[0] = &Karen::debug;
	fncPtr[1] = &Karen::info;
	fncPtr[2] = &Karen::warning;
	fncPtr[3] = &Karen::error;

	std::string complain_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int32_t i = 0; i < 4; i++)
	{
		if (level == complain_levels[i])
			(this->*fncPtr[i])(); //* call associated functions
	}
}
