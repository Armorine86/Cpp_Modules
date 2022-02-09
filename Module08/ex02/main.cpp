/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:53:46 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/09 16:38:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "colors.hpp"
#include "MutantStack.hpp"

int main(void) {
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	{
		std::cout << GREEN << "======================\n";
		std::cout << "|| STACK.TOP() TEST ||\n";
		std::cout << "======================\n" << END << std::endl;
		
		MutantStack<int> stack;

		stack.push(42);

		std::cout << "Top Element: " << stack.top() << std::endl;
	}
	
	std::cout << std::endl;

	{
		std::cout << GREEN << "=======================\n";
		std::cout << "|| STACK.SIZE() TEST ||\n";
		std::cout << "=======================\n" << END << std::endl;

		MutantStack<int> stack;
		
		for (int i = 0; i < 42; i++) {
			stack.push(rand() % 255);
		}

		std::cout << "Stack size: " << stack.size() << std::endl;
	}

	std::cout << std::endl;
	
	{
		std::cout << GREEN << "======================\n";
		std::cout << "|| STACK.POP() TEST ||\n";
		std::cout << "======================\n" << END << std::endl;

		MutantStack<int> stack;

		for (int i = 0; i < 42; i++) {
			stack.push(rand() % 255);
		}

		std::cout << "Top Element: " << stack.top() << std::endl;

		stack.pop();
		
		std::cout << "Top Element: " << stack.top() << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "========================\n";
		std::cout << "|| STACK.EMTPY() TEST ||\n";
		std::cout << "========================\n" << END << std::endl;

		MutantStack<int> stack;

		if (stack.empty())
			std::cout << "Stack is Empty" << std::endl;

	}
	
	std::cout << std::endl;

	{
		std::cout << GREEN << "==========================\n";
		std::cout << "|| STACK ITERATORS TEST ||\n";
		std::cout << "==========================\n" << END << std::endl;

		MutantStack<int> stack;

		for (int i = 0; i < 42; i++) {
			stack.push(rand() % 255);
		}
		
		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator it_end = stack.end();
		
		std::cout << "Stack begin: " <<  *it << std::endl;
		std::cout << "Stack end: " <<  *it_end << std::endl;
		
		++it;
		--it_end;

		std::cout << "Stack begin: " <<  *it << std::endl;
		std::cout << "Stack end: " <<  *it_end << std::endl;

		++it_end;
		for (it = stack.begin(); it != it_end; it++){
			std::cout << *it << " ";
		}
	}
	return 0;
}
