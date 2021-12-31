/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:33:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/30 16:17:05 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Convert.hpp"
#include "colors.hpp"

void p_error(const char* msg)
{
    std::cerr << RED << msg << END << std::endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
    if (argc != 2)
        p_error("\nUSAGE: ./convert [argument]\n");

    std::string input(argv[1]);

    if (input.empty())
        p_error("\nError: Empty Argument\n");

    Convert convert(argv[1]);

    convert.toChar();
    convert.toInt();
    convert.toFloat();
    convert.toDouble();
}
