/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:01:51 by mmondell          #+#    #+#             */
/*   Updated: 2022/03/03 08:59:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

template <typename T>
bool easyfind(T &cont, const int &target)
{
	typename T::iterator iter;
	
	// Returns an iterator to first occurence of target
	if(std::find(cont.begin(), cont.end(), target) != cont.end())
		return true;
	throw std::exception();
}
