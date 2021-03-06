/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:16:13 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/25 08:49:50 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdint.h>

#include "Karen.hpp"

int main(int argc, char**argv)
{
	Karen karen;

	if (argc != 2)
	{
		karen.complain("");
		return (0);
	}
	
	std::string level;
	level.assign(argv[1]);
	
	// Capitalize argv[1]
	for (int32_t i = 0; level[i]; i++)
		level[i] = toupper(level[i]);
	karen.complain(level);
}
