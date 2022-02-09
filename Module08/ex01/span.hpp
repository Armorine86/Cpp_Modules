/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:36:01 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/09 13:23:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#define MAX 25000

class Span {

public:
	Span() : vec(0), vec_size(0) {}
	Span(unsigned int N);
	Span(Span& src);
	~Span() {}
	Span& operator=(Span& rhs);

	void addNumber(const int &num);
	void random_populate();
	int shortestSpan();
	int longestSpan();

	void print_vector();
	
private:
	std::vector<int> vec;
	size_t vec_size;
};
