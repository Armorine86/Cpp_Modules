/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:28:36 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/31 15:38:07 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <exception>
#include <iostream>
#include <string>

#define TYPE_NONE 4

class Convert
{
public:
    Convert();
    Convert(const std::string& input);
    Convert(Convert& src);
    ~Convert() {}
    Convert& operator=(Convert& rhs);

    typedef enum ScalarTypes { isChar, isInt, isFloat, isDouble, isPseudo, error } ScalarTypes;

    void toChar();
    void toInt();
    void toFloat();
    void toDouble();

    ScalarTypes find_type();
    void cast_type();

private:
    std::string input;
    char c;
    int Int;
    float Float;
    double Double;
    ScalarTypes type;
};
