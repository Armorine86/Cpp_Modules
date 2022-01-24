/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:57:39 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:05:21 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

//* "std" is a namespace. The "::" operator is the "scope" operator. 
//* It tells the compiler which class/namespace to look in for an identifier.
//
//* "cout" is an object of class ostream. It is defined in iostream header file.
//* The data needed to be displayed on the screen,
//* is inserted in the standard output stream (cout) using the insertion operator(<<)
//
//* "endl" is a predefined object of ostream class.
//* It is used to insert a new line characters and flushes the stream (forces output to console).
//
//* "int32_t" is the equivalent to the standard int type.
//* It will tell the compiler to give exactly 32 bits (4 bytes) regardless
//* of the compiler you are using.
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int32_t i = 1; argv[i]; i++)
		{
			for (int32_t j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
