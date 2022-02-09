/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:23 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/09 13:23:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <climits>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>

typedef std::vector<int>::iterator Iter;

Span::Span(unsigned int N) : vec_size(N)
{
	// Reserve increases the capacity of the vector by the value of the parameter
	vec.reserve(N);
}

Span::Span(Span& src) 
{
	vec = src.vec;
	vec_size = src.vec_size;
}

Span& Span::operator=(Span& rhs) 
{
	if (this != &rhs)
	{
		vec = rhs.vec;
		vec_size = rhs.vec_size;
		return *this;
	}
	return *this;
}

// Adds a number to the vector
// Throws an exception if capacity is reached
void Span::addNumber(const int &num) 
{
	if (vec.size() >= vec_size)
		throw std::exception();
	vec.push_back(num);
}

void Span::random_populate() 
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (size_t i = 0; i < MAX; i++) {
		vec.push_back(rand() % (INT32_MAX / 2));
		if (i == vec_size - 1)
			break;
	}
}

// Finds the difference between each member of the vector and returns
// the shortest span found.
int Span::shortestSpan() 
{
	if (vec_size <= 1)
		throw std::exception();
	
	int shortest = INT32_MAX;
	
	for (Iter first = vec.begin(); first != vec.end(); first++) {
		Iter next = first + 1;
		if (next == vec.end())
			break;
		if (std::abs(*first - *next) < shortest)
			shortest = std::abs(*first - *next);
	}
	return shortest;
}

// Finds the difference between each member of the vector and returns
// the longest span found.
int Span::longestSpan() 
{
	if (vec_size <= 1)
		throw std::exception();
	
	int largest = 0;
	
	for (Iter first = vec.begin(); first != vec.end(); first++) {
		Iter next = first + 1;
		if (next == vec.end())
			break;
		if (std::abs(*first - *next) > largest)
			largest = std::abs(*first) - std::abs(*next);
	}
	return largest;
}

void Span::print_vector() 
{
	for (Iter iter = vec.begin(); iter != vec.end(); iter++) {
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
}
