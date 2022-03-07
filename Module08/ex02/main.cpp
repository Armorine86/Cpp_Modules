/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:53:46 by mmondell          #+#    #+#             */
/*   Updated: 2022/03/07 09:07:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "colors.hpp"
#include "MutantStack.hpp"

int main(void) {
	
	srand(static_cast<unsigned int>(time(NULL)));

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
		std::cout << "|| STACK.TOP() TEST ||\n";
		std::cout << "======================\n" << END << std::endl;
		
		MutantStack<int> stack;

		std::cout << "Stack size: " << stack.size() << "\n" << std::endl;
		std::cout << "Push_back: 42" << std::endl;
		
		stack.push(42);
		std::cout << "Stack size: " << stack.size() << "\n" << std::endl;

		std::cout << "Top Element: " << stack.top() << std::endl;

		std::cout << "\nPush_back: 199" << std::endl;
		stack.push(199);
		std::cout << "Stack size: " << stack.size() << "\n" << std::endl;

		std::cout << "Top Element: " << stack.top() << std::endl;
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

		std::cout << "Stack Size: " << stack.size() << std::endl;
		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator it_end = stack.end();
		
		for (it = stack.begin(); it != it_end; it++){
			std::cout << *it << " ";
		}
		
		std::cout << "\nTop Element: " << stack.top() << "\n" << std::endl;

		std::cout << "stack.pop()\n" << std::endl;
		stack.pop();

		std::cout << "New Stack Size: " << stack.size() << std::endl;
		it_end = stack.end();

		for (it = stack.begin(); it != it_end; it++){
			std::cout << *it << " ";
		}
		
		std::cout << "\nTop Element: " << stack.top() << std::endl;
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

		std::cout << std::endl;

		std::cout << "Stack begin: " <<  *it << std::endl;
		std::cout << "Stack end: " <<  *it_end << std::endl;

		++it_end;
		for (it = stack.begin(); it != it_end; it++){
			std::cout << *it << " ";
		}
		std::cout << std::endl;

	}

	std::cout << std::endl;

	{
		std::cout << GREEN << "==========================\n";
		std::cout << "|| STD::STACK INIT TEST ||\n";
		std::cout << "==========================\n" << END << std::endl;
		
		MutantStack<int> stack;
		
		for (int i = 0; i < 42; i++) {
			stack.push(rand() % 255);
		}
		
		std::stack<int> s(stack);

		std::cout << "Std::stack size: " <<  s.size() << std::endl;
	}

	return 0;
}
