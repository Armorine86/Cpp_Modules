/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:40:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/20 09:12:42 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	
	public:
		WrongCat();
		WrongCat(const std::string& type);
		WrongCat(const WrongCat& src);
		~WrongCat();

		WrongCat& operator=(const WrongCat& rhs);
		
		//std::string getType() const;
		void makeSound() const; //* without virtual keyword
};
