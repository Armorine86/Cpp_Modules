/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/15 21:47:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

	std::string name = "Chappy";
	std::string target = "Snappy";
	
	ClapTrap Chappy(name);
	
	Chappy.attack(target);
	Chappy.takeDamage(5);
	Chappy.beRepaired(3);
	Chappy.beRepaired(3);
}
