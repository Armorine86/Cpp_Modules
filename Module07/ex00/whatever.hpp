/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:03:32 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 13:49:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void swap(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

template <typename T>
T min(T &x, T &y)
{
    if (x == y)
        return y;
    return (x < y) ? x : y;
}

template <typename T>
T max(T &x, T &y)
{
    if (x == y)
        return y;
    return (x > y) ? x : y;
}
