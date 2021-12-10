/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:08:21 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/09 19:55:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//* "new" allocates memory on the heap
Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}
