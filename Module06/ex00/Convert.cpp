/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:38:15 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 09:30:55 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

#include <iomanip>

Convert::Convert() : input(""), c(0), _Int(0), _Float(0.0f), _Double(0.0), type(isInt) {}

Convert::Convert(const std::string& input)
    : input(input), c(0), _Int(0), _Float(0.0f), _Double(0.0), type(isInt)
{
    type = find_type();
    cast_type();
}

Convert::Convert(Convert& src)
{
    input = src.input;
    c = src.c;
    _Int = src._Int;
    _Float = src._Float;
    _Double = src._Double;
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
	if (type == error || isnan(_Float) || isinf(_Float))
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
        std::cout << _Int;
    std::cout << std::endl;
}

void Convert::toFloat()
{
    std::cout << "float: ";
    if (type == error)
        std::cout << "impossible";
    else
        std::cout << std::fixed << std::setprecision(1) << _Float << "f";
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
    std::cout << std::fixed << std::setprecision(1) << _Double;
    std::cout << std::endl;
}

Convert::ScalarTypes Convert::find_type()
{
	char *endptr;
	
    for (size_t i = 0; input[i]; i++) {
        if (!isdigit(input[i]))
            break;
        if (i == input.length() - 1) {
            _Int = atoi(input.c_str());
            return isInt;
        }
    }
    if (input.length() == 1 && std::isprint(input[0])) {
        c = input[0];
        return isChar;
    } else if (input[input.length() - 1] == 'f' && input.find('.') != std::string::npos) {
        input.erase(input.end() - 1);
        _Float = strtof(input.c_str(), &endptr);
		if (*endptr != '\0')
			return error;
        return isFloat;

    } else if (input[input.length() - 1] != 'f' && input.find('.') != std::string::npos) {
        _Double = strtod(input.c_str(), &endptr);
		if (*endptr != '\0')
			return error;
        return isDouble;

    } else if (is_pseudo_litteral(input)) {
        if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
            input.erase(input.end() - 1);
        _Double = strtod(input.c_str(), NULL);
        return isPseudo;
    } else
        return error;
}

void Convert::cast_type()
{
    switch (type) {
        case isChar: {
            _Int = static_cast<int>(c);
            _Float = static_cast<float>(c);
            _Double = static_cast<double>(c);
            break;
        }
        case isInt: {
            c = static_cast<char>(_Int);
            _Float = static_cast<float>(_Int);
            _Double = static_cast<double>(_Int);
            break;
        }
        case isFloat: {
            _Int = static_cast<int>(_Float);
            c = static_cast<char>(_Float);
            _Double = static_cast<double>(_Float);
            break;
        }
        case isDouble: {
            _Int = static_cast<int>(_Double);
            _Float = static_cast<float>(_Double);
            c = static_cast<char>(_Double);
            break;
        }
        case isPseudo: {
            _Int = static_cast<int>(_Double);
            _Float = static_cast<float>(_Double);
            c = static_cast<char>(_Double);
            break;
        }
        case error: {
            input = "impossible";
            break;
        }
    }
}
