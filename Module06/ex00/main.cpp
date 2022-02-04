/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:33:43 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 09:19:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Convert.hpp"
#include "colors.hpp"

// Why use c++ cast types instead of C-Style cast?
// 
// The main reason is that classic C casts make no distinction between what we call
// static_cast<>(), reinterpret_cast<>(), const_cast<>(), and dynamic_cast<>().
// These four things are completely different.

// https://stackoverflow.com/questions/103512/why-use-static-castintx-instead-of-intx

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
