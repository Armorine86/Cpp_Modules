/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 09:43:44 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/01 09:46:09 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() :
	Integer(42),
	c('z'),
	Double(42.42)
{}

Data::Data(Data& src) 
{
	Integer = src.Integer;
	c = src.c;
	Double = src.Double;
}

Data& Data::operator=(Data& rhs) 
{
	if (this != &rhs)
	{
		Integer = rhs.Integer;
		c = rhs.c;
		Double = rhs.Double;
		return *this;
	}
	return *this;
}
