/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:05:34 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/04 13:22:12 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "colors.hpp"
#include "easyfind.hpp"

void populate_vector(std::vector<int> &vec)
{
	for (int i = 0; i < 25; i++)
		vec.push_back(i + 1);
}

void print_vector(std::vector<int> &vec)
{
	std::vector<int>::iterator index;

	std::cout << "Array: ";

	// Using iterator, we don't need to keep track of the number of elements in the array
	for(index = vec.begin(); index != vec.end(); index++)
		std::cout << *index << " ";							  			
	std::cout << std::endl;
}

int main(void)
{
	std::vector<int> vec0;
	std::vector<int>::iterator value; // Like a pointer, dereference to access value at its address.

	populate_vector(vec0);
	
	print_vector(vec0);
	
	try {
		value = easyfind(vec0, 10);
		std::cout << "Value found: " << *value << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << END << std::endl;
	}

	try {
		value = easyfind(vec0, 0);
		std::cout << "Value found: " << *value << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Value not found" << END << std::endl;
	}
}
