/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:42:56 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:24:00 by mmondell         ###   ########.fr       */
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
	
	std::cout << "\nMajor differences between Pointers and References\n";
	std::cout << "|===========================================================================|\n";
	std::cout << "|             POINTERS             ||              REFERENCES               |\n";
	std::cout << "|===========================================================================|\n";
	std::cout << "|a) Ptr store a variable address   || References IS the variable            |\n";
	std::cout << "|                                  ||                                       |\n";
	std::cout << "|b) Ptr can be NULL                || References cannot be NULL             |\n";
	std::cout << "|                                  ||                                       |\n";
	std::cout << "|c) Ptr can point to diff addresses|| Ref can only ref a single var ever    |\n";
	std::cout << "|===========================================================================|" << std::endl;

}
