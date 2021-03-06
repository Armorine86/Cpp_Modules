/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:04:55 by mmondell          #+#    #+#             */
/*   Updated: 2022/01/24 13:15:33 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {

	private:
		std::string name;
	
	public:
		Zombie(const std::string& new_name); //* Constructor have the same name as the Class
		~Zombie(); //* Destructor with a ~ in front
		void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

