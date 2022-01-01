/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:19:20 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/01 13:28:24 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

void identify(Base& p)
{
	std::cout << "Reference ";
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "type: A" << std::endl;
		(void)a;
	} catch (std::exception &e){
	}
	
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "type: B" << std::endl;
		(void)b;
	} catch (std::exception &e){
	}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "type: C" << std::endl;
		(void)c;
	} catch (std::exception &e) {
	}
}

void identify(Base* p)
{
	std::cout << "Pointer ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "type: C" << std::endl;
}

Base * generate(void)
{
	enum {ClassA, ClassB, ClassC};
	srand((unsigned int)time(NULL));

	long index = rand() % 3;

	switch (index) {
		case ClassA: {
			A *a = new A();
			return a;
		}
		case ClassB: {
			B *b = new B();
			return b;
		}
		case ClassC: {
			C *c = new C();
			return c;
		}
	}
	return NULL;
}

int main(void)
{
	Base *ptr = generate();
	std::cout << "Base ptr address: " << ptr << std::endl;

	identify(ptr);
	identify(*ptr);
}
