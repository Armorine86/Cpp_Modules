/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:01:51 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/04 13:29:02 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &arr, const int &target)
{
	typename T::iterator index;
	
	// Returns an iterator to first occurence of target
	index = std::find(arr.begin(), arr.end(), target);
	if (index == arr.end())
		throw std::exception();
	return index;
}
