/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:19:20 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 13:24:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <exception>

// **Signature: dynamic_cast < new_type > ( expression )
//
// **If the cast fails and new_type is a reference type, it throws an exception that matches a handler of type std::bad_cast.
//
// An exception of this type is thrown when a dynamic_cast to a reference type fails the run-time check
// (e.g. because the types are not related by inheritance)
void identify(Base& p)
{
	std::cout << "Reference ";
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Class: A" << std::endl;
		(void)a;
	} catch (const std::bad_cast){
	}
	
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Class: B" << std::endl;
		(void)b;
	} catch (const std::bad_cast){
	}

	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Class: C" << std::endl;
		(void)c;
	} catch (const std::bad_cast) {
	}
}

// dynamic_cast < new_type > ( expression )
//
// **If the cast is successful, dynamic_cast returns a value of type new_type.
// **If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
void identify(Base* p)
{
	std::cout << "Pointer ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Class: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Class: B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Class: C" << std::endl;
}

Base* generate(void)
{
	enum {ClassA, ClassB, ClassC};
	srand((unsigned int)time(NULL));

	switch (rand() % 3) {
		case ClassA: {
			return new A();
		}
		case ClassB: {
			return new B();
		}
		case ClassC: {
			return new C();
		}
	}
	return NULL;
}

int main(void)
{
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
}
