/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:42:56 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/26 08:23:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {

	std::string str = "HI THIS IS BRAIN";

	
	std::string* stringPTR = &str;	//* pointing to the address of str
	std::string& stringREF = str;   //* referencing str variable

	
	
	std::cout << "\nAddress of stringPTR:                  " << &stringPTR << std::endl;
	std::cout << "Address of str:                        " << &str << std::endl;
	std::cout << "Address stored in stringPTR:           " << stringPTR << std::endl;
	std::cout << "Address of stringREF:                  " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "stringPTR Value at address:            " << *stringPTR << std::endl;
	std::cout << "value of str referenced by stringREF:  " << stringREF << std::endl;
	
	// |===========================================================================|
	// |             POINTERS             ||              REFERENCES               |
	// |===========================================================================|
	// |a) Ptr store a variable address   || References IS the variable            |
	// |                                  ||                                       |
	// |b) Ptr can be NULL                || References cannot be NULL             |
	// |                                  ||                                       |
	// |c) Ptr can point to diff addresses|| Ref can only ref a single var ever    |
	// |===========================================================================|
}
