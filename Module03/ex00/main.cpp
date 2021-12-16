/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 21:06:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/16 15:26:26 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {

	ClapTrap Chappy("Chappy");
	
	Chappy.attack("Marauder");
	Chappy.takeDamage(5);
	Chappy.beRepaired(3);
	Chappy.beRepaired(3);
}
