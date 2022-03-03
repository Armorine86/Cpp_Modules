/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:05:34 by mmondell          #+#    #+#             */
/*   Updated: 2022/03/03 09:03:31 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "colors.hpp"
#include "easyfind.hpp"

template <typename T>
void populate_container(T &cont)
{
	for (int i = 0; i < 25; i++)
		cont.push_back(i + 1);
}

template <typename T>
void print_content(T &cont)
{
	typename T::iterator iter; //An iterator that works on any type of containers
	std::cout << "Array: ";

	// Using iterator, we don't need to keep track of the number of elements in the array
	for(iter = cont.begin(); iter != cont.end(); iter++)
		std::cout << *iter << " ";							  			
	std::cout << "\n" << std::endl;
}

int main(void)
{

	std::vector<int> vec0; // https://en.cppreference.com/w/cpp/container/vector

	populate_container(vec0);
	
	std::cout << GREEN << "\nVECTORS" << END << std::endl;
	print_content(vec0);
	
	try {
		const int target = 10;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(vec0, target)) {
			std::cout << "Value found: " << target << "\n" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Target not found" << END << std::endl;
	}

	try {
		const int target = 0;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(vec0, target)){
			std::cout << "Value found: " << target << "\n" <<  std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Target not found" << END << std::endl;
	}

	std::cout << std::endl;

	std::list<int> list1; // https://en.cppreference.com/w/cpp/container/list

	std::cout << GREEN << "LINKED LIST" << END << std::endl;
	populate_container(list1);

	print_content(list1);

	try {
		const int target = 15;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(list1, target)) {
			std::cout << "Value found: " << target << "\n" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Target not found" << END << std::endl;
	}

	try {
		const int target = 0;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(list1, target)) {
			std::cout << "Value found: " << target << "\n" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Target not found" << END << std::endl;
	}
	
	std::cout << std::endl;



	std::deque<int> deq1; // https://en.cppreference.com/w/cpp/container/deque

	std::cout << GREEN << "DOUBLE-ENDED QUEUE" << END << std::endl;
	populate_container(deq1);
	
	print_content(deq1);
	
	try {
		const int target = 23;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(deq1, target)) {
			std::cout << "Value found: " << target << "\n" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << END << std::endl;
	}

	try {
		const int target = 0;
		std::cout << YELLOW << "Target: " << target << END << std::endl;
		if (easyfind(deq1, target)) {
			std::cout << "Value found: " << target << "\n" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Target not found" << END << std::endl;
	}

	std::cout << std::endl;

}
