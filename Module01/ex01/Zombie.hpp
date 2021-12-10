/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:55 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/10 08:16:48 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define N_ZOMBIES 6

class Zombie {

	private:
		std::string name;
	
	public:
		Zombie(); //* Default Constructor
		Zombie(const std::string& new_name); //* Overloaded Constructor
		~Zombie();
		void randName();
		void announce( void );
};

Zombie *zombieHorde( int32_t N, std::string name);
Zombie* newZombie(std::string name);
void randomChump(std::string name);

