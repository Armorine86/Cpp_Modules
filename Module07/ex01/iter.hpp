/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:07:54 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/02 20:45:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
void iter(T *array, int length, void (*fn)(T&))
{
	for (int i = 0; i < length; i++)
		(*fn)(array[i]);
}

template<typename T>
void print(T &index)
{
	std::cout << index;
}
