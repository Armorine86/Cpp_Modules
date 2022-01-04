/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:36:01 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/04 16:02:34 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#define MAX 125000

class Span {

private:
	std::vector<int> vec;
	unsigned int vec_size;

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
	
	class MaxSizeReached : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	
	class NoShortSpan : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NoLongSpan : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};
