/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:03:32 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/02 20:05:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename Swap>
void swap(Swap &x, Swap &y)
{
	Swap temp;
	temp = x;
	x = y;
	y = temp;
}

template<typename Min>
Min min(Min x, Min y)
{
	if (x == y)
		return y;
	return (x < y) ? x : y;
}

template<typename Max>
Max max(Max x, Max y)
{
	if (x == y)
		return y;
	return (x > y) ? x : y;
}
