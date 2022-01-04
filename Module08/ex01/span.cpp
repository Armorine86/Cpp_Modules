/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:23 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/04 16:05:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>

Span::Span(unsigned int N) : vec_size(N)
{
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

void Span::addNumber(const int &num) 
{
	if (vec.size() >= vec_size)
		throw MaxSizeReached();
	vec.push_back(num);
}

void Span::random_populate() 
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (size_t i = 0; i < MAX; i++)
		vec.push_back(rand());
}

// Builds a new vector and returns the minimum difference result found between each elements
int Span::shortestSpan() 
{
	if (vec_size <= 1)
		throw NoShortSpan();
	
	std::vector<int> temp;
	std::vector<int>::iterator first = vec.begin();
	std::vector<int>::iterator second;
	
	for (; second != vec.end(); first++)
	{
		second = first + 1;
		int diff = abs(*first - *second);
		temp.push_back(diff);
	}
	return (*(std::min_element(temp.begin(), temp.end())));
}

// Builds a new vector and returns the maximum difference result found between each elements
int Span::longestSpan() 
{
	if (vec_size <= 1)
		throw NoLongSpan();
	
	std::vector<int> temp;
	std::vector<int>::iterator first = vec.begin();
	std::vector<int>::iterator second;
	
	for (; second != vec.end(); first++)
	{
		second = first + 1;
		int diff = abs(*first - *second);
		temp.push_back(diff);
	}
	return (*(std::max_element(temp.begin(), temp.end())));
}

const char* Span::MaxSizeReached::what() const throw()
{
	return "Max Size Reached";
}

const char* Span::NoShortSpan::what() const throw()
{
	return "No short span possible";
}

const char* Span::NoLongSpan::what() const throw()
{
	return "No long span possible";
}
