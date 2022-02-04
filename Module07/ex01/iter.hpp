/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:07:54 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 14:12:04 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>


// usint T for the length here would conflict with array type T
template<typename T>
void iter(T* array, size_t length, void (*fn)(T&))
{
	for (size_t i = 0; i < length; i++)
		(*fn)(array[i]);
}

template<typename T>
void print(T &index)
{
	std::cout << index << std::flush;
}
