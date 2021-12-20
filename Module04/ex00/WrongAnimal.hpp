/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:43:53 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:10:01 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal {
	
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& rhs);
		
		std::string getType() const;
		void makeSound() const; //* without virtual keyword
};
