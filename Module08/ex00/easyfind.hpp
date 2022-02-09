/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:01:51 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/09 09:42:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &arr, const int &target)
{
	typename T::iterator iter;
	
	// Returns an iterator to first occurence of target
	iter = std::find(arr.begin(), arr.end(), target);
	if (iter == arr.end())
		throw std::exception();
	return iter;
}
