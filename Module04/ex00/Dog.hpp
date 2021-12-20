/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:37:45 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/19 18:36:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& src);
		virtual ~Dog();
		Dog& operator=(const Dog& rhs);

		virtual std::string getType() const;
		virtual void makeSound() const;

};
