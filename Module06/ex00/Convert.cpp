/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:38:15 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/31 10:31:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

#include <iomanip>

Convert::Convert() : input(""), c(0), Int(0), Float(0.0f), Double(0.0), type(isInt) {}

Convert::Convert(const std::string& input)
    : input(input), c(0), Int(0), Float(0.0f), Double(0.0), type(isInt)
{
    type = find_type();
    cast_type();
}

Convert::Convert(Convert& src)
{
    input = src.input;
    c = src.c;
    Int = src.Int;
    Float = src.Float;
    Double = src.Double;
    type = src.type;
}

Convert& Convert::operator=(Convert& rhs)
{
    if (this != &rhs) {
        *this = rhs;
        return *this;
    }
    return *this;
}

bool is_pseudo_litteral(std::string& input)
{
    if (input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff" ||
        input == "inf" || input == "inff" || input == "nan" || input == "nanf")
        return true;
    return false;
}

bool Convert::isImpossible()
{
	if (type == error || isnan(Float) || isinf(Float))
		return true;
	return false;
}

void Convert::toChar()
{
    std::cout << "char: ";
    if (type == error)
        std::cout << "impossible";
    else if (c < 32 || c > 126)
        std::cout << "Non Displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void Convert::toInt()
{
    std::cout << "int: ";
    if (isImpossible())
        std::cout << "impossible";
    else
        std::cout << Int;
    std::cout << std::endl;
}

void Convert::toFloat()
{
    std::cout << "float: ";
    if (type == error)
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << Float << "f";
    std::cout << std::endl;
}

void Convert::toDouble()
{
    std::cout << "double: ";
    if (type == error)
	{
        std::cout << "impossible" << std::endl;
		return;
	}
    if (input == "+inf")
        std::cout << "+";
    std::cout << std::fixed << std::setprecision(1) << Double;
    std::cout << std::endl;
}

Convert::ScalarTypes Convert::find_type()
{
	char *endptr;
	
    for (size_t i = 0; input[i]; i++) {
        if (!isdigit(input[i]))
            break;
        if (i == input.length() - 1) {
            Int = atoi(input.c_str());
            return isInt;
        }
    }
    if (input.length() == 1 && std::isalpha(input[0])) {
        c = input[0];
        return isChar;
    } else if (input[input.length() - 1] == 'f' && input.find('.') != std::string::npos) {
        input.erase(input.end() - 1);
        Float = strtof(input.c_str(), &endptr);
		if (*endptr != '\0')
			return error;
        return isFloat;

    } else if (input[input.length() - 1] != 'f' && input.find('.') != std::string::npos) {
        Double = strtod(input.c_str(), &endptr);
		if (*endptr != '\0')
			return error;
        return isDouble;

    } else if (is_pseudo_litteral(input)) {
        if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
            input.erase(input.end() - 1);
        Double = strtod(input.c_str(), NULL);
        return isPseudo;
    } else
        return error;
}

void Convert::cast_type()
{
    switch (type) {
        case isChar: {
            Int = static_cast<int>(c);
            Float = static_cast<float>(c);
            Double = static_cast<double>(c);
            break;
        }
        case isInt: {
            c = static_cast<char>(Int);
            Float = static_cast<float>(Int);
            Double = static_cast<double>(Int);
            break;
        }
        case isFloat: {
            Int = static_cast<int>(Float);
            c = static_cast<char>(Float);
            Double = static_cast<double>(Float);
            break;
        }
        case isDouble: {
            Int = static_cast<int>(Double);
            Float = static_cast<float>(Double);
            c = static_cast<char>(Double);
            break;
        }
        case isPseudo: {
            Int = static_cast<int>(Double);
            Float = static_cast<float>(Double);
            c = static_cast<char>(Double);
            break;
        }
        case error: {
            input = "impossible";
            break;
        }
    }
}
