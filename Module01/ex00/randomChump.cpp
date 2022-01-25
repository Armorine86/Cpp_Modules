/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:10:28 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:14:15 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// creates another object of type Zombie with name as parameter
void randomChump(std::string name) {

	// this object is on the stack and will be destroyed at the end of the scope
	Zombie zombie(name);

	zombie.announce();
}
