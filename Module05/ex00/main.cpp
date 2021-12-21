/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:17:48 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 16:52:18 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "colors.hpp"

int main(void)
{
	std::cout << "\n\nConstructor Exception Checks\n";
	std::cout << "=============================" << std::endl;

	try 
	{
		Bureaucrat high("John", 1);
		std::cout << "[OSTREAM OVERLOAD] " << high;			//* ostream test
		std::cout << std::endl;
		Bureaucrat low("Jack", 150);
		std::cout << "[OSTREAM OVERLOAD] " << low ;			//* ostream test
		std::cout << std::endl;
		
		Bureaucrat tooHigh("Clarence", 0); //* Should throw an exception
		
		//* Should Not be Executed
		std::cout << tooHigh;
		std::cout << std::endl;
	} 
	catch (std::exception &exc)
	{
		std::cerr << RED << exc.what() << END << std::endl;
	}

	std::cout << "\n\nRanking Up/Down Exception Checks\n";
	std::cout << "=================================" << std::endl;

	try
	{
		Bureaucrat lawrence("Lawrence", 1);
		std::cout << lawrence;
		
		std::cout << std::endl;
		lawrence.rankDown();
		
		std::cout << lawrence;
		std::cout << std::endl;
	}
	catch (std::exception &exc)
	{
		std::cerr << RED << exc.what() << END << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat cassivy("cassivy", 150);
		std::cout << "[OSTREAM OVERLOAD" << cassivy;
		std::cout << std::endl;
		try
		{
			cassivy.rankDown();
			std::cout << std::endl;
			
			//* should not be executed
			std::cout << "[OSTREAM OVERLOAD" << cassivy;
		}
		catch (std::exception &exc)
		{
			std::cerr << RED << exc.what() << END << std::endl;
		}
	}
	catch (std::exception &exc)
	{
		std::cout << RED << exc.what() << END << std::endl;
	}
	std::cout << std::endl;
}
