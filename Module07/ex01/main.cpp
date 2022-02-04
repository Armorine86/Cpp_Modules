/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:08:44 by mmondell          #+#    #+#             */
/*   Updated: 2022/02/04 14:08:29 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int nums[5] = {0, 1, 2, 3, 4};
	
	std::string hello[5] = {"H", "E", "L", "L", "O"};

	char world[6] = {'W', 'O', 'R', 'L', 'D', '\0'};

	iter(nums, 5, print);
	std::cout << std::endl;

	iter(hello, 5, print);
	std::cout << std::endl;

	iter(world, 6, print);
	std::cout << std::endl;
	
}
